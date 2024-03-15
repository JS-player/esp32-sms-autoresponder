#include <SoftwareSerial.h>

// Create software serial object to communicate with SIM900
SoftwareSerial mySerial(19, 18); // D19 and D18 of ESP32 conneced to SIM900A Rx & Tx respectively

String senderNumber = ""; // Store the sender's phone number

void setup() {
  // Begin serial communication with IDE (Serial Monitor)
  Serial.begin(9600));

  // Begin serial communication with Arduino and SIM900
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  mySerial.println("AT"); // Handshaking with SIM900
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();

  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop() {
  if (mySerial.available()) {
    String message = mySerial.readString();
    Serial.println(message); // Print the received message to the Serial Monitor

    // Check if the message contains the indicator for a new SMS (+CMTI)
    if (message.indexOf("+CMTI") != -1) {
      // Extract the sender's phone number
      int commaIndex = message.indexOf(',');
      senderNumber = message.substring(commaIndex + 1); // Store the number

      // Send the reply SMS
      sendSMS("SIM900A module got your message Sir.");
    }
  }
}

void sendSMS(String message) {
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"" + senderNumber + "\""); // Use the extracted sender's number
  updateSerial();
  mySerial.print(message); // Text content
  updateSerial();
  mySerial.write(26); 
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read());
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}

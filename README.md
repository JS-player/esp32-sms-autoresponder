# Esp32-sms-autorespond
Receive and repply to SMS messages with ESP32 using SIM900A GSM/GPRS module

## Description
This ESP32 project utilizes the SIM900A GSM/GPRS module to receive SMS messages, print them to the Serial Monitor, and automatically reply to the sender with a predefined message.

## Features
SMS Receiving: Reads incoming SMS messages and prints them for monitoring.
Automatic Replies: Extracts the sender's number and sends a configurable response.

## Hardware Requirements
ESP32 development board
SIM900A GSM/GPRS module
Jumper wires
Breadboard (optional)
Power supply suitable for the SIM900A module

## Software Requirements
Arduino IDE
SoftwareSerial library (included in the Arduino IDE)
Wiring
Connect the SIM900A Tx pin to ESP32 pin 19.
Connect the SIM900A Rx pin to ESP32 pin 18.
Connect SIM900A power pins (refer to module datasheet for voltage requirements).

## Instructions
Install the Arduino IDE.
Copy and paste the provided code into the Arduino IDE.
Customize the predefined reply message in the sendSMS function, if desired.
Upload the code to your ESP32 board.
Open the Serial Monitor to observe incoming SMS messages and sent replies.

## Important Notes
Ensure you use a compatible SIM card with your SIM900A module.
The SIM900A can require a significant amount of power. Use a suitable power supply.

## Example Usage
Once the code is running, any SMS sent to the SIM card in the SIM900A will trigger an automatic response with your predefined message.

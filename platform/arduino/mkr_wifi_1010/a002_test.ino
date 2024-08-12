#ifdef a009
// test send spi value via wifi connection
#include <WiFiNINA.h>

#include "PmodAD1.hpp"
#include "arduino_secrets.h"

#define csPinNumber 7

#define serialBaudRate 9600
#define cyclePerSecond 20000

#define cyclePeriod (1000000 / cyclePerSecond)

#define sampleCount 20000

char* ssid = SECRET_SSID;
char* pass = SECRET_PASS;

int status = WL_IDLE_STATUS;

IPAddress serverIPAddress = IPAddress(172, 30, 1, 52);
int serverPortNumber = 9876;

WiFiClient client;

PmodAD1 ad1 = PmodAD1(csPinNumber);

int count;

void connect() {
  while (true) {
    Serial.println("Starting connection to server...");
    if (client.connect(serverIPAddress, serverPortNumber)) {
      break;
    }
  }
  Serial.println("connected to server");
}

void senseAD1() {
  client.write(ad1.read(), 3);
}

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  count = 0;

  while (true) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);

    if (status != WL_CONNECTED) {
      break;
    }

    delay(10000);
  }
  Serial.println("Connected to wifi");
}

typedef void (*function)();

const function clientAction[5] = {
  connect,
  0,
  0,
  0,
  senseAD1,
};

void loop() {
  clientAction[client.status()]();
}
#endif



#ifdef a008
// test wifi data send
/*

  Web client

 This sketch connects to a website (http://www.google.com)

 using the WiFi module.

 This example is written for a network using WPA encryption. For

 WEP or WPA, change the Wifi.begin() call accordingly.

 This example is written for a network using WPA encryption. For

 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:

 * Board with NINA module (Arduino MKR WiFi 1010, MKR VIDOR 4000 and UNO WiFi Rev.2)

 created 13 July 2010

 by dlf (Metodo2 srl)

 modified 31 May 2012

 by Tom Igoe

 */

#include <SPI.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(172,30,1,52);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)
int portNumber = 9876;

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):

WiFiClient client;

void setup() {

  //Initialize serial and wait for port to open:

  Serial.begin(9600);

  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }

  // check for the WiFi module:

  if (WiFi.status() == WL_NO_MODULE) {

    Serial.println("Communication with WiFi module failed!");

    // don't continue

    while (true);

  }

  String fv = WiFi.firmwareVersion();

  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {

    Serial.println("Please upgrade the firmware");

  }

  // attempt to connect to Wifi network:

  while (status != WL_CONNECTED) {

    Serial.print("Attempting to connect to SSID: ");

    Serial.println(ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:

    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:

    delay(10000);

  }

  Serial.println("Connected to wifi");

  printWifiStatus();

  Serial.println("\nStarting connection to server...");

  // if you get a connection, report back via serial:

  if (client.connect(server, portNumber)) {

    Serial.println("connected to server");

    // Make a HTTP request:

    client.println("GET /search?q=arduino HTTP/1.1");

    client.println("Host: www.google.com");

    client.println("Connection: close");

    client.println();

  }
}

void loop() {

  // if there are incoming bytes available

  // from the server, read them and print them:

  while (client.available()) {
    client.print("hi");
//
//    char c = client.read();
//
    Serial.write("hi");
    delay(1);

  }

  // if the server's disconnected, stop the client:

  if (!client.connected()) {

    Serial.println();

    Serial.println("disconnecting from server.");

    client.stop();

    // do nothing forevermore:

    while (true);

  }
}

void printWifiStatus() {

  // print the SSID of the network you're attached to:

  Serial.print("SSID: ");

  Serial.println(WiFi.SSID());

  // print your board's IP address:

  IPAddress ip = WiFi.localIP();

  Serial.print("IP Address: ");

  Serial.println(ip);

  // print the received signal strength:

  long rssi = WiFi.RSSI();

  Serial.print("signal strength (RSSI):");

  Serial.print(rssi);

  Serial.println(" dBm");
}
#endif



#ifdef a007
// test wifi connection
#include <WiFiNINA.h>
#include "arduino_secrets.h"

char* ssid = wifiSSID;
char* pass = wifiPassword;
int status = WL_IDLE_STATUS;

void printData() {
  Serial.println("Board Information:");
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println();
  Serial.println("Network Information:");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial);

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");

  Serial.println("----------------------------------------");
  printData();
  Serial.println("----------------------------------------");
}

void loop() {
  // check the network connection once every 10 seconds:
 delay(10000);
 printData();
 Serial.println("----------------------------------------");
}
#endif



#ifdef a006
// test performance
#include "PmodAD1.hpp"

#define csPinNumber 7

#define serialBaudRate 2000000
#define cyclePerSecond 20000

#define cyclePeriod (1000000 / cyclePerSecond)

#define sampleCount 20000

PmodAD1 ad1 = PmodAD1(csPinNumber);

unsigned long startTime;

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  startTime = micros();
}

int count = 0;

void loop() {
  if (count >= sampleCount) {
    if (count == sampleCount) {
      Serial.print(micros() - startTime);
      Serial.print('\n');
      ++count;
    }
    return;
  }
  Serial.write(ad1.read(), 3);
  ++count;
}
#endif



#ifdef a005
// test print serial readable value without delay
#include "PmodAD1.hpp"

#define csPinNumber 7

#define serialBaudRate 2000000
#define cyclePerSecond 20000

#define cyclePeriod (1000000 / cyclePerSecond)

PmodAD1 ad1 = PmodAD1(csPinNumber);

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();
}

void loop() {
  byte buffer[2];
  byte* wordBuffer = ad1.read();
  buffer[0] = wordBuffer[1];
  buffer[1] = wordBuffer[0];
  Serial.print(*(unsigned short*)buffer);
  Serial.print('\n');
}
#endif



#ifdef a004
// test print serial readable value
#include "PmodAD1.hpp"

#define csPinNumber 7

#define serialBaudRate 2000000
#define cyclePerSecond 20000

#define cyclePeriod (1000000 / cyclePerSecond)

PmodAD1 ad1 = PmodAD1(csPinNumber);
unsigned long deadline;

unsigned long moveDeadline() {
  unsigned long sleeptime = deadline - micros();
  deadline += cyclePeriod;
  return max(sleeptime, 0);
}

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  deadline = micros() + cyclePeriod;
}

void loop() {
  Serial.print(ad1.read());
  Serial.print('\n');
  delayMicroseconds(moveDeadline());
}
#endif



#ifdef a003
// test pin onoff
const int pinNumber = 7;

void setup() {
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
}

void loop() {
  digitalWrite(pinNumber, HIGH);
  delayMicroseconds(1);
  digitalWrite(pinNumber, LOW);
  delayMicroseconds(1);
}
#endif

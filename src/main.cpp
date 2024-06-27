/**
Version: 0a
Tecnocoli - 07/2023
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
espwroom32 - EMS
**/
#include <Arduino.h>
#include "BluetoothSerial.h"
// #include "esp_bt_device.h"

#include "defines.h"
#include "io_defines.h"
#include "tools.h"
#include "communication.h"
#include "control.h"


#define RXp2 16
#define TXp2 17

// void BTConfirmRequestCallback(uint32_t numVal);
// void BTAuthCompleteCallback(boolean success);

// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
// #endif

// #if !defined(CONFIG_BT_SPP_ENABLED)
// #error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
// #endif

BluetoothSerial BTSERIAL;
boolean confirmRequestPending = true;

void serialEvent();
void serialEvent1();
void serialEvent2();
void serialEventRun(void);
// void printDeviceAddress();



void serialEventRun(void)
{
  // #if defined(HAVE_HWSERIAL2)
  if (serialEvent2 && Serial2.available())
  {
    serialEvent2();
  }
  // #endif
  // #if defined(USBCON)
  if (serialEvent && Serial.available())
  {
    serialEvent();
  }
  
  if (serialEvent1 && BT_SERIAL.available())
  {
    serialEvent1();
  }
}


bool bt_enabled = false;
bool bt_connected = false;
bool bt_alive = false;
bool intLed = true;

int tim_alive = 0;
int tim_conn = 0;
int tim_sleep = 0;

String btAddress;

String line = "";
String line1 = "";
String line2 = "";
bool stringComplete = false;
bool string1Complete = false;
bool string2Complete = false;

unsigned long loopDelay_on = millis();
unsigned long loopDelay_int_temp = millis();
unsigned long loopDelay_bit_alive = millis();
unsigned long loopDelay_bit_conn = millis();

void setup()
{
  Serial.begin(115200);
  Serial2.begin(19200, SERIAL_8N1, RXp2, TXp2);
  delay(3000);
  // btAddress = SerialBT.
  Serial.println("EMS");
  BT_SERIAL.begin("EMS-01"); 
  BT_SERIAL.begin(19200);
  // Bluetooth device name
  delay(10000);
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("Not connected!!");
  // printDeviceAddress();
  sendMsg1(btAddress);
  Serial2.println("re,0,0,1,#");
  
}

void loop()
{
  // delay(1000);

  if (BT_SERIAL.available())
  {
    serialEvent1();
  }

  

  if (millis() - loopDelay_bit_conn > 5000)
  {
    loopDelay_bit_conn = millis();
    if (BT_SERIAL.connected())
    {
      bt_connected = true;
      Serial.println("Connected!");
      Serial2.println("0,0,0,1,#");
      BT_SERIAL.print("0,0,0,1,#");
      tim_sleep = 0;
    }else{
      Serial.println("Disconnected!");
    }
    
    sendMsg2("1,0,0,1,#");
    // Serial.println(tim_conn);
  }

  if ((tim_conn >= 700) && (bt_connected))
  {
    // Serial.println("TIM COMM");
    bt_connected = false;
    BT_SERIAL.disconnect();
    on_bit_connected();
  }

  if (millis() - loopDelay_bit_alive > 20)
  {
    loopDelay_bit_alive = millis();
    tim_alive++;
    tim_conn++;
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    // delay(30);
    char inChar = (char)Serial.read();
    line += inChar;
    if (inChar == '#')
    {
      stringComplete = true;
      // Serial.print(line);
    }
  }
}

void serialEvent1()
{
  // Serial.print("serial 1: ");
  while (BT_SERIAL.available())
  {
    // delay(50);
    char inChar = (char)BT_SERIAL.read();
    line1 += inChar;
    if ((inChar == '#'))
    {
      string1Complete = true;
    }
  }
  on_BT_comm(line1);
  Serial.print("serial BT: ");
  Serial.println(line1);
  Serial2.println(line1);
  string1Complete = false;
  line1 = "";
}

void serialEvent2()
{
  while (Serial2.available() && !string2Complete)
  {
    // delay(50);
    char inChar = (char)Serial2.read();
    line2 += inChar;
    if ((inChar == '#'))
    {
      string2Complete = true;
    }
  }
  Serial.print("serial 2: ");
  Serial.println(line2);
  sendBT(line2);
  string2Complete = false;
  line2 = "";
}


// void printDeviceAddress() {

//   const uint8_t* point = esp_bt_dev_get_address();
//   for (int i = 0; i < 6; i++) {
//     char str[3];
//     sprintf(str, "%02X", (int)point[i]);
//     // Serial.print(str);
//     btAddress = btAddress + (str);
//     if (i < 5){
//       // Serial.print(":");
//       btAddress = btAddress + ":";  
//     }

//   }
//   // Serial.println("--");
// }

/**
Version: 0a
Tecnocoli - 06/2023
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F401 - Mio Stimulation
**/

#include <Arduino.h>
#include "BluetoothSerial.h"

#include "defines.h"
#include "io_defines.h"
#include "tools.h"
#include "control.h"

void bt_init();
void on_serial();
void on_BT_comm(String line_in);
void sendMsg1(String s);
void sendMsg2(String s);
void sendBT(String s);

extern bool bt_enabled;
extern bool bt_connected;
extern bool bt_alive;

extern String btAddress;

extern String line;
extern String line1;
extern String line2;
extern bool stringComplete;
extern bool string1Complete;
extern bool string2Complete;

extern String retMsg2[2];
extern String retMsg3[3];
extern String retMsg4[4];
extern String retMsg5[5]; 

extern BluetoothSerial BT_SERIAL;

void bt_init(){
    // Serial.println("bt_init");
}

void on_serial(){ 
    // Serial.print(line);
    stringComplete = false;
    line1 = "";
}

void on_BT_comm(String line_in){
    if (line_in == "OK"){
        bt_enabled = true;
    }else{
        // Serial.println(line2);
        split_msg_4(line_in);
        // Serial.println("split: "+ retMsg4[0] + " - " +retMsg4[1] + " - " + retMsg4[2] + " - " + retMsg4[3]);
        decoder_four();
        string1Complete = false;
        
        retMsg4[0] = "";
        retMsg4[1] = "";
        retMsg4[2] = "";
        retMsg4[3] = "";
    }
}    

void sendMsg1(String s){
    Serial.println(s);
}  
    
void sendMsg2(String s){
    Serial2.println(s+",#");
}   

void sendBT(String s){
    string2Complete = false;
    line2 = "";
    // Serial.print("S: ");
    // Serial.println(s);
    BT_SERIAL.print(s);
}   

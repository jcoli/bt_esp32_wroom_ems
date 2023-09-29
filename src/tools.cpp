/**
Version: 0a
Tecnocoli - 06/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
ESP32WROOM - Clothes Dryer
**/
#include <Arduino.h>

#include "defines.h"
#include "io_defines.h"

// void split_msg_2(String msg);
// void split_msg_3(String msg);
void split_msg_4(String msg);
// void split_msg_5(String msg);

// String retMsg2[2] = {"", ""};
// String retMsg3[3] = {"", "", ""};
String retMsg4[4] = {"", "", "", ""};
// String retMsg5[5] = {"", "", "", "", ""};

// void split_msg_2(String msg){
//     retMsg2[0] = "";
//     retMsg2[1] = "";
//     int j = 0;
//     int p = 0;
//     for(int i =0; i < msg.length(); i++){
//        if(msg.charAt(i) == ','){
//            retMsg2[p] = msg.substring(j, i);
//            j = i +1;
//            p++; 
//        }
//     }  
// }

// void split_msg_3(String msg){
//     // Serial.println(msg);
//     retMsg3[0] = "";
//     retMsg3[1] = "";
//     retMsg3[2] = "";
//     int j = 0;
//     int p = 0;
//     for(int i =0; i < msg.length(); i++){
//        if(msg.charAt(i) == ','){
//            retMsg3[p] = msg.substring(j, i);
//            j = i +1;
//            p++;
//        }
//     }  
// }

void split_msg_4(String msg){
    retMsg4[0] = "";
    retMsg4[1] = "";
    retMsg4[2] = "";
    retMsg4[3] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           String st = msg.substring(j, i);
           st.trim();
           retMsg4[p] = st;
           j = i +1;
           p++;
       }
    }  
}

// void split_msg_5(String msg){
//     retMsg5[0] = "";
//     retMsg5[1] = "";
//     retMsg5[2] = "";
//     retMsg5[3] = "";
//     retMsg5[4] = "";
//     int j = 0;
//     int p = 0;
//     for(int i =0; i < msg.length(); i++){
//        if(msg.charAt(i) == ','){
//            retMsg5[p] = msg.substring(j, i);
//            j = i +1;
//            p++;
//        }
//     }  
// }
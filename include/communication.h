/**
Version: 0a
Tecnocoli - 06/2023
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
ESP32WROOM - Mio Stimulation
**/

#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

void bt_init();
void on_serial();
void on_BT_comm(String line_in);

#endif
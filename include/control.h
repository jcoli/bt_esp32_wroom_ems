/**
Version: 0a
Tecnocoli - 06/2023
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
ESP32WROOM - Mio Stimulation
**/

#ifndef __CONTROL_H__
#define __CONTROL_H__

void on_receive(int mSize);
void on_bit_alive();
void on_bit_connected();
void decoder_one();
void decoder_two();
void decoder_three();
void decoder_four();
void decoder_five();


#endif
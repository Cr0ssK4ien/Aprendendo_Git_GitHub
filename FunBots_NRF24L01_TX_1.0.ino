/*
      Programa para controle de um Servo via RF com módulo NRF24L01 - TRANSMISSOR
      
      Componentes:
        - Arduino Uno;
        - Módulo NRF24L01 com adaptador;
        - Potenciômetro (qualquer um);

      Versão 1.0 - Versão inicial com controle de posição do servo via rádio - 3/Abr/2021; programa base fonte: by Dejan Nedelkovski, www.HowToMechatronics.com
                  
 *    * Criado por Cleber Borges - FunBots - @cleber.funbots  *     *

      Instagram: https://www.instagram.com/cleber.funbots/
      Facebook: https://www.facebook.com/cleber.funbots
      YouTube: https://www.youtube.com/c/funbots
      Telegram: https://t.me/cleberfunbots

*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define pinPot A0
int potPos = 0;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  potPos = analogRead(pinPot);
  radio.write(&potPos, sizeof(potPos));
  delay(100);
}

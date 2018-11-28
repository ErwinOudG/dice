/* Gadgets that Go
   Matrix LED Rain (WeMos Matrix Shield Example)
   Created 2017-9-2 / Aaron Schnetzer
*/

#include <WEMOS_Matrix_LED.h>
long interval = 650; //update interval
long previous = 0;
int randx;
int randy;
int randi;
int dobbel;
bool gedrukt = false;

MLED led(2); //update from 0-8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115000);
  pinMode(D4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D4), stopdice, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (!gedrukt) {
    randx = random(7);
    randy = random(7);
    randi =  random(8);
    led.dot(randx, randy);
    //  MLED mled(randi); //set intensity=5
    led.display();
    delay(10);
    led.dot(randx, randy, 0); //clear dot
  } else if (dobbel == 1) {
    stip(3, 3);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(3, 3);
  } else if (dobbel == 2) {
    stip(0, 0);
    stip(6, 6);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(0, 0);
    stipuit(6, 6);
  } else if (dobbel == 3) {
    stip(0, 0);
    stip(6, 6);
    stip(3, 3);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(0, 0);
    stipuit(6, 6);
    stipuit(3, 3);
  } else if (dobbel == 4) {
    stip(0, 0);
    stip(6, 6);
    stip(6, 0);
    stip(0, 6);
//    stip(3, 3);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(0, 0);
    stipuit(6, 6);
    stipuit(6, 0);
    stipuit(0, 6);
//    stipuit(3, 3);
  } else if (dobbel == 5) {
    stip(0, 0);
    stip(6, 6);
    stip(6, 0);
    stip(0, 6);
    stip(3, 3);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(0, 0);
    stipuit(6, 6);
    stipuit(6, 0);
    stipuit(0, 6);
    stipuit(3, 3);
  } else if (dobbel == 6) {
    stip(0, 0);
    stip(6, 6);
    stip(6, 0);
    stip(0, 6);
    stip(3, 0);
    stip(3, 6);
    led.display();
    delay(1000);
    gedrukt = false;
    stipuit(0, 0);
    stipuit(6, 6);
    stipuit(6, 0);
    stipuit(0, 6);
    stipuit(3, 0);
    stipuit(3, 6);
  } else {
    led.dot(dobbel, dobbel);
    led.display();
    delay(1000);
    gedrukt = false;
    led.dot(dobbel, dobbel, 0);

  }
}

void stopdice() {
  if (!gedrukt) {
    dobbel = random(6) + 1;
    gedrukt = true;
    Serial.print(dobbel);
  }
}

void stip(int plekx, int pleky){
    led.dot(plekx, pleky);
    led.dot(plekx, pleky + 1);
    led.dot(plekx +1, pleky);
    led.dot(plekx + 1, pleky + 1);
}

void stipuit(int plekx, int pleky){
    led.dot(plekx, pleky, 0);
    led.dot(plekx, pleky + 1, 0);
    led.dot(plekx +1, pleky, 0);
    led.dot(plekx + 1, pleky + 1, 0);
}



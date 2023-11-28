#include <Ps3Controller.h>
#include"motor.h"
#include"fk.h"


void notify() {  //---------------- Analog stick value events ---------------
  if (abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2) {
    Serial.print("Moved the left stick:");
    Serial.print(" x=");
    Serial.print(Ps3.data.analog.stick.lx, DEC);
    Serial.print(" y=");
    Serial.print(Ps3.data.analog.stick.ly, DEC);
    Serial.println();
  }

  if (abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2) {
    Serial.print("Moved the right stick:");
    Serial.print(" x=");
    Serial.print(Ps3.data.analog.stick.rx, DEC);
    Serial.print(" y=");
    Serial.print(Ps3.data.analog.stick.ry, DEC);
    Serial.println();
  }
}

void onConnect() {
  Serial.println("Connected. it is");
}

void setup() {
  motor_setup();
  reset_motor();
  Serial.begin(115200);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("04:12:20:02:21:40");
  Serial.println("Ready.");
}

void loop() {
  if (!Ps3.isConnected())
    return;
    fk();
  delay(5);
}
#include <ESP32Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
void motor_setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo1.setPeriodHertz(50);  // standard 50 hz servo
  myservo1.attach(13, 544, 2400);
  myservo2.setPeriodHertz(50);  // standard 50 hz servo
  myservo2.attach(12, 544, 2400);
  myservo3.setPeriodHertz(50);  // standard 50 hz servo
  myservo3.attach(14, 544, 2400);
  myservo4.setPeriodHertz(50);  // standard 50 hz servo
  myservo4.attach(26, 544, 2400);
  myservo5.setPeriodHertz(50);  // standard 50 hz servo
  myservo5.attach(33, 544, 2400);
  myservo6.setPeriodHertz(50);  // standard 50 hz servo
  myservo6.attach(32, 544, 2400);
}

void reset_motor()
{
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(110);
  myservo6.write(90);
}

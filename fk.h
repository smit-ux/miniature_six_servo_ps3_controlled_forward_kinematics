
void fk() {
  int left_x = Ps3.data.analog.stick.lx;
  int left_y = -1 * Ps3.data.analog.stick.ly;
  int right_x = Ps3.data.analog.stick.rx;
  int right_y = -1 * Ps3.data.analog.stick.ry;
  float right_radi = sqrt((right_x * right_x) + (right_y * right_y));  // radius of joystick
  float left_radi = sqrt((left_x * left_x) + (left_y * left_y));
  //////////////////////////////////////////////////////////////////
  float right_alpha = atan2(right_y, right_x);
  float left_alpha = atan2(left_y, left_x);
  //////////////////////////////////////////////////
  float right_weight = 0.00008;
  float left_weight = 0.00008;
  float rp = 0.009;
  /////////////////////////////////////////////////////
  float right_lv = right_weight * right_radi;
  float left_lv = left_weight * left_radi;
  /////////////////////////////////////////////////////////////////
  float right_l1 = right_lv * cos(right_alpha);
  float right_l2 = right_lv * cos(2.094395 - right_alpha);        // 2*pi/3 - right_alpha
  float right_l3 = right_lv * cos((2 * 2.094395) - right_alpha);  // 4*pi/3 - right_alpha
  float right_theta_m1 = (right_l1 / rp) * 57.2957;
  float right_theta_m2 = (right_l2 / rp) * 57.2957;
  float right_theta_m3 = (right_l3 / rp) * 57.2957;
  /////////////////////////////////////////////////////////////////////////////////
  float left_l1 = left_lv * cos(left_alpha);
  float left_l2 = left_lv * cos(2.094395 - left_alpha);        // 2*pi/3 - left_alpha
  float left_l3 = left_lv * cos((2 * 2.094395) - left_alpha);  // 4*pi/3 - left_alpha
  float left_theta_m1 = (left_l1 / rp) * 57.2957;              //radian to degree
  float left_theta_m2 = (left_l2 / rp) * 57.2957;
  float left_theta_m3 = (left_l3 / rp) * 57.2957;
  Serial.print(left_theta_m1);
  Serial.print(",");
  Serial.print(left_theta_m2);
  Serial.print(",");
  Serial.print(left_theta_m3);
  Serial.print(",");
  Serial.println();
  ///////////FINAL MOTOR ANGLE INPUT WITH 90 DEGREE RESET /////////////////////////////////////
  myservo1.write(90 + right_theta_m1);
  myservo2.write(90 + right_theta_m2);
  myservo3.write(90 + right_theta_m3);
  myservo4.write(90 + left_theta_m1);
  myservo5.write(110 + left_theta_m2);
  myservo6.write(90 + left_theta_m3);
}

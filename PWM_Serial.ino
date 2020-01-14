/*
 * Author: Akhilesh Gowrishetty
 * Date  : 14-01-2020
 * 
 * PWM Values for FlySky CT6B Transmitter and Receiver.
 */

const int ch2=13,ch1=12,ch5=8;
// ch2 = throttle   ch1 = roll    ch5 = knob

unsigned long t_ch1,t_ch2,t_ch5; // timers for pwm signals from TX


void setup() {
  
  Serial.begin(9600);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch5,INPUT);
}

void loop() {
  
  t_ch1=pulseIn(ch1,HIGH);
  t_ch2=pulseIn(ch2,HIGH);
  t_ch5=pulseIn(ch5,HIGH);

  Serial.print("t_ch2");
  Serial.print(t_ch2);
  Serial.print("\t");
  Serial.print("t_ch1");
  Serial.print(t_ch1);
  Serial.print("\t");
  Serial.print(t_ch5);
  Serial.println("\t");
}

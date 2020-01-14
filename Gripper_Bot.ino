#include <Servo.h>

int ch2=13,ch1=12,ch5=8; // ch2(pin13) - forward&backard  ch1(pin12) - turning left&right  ch5(pin8) - gripper(servo)

unsigned long t_ch1,t_ch2,t_ch5; // timers for pwm signals from TX

const int left_p=11,left_n=10,right_p=9,right_n=6; // define the pins of outputs from arduino uno to motor driver

int value=0,pos1=0; // defining variables for controlling motion & servo

Servo gripper_servo;

void setup()
{
  Serial.begin(9600);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch5,INPUT);
  pinMode(left_p,OUTPUT);
  pinMode(left_n,OUTPUT);
  pinMode(right_p,OUTPUT);
  pinMode(right_n,OUTPUT);
  gripper_servo.attach(3);
}

void forward(unsigned long val)
{
  value = map(val, 1500, 1900, 0, 255);
  digitalWrite(left_p,HIGH);
  analogWrite(left_n,0);
  digitalWrite(right_p,HIGH);
  analogWrite(right_n,0);
  Serial.print("f=");
  Serial.println(value);
  return;
}

void backward(unsigned long val)
{
  value = map(val, 1440, 1080, 0, 255);
  analogWrite(left_p,0);
 digitalWrite(left_n,HIGH);
  analogWrite(right_p,0);
  digitalWrite(right_n,HIGH);
  Serial.print("b=");
  Serial.println(value);
  return;
}

void right(unsigned long val)
{
  value = map(val, 1520, 2010, 0, 255);
  digitalWrite(left_p,HIGH);
  analogWrite(left_n,0);
  analogWrite(right_p,0);
  digitalWrite(right_n,HIGH);
  Serial.print("r=");
  Serial.println(value);
  return;
}

void left(unsigned long val)
{
  value = map(val, 1460, 1030, 0, 255);
  analogWrite(left_p,0);
  digitalWrite(left_n,HIGH);
  digitalWrite(right_p,HIGH);
  analogWrite(right_n,0);
  Serial.print("l=");
  Serial.println(value);
  return;
}

void gripper(unsigned long val)
{
  pos1=map((int)val, 990, 2020, 180, 120);
  gripper_servo.write(pos1);
  Serial.print("angle=");
  Serial.println(pos1); 
  return; 
}



void loop()
{
  // put your main code here, to run repeatedly:
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

  if( (int)t_ch2 > 1700 && (int)t_ch2 < 1900)
   {
    forward(t_ch2); 
    delay(10);
   }
  else if( (int)t_ch2 > 1080 && (int)t_ch2 < 1300)
    {
      backward(t_ch2);
      delay(10);
    }
  else if( (int)t_ch1 > 1030 && (int)t_ch1 < 1300)
    {
      left(t_ch1);
      delay(10);
    }
  else if( (int)t_ch1 > 1650 && (int)t_ch1 < 2010)
    {
      right(t_ch1);
      delay(10);
    }
  else 
    {
      digitalWrite(left_p,LOW);
      digitalWrite(left_n,LOW);
      digitalWrite(right_p,LOW);
      digitalWrite(right_n,LOW);  
    }
  if( (int)t_ch5 > 1000 && (int)t_ch5 <2000)
  
    {
       gripper(t_ch5);
        delay(10);
    }
  
  delay(10);
  
}

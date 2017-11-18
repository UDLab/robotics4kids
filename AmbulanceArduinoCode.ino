#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>


//Encoder Motor
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);

void isr_process_encoder1(void)
{
      if(digitalRead(Encoder_1.getPortB()) == 0){
            Encoder_1.pulsePosMinus();
      }else{
            Encoder_1.pulsePosPlus();
      }
}

void isr_process_encoder2(void)
{
      if(digitalRead(Encoder_2.getPortB()) == 0){
            Encoder_2.pulsePosMinus();
      }else{
            Encoder_2.pulsePosPlus();
      }
}

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
            leftSpeed = -speed;
            rightSpeed = speed;
      }else if(direction == 2){
            leftSpeed = speed;
            rightSpeed = -speed;
      }else if(direction == 3){
            leftSpeed = -speed;
            rightSpeed = -speed;
      }else if(direction == 4){
            leftSpeed = speed;
            rightSpeed = speed;
      }
      Encoder_1.setTarPWM(leftSpeed);
      Encoder_2.setTarPWM(rightSpeed);
}
void moveDegrees(int direction,long degrees, int speed_temp)
{
      speed_temp = abs(speed_temp);
      if(direction == 1)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
      else if(direction == 2)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
      else if(direction == 3)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
      else if(direction == 4)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
}

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void lightsOnOffWhileDriving();
MeRGBLed rgbled_0(0, 12);
MeBuzzer buzzer;
void lightsAtInterSection();


void lightsOnOffWhileDriving()
{
    for(int __i__=0;__i__<10;++__i__)
    {
        for(int __i__=0;__i__<2;++__i__)
        {
            rgbled_0.setColor(2,0,0,20);
            rgbled_0.show();
            rgbled_0.setColor(8,0,0,20);
            rgbled_0.show();
            rgbled_0.setColor(0,0,0,0);
            rgbled_0.show();
            _delay(0.1);
        }
        buzzer.tone(392, 500);
        delay(20);
        for(int __i__=0;__i__<2;++__i__)
        {
            rgbled_0.setColor(4,0,0,20);
            rgbled_0.show();
            rgbled_0.setColor(10,0,0,20);
            rgbled_0.show();
            rgbled_0.setColor(0,0,0,0);
            rgbled_0.show();
            _delay(0.1);
        }
        buzzer.tone(587, 500);
        delay(20);
    }
    
}

void lightsAtInterSection()
{
    for(int __i__=0;__i__<4;++__i__)
    {
        rgbled_0.setColor(2,0,0,60);
        rgbled_0.show();
        rgbled_0.setColor(8,0,0,60);
        rgbled_0.show();
        rgbled_0.setColor(4,0,0,60);
        rgbled_0.show();
        rgbled_0.setColor(10,0,0,60);
        rgbled_0.show();
        buzzer.tone(196, 1000);
        delay(20);
        _delay(0.5);
        rgbled_0.setColor(0,0,0,0);
        rgbled_0.show();
        _delay(0.1);
    }
    
}


void setup(){
    rgbled_0.setpin(44);
    buzzer.setpin(45);
    
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}


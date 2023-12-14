#include<boltiot.h>
#ifndef API_KEY
#define API_KEY   "985b48ef-3413-4906-ac6f-698cbe98b500"
#endif
#ifndef DEVICE_ID
#define DEVICE_ID "BOLT9097634"
#endif
int buzPin = 7;       
int trigPin = 9;       
int echoPin = 10;      
float speed = 0.0347; 
float dist;           
float pingTime;       
int buzNear = 20;     
int buzHigh = 50;     
int buzMid  =130;     
int buzFar = 600;     
int delayFar = 260;
int l1=5;

 
 
void setup() {
  boltiot.Begin(Serial);
  pinMode(buzPin,OUTPUT);     //set buzzer & trigger pin as outpin;
  pinMode(trigPin,OUTPUT);    
  pinMode(echoPin,INPUT);     //set echo pin as input;
  pinMode(l1,OUTPUT);
  
 
}
 
void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);          //creating a pulse for sensing distance;
  pingTime = pulseIn(echoPin,HIGH);   //read the echoTime, &hence the distance;
  dist = (speed*pingTime*0.5);    
  boltiot.processPushDataCommand(dist);     
  
  if(dist<=10.0){
    digitalWrite(buzPin,HIGH);         //simple conditional statements changing frequency based upon the distance sensed
    delay(20);
    
    digitalWrite(buzPin,LOW);
    delay(20);
    digitalWrite(l1,HIGH);
    delay(20);
  }  
  else if(dist<=30.0 && dist>10.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzHigh);
    digitalWrite(buzPin,LOW);
    delay(buzHigh);
    digitalWrite(l1,LOW);
  }
  else if((dist>30.0) && (dist<60.0))
  {
    digitalWrite(buzPin,HIGH);
    delay(buzMid);
    digitalWrite(buzPin,LOW);
    delay(buzMid);
    digitalWrite(l1,LOW);
  }
  else if(dist>=60.0 && dist<120.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzFar);
    digitalWrite(buzPin,LOW);
    delay(delayFar);
    digitalWrite(l1,LOW);
  }
  
}

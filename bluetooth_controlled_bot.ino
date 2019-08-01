
#include<Servo.h>
// initializing the code by mentioning the pin number and connections
Servo Turn_Servo;
const int m1_1 = 4;    //Left wheel
const int m1_2 = 2;    
const int m2_1 = 5;    //Right wheel
const int m2_2 = 7;    
const int en_1 = 3;     //Enable Left 
const int en_2 = 6;       

const int IR = 10;       

const int PinServo = 9;   


char Trigger;

void StopMotor() // code to stop moving the motor
{
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,LOW);
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,LOW);
}

void Left(int PwmC = 100){ // to turn left by making left motor LOW and right motor HIGH
  digitalWrite(m1_1,HIGH);
  digitalWrite(m1_2,LOW);
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,HIGH);
  analogWrite(en_1,PwmC);
  analogWrite(en_2,PwmC);
}

void Right(int PwmC = 100){ // to turn right by making right motor LOW and left motor HIGH
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,HIGH);
  digitalWrite(m2_1,HIGH);
  digitalWrite(m2_2,LOW);
  analogWrite(en_1,PwmC);
  analogWrite(en_2,PwmC);
}

void Forward(int PwmC = 100){ // function to move forward
  digitalWrite(m1_1,HIGH);
  digitalWrite(m1_2,LOW);
  digitalWrite(m2_1,HIGH);
  digitalWrite(m2_2,LOW);
  analogWrite(en_1,PwmC);
  analogWrite(en_2,PwmC);
  //Serial.print(dist1);
}

void Reverse(int PwmC = 100){ // fucntion to move reverse
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,HIGH);
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,HIGH);
  analogWrite(en_1,PwmC);
  analogWrite(en_2,PwmC);
  //Serial.print(dist1);
}

void TServo(){ // function to turn the servo motor by 90 degrees and a delay is given after every 90 degrees.
  int pos = 0;
  Turn_Servo.write(90);
  delay(300);
  Turn_Servo.write(0);
  delay(100);
  Forward(240);
  delay(200);
}


void setup() {// define the OUTPUT and INPUT to the arduino by setting the motors as OUTPUT and IR as INPUT.
  Turn_Servo.attach(PinServo);
  Serial.begin(9600);
  pinMode(m1_1,OUTPUT);
  pinMode(m1_2,OUTPUT);
  pinMode(m2_1,OUTPUT);
  pinMode(m2_2,OUTPUT);
  pinMode(en_1,OUTPUT);
  pinMode(en_2,OUTPUT);  
  pinMode(IR,INPUT);
}


void loop() {
  if(Serial.available() > 0)     // Send data only when you receive data:
     {
        Trigger = Serial.read();      
        Serial.println(Trigger);      
     }
     
  if(!digitalRead(IR)) // Black Considered as 0 and white as 1. Servo should turn 90 degrees when it reads a black line.
  {
    Serial.println("IR");
    TServo();
    Forward(200);
    delay(100);
  }

  if(Trigger == 'F'){    //For FWD 
    Forward(240);
    delay(49);
    Serial.println("forward");      
  }
  
  else if(Trigger =='R'){  //For Right 
    Right(150);
    delay(49);
    Serial.println("Right");      
  }
  
  else if(Trigger == 'L'){  //For Left 
    Left(150);
    delay(49);
    Serial.println("Left");         
  }
  
  else if(Trigger == 'B'){ //For Reverse
    Reverse(240);
    delay(49);
    Serial.println("reverse");      
  }
  else if(Trigger == 'I'){
      digitalWrite(m1_1,HIGH);
      digitalWrite(m1_2,LOW);
      digitalWrite(m2_1,HIGH);
      digitalWrite(m2_2,LOW);
      analogWrite(en_2,150);
      analogWrite(en_1,75);
      delay(48);   
  }
  else if(Trigger == 'G'){
      digitalWrite(m1_1,HIGH);
      digitalWrite(m1_2,LOW);
      digitalWrite(m2_1,HIGH);
      digitalWrite(m2_2,LOW);
      analogWrite(en_2,75);
      analogWrite(en_1,150);  
      delay(48); 
  }
  else if(Trigger == 'H'){
      digitalWrite(m1_1,LOW);
      digitalWrite(m1_2,HIGH);
      digitalWrite(m2_1,LOW);
      digitalWrite(m2_2,HIGH);
      analogWrite(en_2,75);
      analogWrite(en_1,150);   
      delay(48); 
  }
  
  else if(Trigger == 'J'){
      digitalWrite(m1_1,LOW);
      digitalWrite(m1_2,HIGH);
      digitalWrite(m2_1,LOW);
      digitalWrite(m2_2,HIGH);
      analogWrite(en_2,150);
      analogWrite(en_1,75);   
      delay(48); 
  }
  
  else{
    StopMotor();
  }
  Trigger = '0';
}

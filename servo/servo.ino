#include<Servo.h> 
Servo servo1,servo2;




void setup() {
  // put your setup code here, to run once:
servo1.attach(4);
servo2.attach(6);
pinMode(10,OUTPUT);
}

void loop() {                                                                                               
  // put your main code here, to run repeatedly:
servo1.write(180);
servo2.write(90);
digitalWrite(10,HIGH);
delay(1000);
servo1.write(165);
servo2.write(105);
digitalWrite(10,LOW);
delay(1000);
servo1.write(150);
servo2.write(120);
digitalWrite(10,HIGH);
delay(1000);

servo1.write(135);
servo2.write(135 );
digitalWrite(10,LOW);
servo2.write(150);
digitalWrite(10,HIGH);
delay(1000);
servo1.write(105);
servo2.write(165);
digitalWrite(10,LOW);
delay(1000);

servo1.write(90);
servo2.write( 180);
digitalWrite(10,HIGH);
delay(1000);

}

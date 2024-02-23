
int sensor;           ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
sensor = analogRead(A0);

Serial.println(sensor);

if(sensor<500){
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(5,LOW);
  
  }
if(sensor>500){
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,HIGH);
  
  }



}

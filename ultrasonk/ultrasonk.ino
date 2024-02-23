#include<Servo.h> 

int trig = 8;           // membuat varibel trig yang di set ke-pin 3
int echo = 9;           // membuat variabel echo yang di set ke-pin 2
long durasi, jarak;     // membuat variabel durasi dan jarak
Servo servo;

void setup() {
  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  Serial.begin(9600);       // digunakan untuk komunikasi Serial dengan komputer
  pinMode(6, OUTPUT);  
}

void loop() {

  // program dibawah ini agar trigger memancarakan suara ultrasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);

  durasi = pulseIn(echo, HIGH); // menerima suara ultrasonic
  jarak = (durasi / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
  Serial.print(jarak);        // menampilkan jarak pada Serial Monitor
  Serial.println(" cm"); 


 if( jarak < 30){
  digitalWrite(6, HIGH);
  }

 if( jarak > 30){
  digitalWrite(6, LOW);
    }

}                                       

 //MANIPULASI LENGAN (ARM)  ROBOT 
#include <Stepper.h>
// mendefinisikan revolisi per langkah pada motor bawah dan tengah
#define STEPS1 360 
#define STEPS2 135
// buat posisi kuda-kuda dari kelas stepper,
// definisi pin stepper motor bawaah dan tengah
Stepper stepper1(STEPS1, 12, 11, 10, 9);
Stepper stepper2(STEPS2, 7, 6, 5, 4);
// definisi bacaan sebelumnya dari input analog
int previous1 = 0;
int previous2 = 0;
//definisi buat gripper 
const int pbt = 2;
const int capit = 8;
boolean hasil;
void setup() {
 Serial.begin(9600);//nomor virtual serial monitor 9600
  Serial.println("------------------------------------");
  Serial.println("nama : Furqon Maulana          ");
  Serial.println("nim  : 190534646426");  
  Serial.println("prodi: S1 PTE A");
  Serial.println("------------------------------------");
// atur kecepatan motor ke 30 RPM/s
  stepper1.setSpeed(50);
  stepper2.setSpeed(50);
  pinMode (capit,OUTPUT);//tegangan yang dikeluarkan
  pinMode (pbt, INPUT_PULLUP); //masukan tegangan ke adruino
}
void loop() {
  //controling stepper motor dengan potensio motor ARM bawah
  // mendapatkan hasil bacaan ARM dalam betuk analog
  int val1 = analogRead(A0);
int steep1=map(val1,0,1023,0,STEPS1);//merubah hasil bacaan agar terbaca ke analogWrite
//memindahkan sejumlah langkah yang sama dengan perubahan pada pembacaan stepper
Serial.print("putaran horizontal robot ARM Bawah ="); 
Serial.print(" ");
Serial.print(steep1);
Serial.print(""); 
 delay(1000);
 
//memindahkan 1 langkah yang sama dengan perubahan pada pembacaan stepper dengan syntax if
//stepper dalam kondisi bergerak dengan control potensio ARM bawah
if(steep1>previous1){ 
 stepper1.step(1);
 Serial.print(" : ");
 Serial.print("bergerak ke arah cw");
 }// ingat nilai sensor sebelumnya
 else if(steep1<previous1){ 
 stepper1.step(-1);
Serial.print(" : ");
Serial.print("bergerak ke arah ccw");
 }
else{//stepper bawah dalam kondisi tidak bergerak
  Serial.print(" : ");
  Serial.print("motor kondisi diam");
}
  Serial.println();
  previous1 = steep1;
 //controling stepper motor dengan potensio motor ARM tengah
int val2 = analogRead (A1);
int steep2 =map(val2,0,1023,0,STEPS2);
Serial.print("putaran sudut robot ARM Tengah     =");
Serial.print(" ");
Serial.print(steep2);

delay(1000);
 
//memindahkan 1 langkah yang sama dengan perubahan pada pembacaan stepper dengan syntax if
//stepper dalam kondisi bergerak dengan control potensio 
if(steep2>previous2){ 
 stepper2.step(1);
Serial.print(" : ");
Serial.print("bergerak ke arah cw");
 
 }
else if(steep2<previous2){ 
 stepper2.step(-1);
Serial.print(" : ");
Serial.print("bergerak ke arah ccw");
}
else{//stepper tengah dalam kondisi tidak bergerak
Serial.print(" : ");
Serial.print("motor kondisi diam");
}
// ingat nilai sensor sebelumnya
previous2 = steep2;
 Serial.println();
//mendapatkan hasil bacaan capit dalam bentuk digital
hasil = digitalRead(pbt);
if (hasil !=1){
digitalWrite(capit,HIGH);//syntax capit
Serial.println("      capit robot                  = tertup");
Serial.println();
}
else{
digitalWrite(capit,LOW);
Serial.println("      capit robot                  = terbuka");
Serial.println();
}
}

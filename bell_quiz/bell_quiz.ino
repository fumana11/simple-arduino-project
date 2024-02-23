/* Program Tombol Cerdas Cermat Arduino Uno dibuat oleh Indobot */
#define pb1 2       //Button 1 pada pin D2
#define pb2 3
#define pb3 4
#define pb4 5       //Button 1 pada pin D2
#define pb5 6

#define LED1 7      //LED1 pada pin D5
#define LED2 8
#define LED3 9
#define LED4 10
#define LED5 11
#define bell 12


#define ulang 13     //Button reset pada pin D8

bool kunci = false;

void setup() {
  Serial.begin(9600);
  pinMode(pb1, INPUT_PULLUP);   //Setting I/O
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  pinMode(pb4, INPUT_PULLUP);
  pinMode(pb5, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(bell, OUTPUT);
  pinMode(ulang, INPUT_PULLUP);

      digitalWrite(LED1, HIGH);

      digitalWrite(LED2, HIGH);

      digitalWrite(LED3, HIGH);

      digitalWrite(LED4, HIGH);

      digitalWrite(LED5, HIGH);

      digitalWrite(bell, HIGH);


}

void loop() {
 
  if(kunci == false){               //Jika kunci terbuka, maka
 
    if(digitalRead (pb1) == LOW){       //Jika button 1 ditekan, maka
      digitalWrite(bell, LOW);         
      digitalWrite(LED1, LOW);
      delay(1000);
      digitalWrite(bell, HIGH);
      kunci = true;                     //Mengunci
 
    }

    else if(digitalRead (pb2) == LOW){
      digitalWrite(bell, LOW);         
      digitalWrite(LED2, LOW);
      delay(1000);
      digitalWrite(bell, HIGH);
      kunci = true;
    }
 
    else if(digitalRead (pb3) == LOW){
      digitalWrite(bell, LOW);         
      digitalWrite(LED3, LOW);
      delay(1000);
      digitalWrite(bell, HIGH);
      kunci = true;
    }
 
    else if(digitalRead (pb4) == LOW){
      digitalWrite(bell, LOW);         
      digitalWrite(LED4, LOW);
      delay(1000);
      digitalWrite(bell, HIGH);
      kunci = true;
    }
 
    else if(digitalRead (pb5) == LOW){
      digitalWrite(bell, LOW);         
      digitalWrite(LED5, LOW);
      delay(1000);
      digitalWrite(bell, HIGH);         
      kunci = true;
    }

 
  }
  else{                             //Jika terkunci, maka

    if(digitalRead (ulang) == LOW){

      kunci = false;                //Terbuka kalau tombol reset ditekan

      digitalWrite(LED1, HIGH);

      digitalWrite(LED2, HIGH);

      digitalWrite(LED3, HIGH);

      digitalWrite(LED4, HIGH);

      digitalWrite(LED5, HIGH);

      digitalWrite(bell, HIGH);
      
      delay(200);
    }

  }

Serial.print(pb1); Serial.print("  ");
Serial.print(pb2); Serial.print("  ");
Serial.print(pb3); Serial.print("  ");
Serial.print(pb4); Serial.print("  ");
Serial.print(pb5); Serial.print("  ");




}

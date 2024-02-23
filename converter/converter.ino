const int PWM = 9; //Inisialisasi output PWM di pin D9
const int potensio = A1; //Inisialisasi input ADC di pin A1
int nilaipotensio; //Inisialisasi variabel Potensio untuk menyimpan nilai input potensio dari pin A1
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600); //Baud rate untuk komunikasi serial
pinMode(PWM,OUTPUT); //Set D9 Sebagai Output
pinMode(potensio,INPUT); //Set D1 sebagai input
}

void loop() {
 // put your main code here, to run repeatedly:
nilaipotensio = analogRead(potensio); //membaca potensio
nilaipotensio = map(nilaipotensio,0,1024,0,255); //Mengkonversi nilai ADC (0-1024) menjadi 8bit (0-255)
Serial.println(nilaipotensio); //Mengirimkan nilai potensio ke serial
analogWrite(PWM,nilaipotensio); //Value dari nilai potensio dioutputkan menjadi PWM pada D9
}

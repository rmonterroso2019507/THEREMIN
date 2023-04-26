/*
 Fundacion Kinal
 Centro Educativo Tecnico Laboral KINAL
 Electronica
 Grado:5to A
 Nombre:Roberto Monterroso
 Carne :2019507
 */

int trig = 2; // Pin del sensor ultrasónico TRIG
int echo = 3; // Pin del sensor ultrasónico ECHO
int Buzzer = 5; // Pin del Buzzer
int f=261;//esta do 
int a=294;// esta re 
int cH=329;//esta mi
int eH=349;//esta fa 
int b=392;//esta sol 
int c=440;//esta la 


 void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duracion, distancia;
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58;

  if (distancia > 0 && distancia <= 5) { // Si la distancia está entre 0 y 5 cm
    tone(Buzzer, f, 500);
    delay(500+50);
    
  } else if (distancia > 5 && distancia <= 10) { // Si la distancia está entre 5 y 10 cm
    tone(Buzzer, a, 500);
    delay(500+50);     
    
  } else if (distancia > 10 && distancia <= 15) { // Si la distancia está entre 10 y 15 cm
    tone(Buzzer, f, 500);
    delay(500+50);
    
  } else if (distancia > 15 && distancia <= 20) { // Si la distancia está entre 15 y 20 cm
    tone(Buzzer, cH, 350);  
    delay(350+50);
    
  } else if (distancia > 20 && distancia <= 25) { // Si la distancia está entre 20 y 25 cm
    tone(Buzzer, eH, 150);
    delay(150+50); 
    
    
  } else if (distancia > 25 && distancia <= 30) { // Si la distancia está entre 25 y 30 cm
    tone(Buzzer, b, 500);
    delay(500+50);
    
  } else if (distancia > 30 && distancia <= 35) { // Si la distancia está entre 30 y 35 cm
    tone(Buzzer, c, 350);
    delay(350+50);  
    
  } 
    else {
      
      noTone(Buzzer); // Silencio
      }
    
  Serial.print(distancia);
  Serial.println(" cm");
  delay(2000);  // dos segundos para volver a empezar.
}

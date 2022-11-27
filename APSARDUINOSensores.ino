#include <Wire.h>  //Esta biblioteca permite que você se comunique com dispositivos I2C/TWI. Nas placas Arduino com o layout R3 (pinagem 1.0), o SDA (linha de dados) e SCL (linha de clock) estão nos cabeçalhos dos pinos próximos ao pino AREF. O Arduino Due possui duas interfaces I2C/TWI SDA1 e SCL1 próximas ao pino AREF e uma adicional nos pinos 20 e 21.

int SensorD = A1;  // sensor de linha da direita
int SensorC = 2;          // sensor de linha do meio
int SensorE = A0;  // sensor de linha da esquerda
int MET = 6;       // motor da esquerda para trás
int MEF = 5;       // motor da esquerda para frente
int MDF = 4;       // motor da direita para frente
int MDT = 3;       // motor da direita para trás
int POT = 255;     // potencia dos motores
/*RGB*/
int LDR = 7;  //Led vermelho


void setup() {
  //Motores
  pinMode(MEF, OUTPUT);
  pinMode(MET, OUTPUT);
  pinMode(MDF, OUTPUT);
  pinMode(MDT, OUTPUT);

  //Sensores infravermelhos
  Serial.begin(9600);

  pinMode(SensorD, INPUT);
  pinMode(SensorC, INPUT);
  pinMode(SensorE, INPUT);

  //Sensor RGB/LED
  Serial.begin(9600);  //Iniciamos o monitor serial na taxa de transmissão de 9600

}

  void loop() {

    if (digitalRead(SensorE) == LOW && digitalRead(SensorD) == LOW && digitalRead(SensorC) == LOW) {  // detectou a linha branca nos dois sensores
      analogWrite(MDF, 0);
      analogWrite(MEF, 0);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else if (digitalRead(SensorE) == LOW && digitalRead(SensorD) == HIGH && digitalRead(SensorC) == LOW) {  // detectou a linha branca na esquerda
      analogWrite(MDF, POT);
      analogWrite(MEF, 0);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else if (digitalRead(SensorE) == HIGH && digitalRead(SensorD) == LOW && digitalRead(SensorD) == LOW) {  // detectou a linha branca na direita
      analogWrite(MDF, 0);
      analogWrite(MEF, POT);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else if (digitalRead(SensorE) == LOW && digitalRead(SensorD) == LOW && digitalRead(SensorD) == HIGH) {  // detectou a linha branca na direita
      analogWrite(MDF, POT);
      analogWrite(MEF, POT);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else {  // nao detectou nenhuma linha branca
      analogWrite(MDF, POT);
      analogWrite(MEF, POT);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    }


  delay(20);
  analogWrite(MDF, 0);
  analogWrite(MEF, 0);
  analogWrite(MDT, 0);
  analogWrite(MET, 0);
  delay(10);
}
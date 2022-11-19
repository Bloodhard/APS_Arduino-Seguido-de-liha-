#include <Wire.h>  //Esta biblioteca permite que você se comunique com dispositivos I2C/TWI. Nas placas Arduino com o layout R3 (pinagem 1.0), o SDA (linha de dados) e SCL (linha de clock) estão nos cabeçalhos dos pinos próximos ao pino AREF. O Arduino Due possui duas interfaces I2C/TWI SDA1 e SCL1 próximas ao pino AREF e uma adicional nos pinos 20 e 21.
//#include "Adafruit_TCS34725.h" //biblioteca do sensor RGB TCS34725

int SensorC = A1;  // sensor de linha da direita
//int SensorD = 2;          // sensor de linha do meio
int SensorE = A0;  // sensor de linha da esquerda
int MET = 6;       // motor da esquerda para trás
int MEF = 5;       // motor da esquerda para frente
int MDF = 4;       // motor da direita para frente
int MDT = 3;       // motor da direita para trás
int POT = 255;     // potencia dos motores
/*RGB*/
int LDR = 7;  //Led vermelho
//int SDA = A4; // Define o pino pinoOut como pino analogico A4
//int SCL = A5;// Define o pino pinoS3 como pino analogico A5

/* Inicializa com valores específicos de tempo e ganho int */
//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  //Motores
  pinMode(MEF, OUTPUT);
  pinMode(MET, OUTPUT);
  pinMode(MDF, OUTPUT);
  pinMode(MDT, OUTPUT);

  //Sensores infravermelhos
  Serial.begin(9600);

  pinMode(SensorC, INPUT);
  //pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);

  //Sensor RGB/LED
  Serial.begin(9600);  //Iniciamos o monitor serial na taxa de transmissão de 9600
  //pinMode(LDR, OUTPUT);  // Configula LED vermelho como saída



  void loop() {
    //RGB2Code//
    uint16_t r, g, b, c;
    //tcs.getRawData(&r, &g, &b, &c);//Pega os valores "crus" do sensor referentes ao Vermelho(r), Verde(g), Azul(b) e da Claridade(c).

    /*
  //Para impirmir os valores na tela de RGB//
  Serial.print("Red: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("Green: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("Blue: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Color: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  analogWrite (led, c); 
  delay(100);
  */

    /*
  void semaforo() {
    //se intensidade luminosa for maior que 500 então
    if(c < 5000) {
      if(r > b && r > g) {  //Se intensidade de vermelho for maior que azul e se intensidade de vermelho for maior que verde.
        //parar os motores
        analogWrite(MDF, 0);
        analogWrite(MEF, 0);   
        analogWrite(MDT, 0);
        analogWrite(MET, 0);   
        delay(100)
      }
      else if(r && g > g && b == 0) { //Para formar o amarelo é necessario #FFFF00 (Vermelho[red] e verde[green]) e zero para azul. 
        digitalWrite(LDR, HIGH); //Se atender a condição para o amarelo ligar Led vermelho
      }
      else {
        digitalWrite(LDR, HIGH); //Se não atender a condição para o amarelo ligar Led vermelho
    }
  }
  */

    //semaforo();
    if (digitalRead(SensorE) == LOW && digitalRead(SensorC) == LOW) {  // detectou a linha branca nos dois sensores
      analogWrite(MDF, 0);
      analogWrite(MEF, 0);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else if (digitalRead(SensorE) == HIGHT && digitalRead(SensorC) == LOW) {  // detectou a linha branca na esquerda
      analogWrite(MDF, POT);
      analogWrite(MEF, 0);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else if (digitalRead(SensorE) == LOW && digitalRead(SensorC) == HIGHT) {  // detectou a linha branca na direita
      analogWrite(MDF, 0);
      analogWrite(MEF, POT);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    } else {  // nao detectou nenhuma linha preta
      analogWrite(MDF, POT);
      analogWrite(MEF, POT);
      analogWrite(MDT, 0);
      analogWrite(MET, 0);
    }
  }






  delay(20);
  analogWrite(MDF, 0);
  analogWrite(MEF, 0);
  analogWrite(MDT, 0);
  analogWrite(MET, 0);
  delay(10);
}
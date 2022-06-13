#include <Arduino.h>  //  framework do Arduino
#include <ESP32Servo.h> //  biblioteca do Servo
#include <Ps3Controller.h>  //  biblioteca do Controle de PS3

Servo myservo;

int leftXAxis;  //  armazena o valor do eixo X do analógico esquerdo

void setup() {
    Serial.begin(9600);
    Ps3.begin("94:b9:7e:d5:ab:e2"); //  inicializa o controle que possui o endereço MAC especificado no parâmetro

    myservo.attach(27); //  inicializa o Servo Motor na porta digital 27
    myservo.write(2); //  e escreve um ângulo de 2 graus nele

    Serial.println("Ready.");
}

void loop() {

  leftXAxis = map(Ps3.data.analog.stick.lx, -128, 127, 2, 181); // transforma os valores do analógico para ângulo

  Serial.print(Ps3.data.analog.stick.lx);
  Serial.print(" || ");
  // Serial.println(Ps3.data.analog.stick.ly);
  // Serial.print(" || ");
  Serial.println(leftXAxis);


  myservo.write(leftXAxis); //  escreve o valor convertido no Servo

  /*

  if (Ps3.data.button.cross){ //  funções com os botões do controle, pode ser qualquer coisa
    myservo.write(177);
  }

  if (Ps3.data.button.triangle){
    myservo.write(2);
  }

  */
}
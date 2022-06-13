#include <Arduino.h>        //  framework do Arduino
#include <ESP32Servo.h>     //  biblioteca do Servo
#include <Ps3Controller.h>  //  biblioteca do Controle de PS3

Servo myservoL;
Servo myservoR;

int leftXAxis;   //  armazena o valor do eixo X do analógico esquerdo
int rightXAxis;  //  armazena o valor do eixo X do analógico direito

void setup() {
    Serial.begin(9600);
    Ps3.begin("94:b9:7e:d5:ab:e2");  //  inicializa o controle que possui o endereço MAC especificado no parâmetro

    myservoL.attach(27);  //  inicializa o Servo Motor na porta digital 27
    myservoR.attach(26);  //  inicializa o Servo Motor na porta digital 26

    myservoL.write(2);  //  e escreve um ângulo de 2 graus neles
    myservoR.write(2);  //  

    Serial.println("Ready.");
}

void loop() {
    leftXAxis = map(Ps3.data.analog.stick.lx, -128, 127, 2, 181);  // transforma os valores do analógico para ângulo

    rightXAxis = map(Ps3.data.analog.stick.rx, -128, 127, 2, 181);

    Serial.print(Ps3.data.analog.stick.lx);
    Serial.print(" || ");
    // Serial.println(Ps3.data.analog.stick.ly);
    // Serial.print(" || ");
    Serial.print(leftXAxis);
    Serial.print(" || ");

    Serial.print(Ps3.data.analog.stick.rx);
    Serial.print(" || ");
    Serial.println(rightXAxis);

    myservoL.write(leftXAxis);  //  escreve o valor convertido no Servo

    myservoR.write(rightXAxis);

    /*

    if (Ps3.data.button.cross){ //  funções com os botões do controle, pode ser qualquer coisa
      myservo.write(177);
    }

    if (Ps3.data.button.triangle){
      myservo.write(2);
    }

    */
}

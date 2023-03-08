#include<math.h>

//Ponte H portas
#define IN1 7
#define IN2 5
#define VEL_A 6
#define IN3 4
#define VEL_B 13

//Botões
#define BUTTON_1 11
#define BUTTON_2 10

//Variáveis
int velocidade = 0;

void setup() {
//Iniciando a serial do arduino
  Serial.begin(9600);
//Iniciando os pinos do motor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(VEL_A,OUTPUT);
  pinMode(VEL_B,OUTPUT);
//Iniciando os botões
  pinMode(BUTTON_1,INPUT);
  pinMode(BUTTON_2,INPUT);
}

void loop() {
//Verificação se o botão 1 foi pressionado
  if(digitalRead(BUTTON_1) == HIGH && velocidade < 250){
//Mais velocidade e colocar um delay
  velocidade += 10;
  delay(80);
  }
//Verificação se o botão 2 foi pressionado
  if(digitalRead(BUTTON_2) == HIGH && velocidade >- 250){
//Menos velocidade e colocar um delay
  velocidade -= 10;
  delay(80);
  }
//Velocidade maior que 0
  if(velocidade > 0){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
//Velocidade igual a 0
  else if(velocidade == 0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
//Velocidade menor que 0
  else if(velocidade < 0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
//Controle de velocidade
  analogWrite(VEL_A,abs(velocidade));
  analogWrite(VEL_B,abs(velocidade));
  delay(80);
}

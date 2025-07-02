#include <Servo.h>

Servo myservo;
#define ldr1 A1
#define ldr2 A2
#define pinUmidade A0

int pos = 90;
int tolerancia = 20;

const int valorAr = 489;
const int valorAgua = 193;

const int pinBomba = 8;

void setup() {
  myservo.attach(3);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(pinBomba, OUTPUT);
  myservo.write(pos);
  Serial.begin(9600);
  Serial.println("Iniciando leitura do sensor de umidade de solo...");
  delay(1000);
}
void loop() {
  TrackSolar();
  int valorSensor = analogRead(pinUmidade);
  int umidadePercentual = map(valorSensor, valorAr, valorAgua, 0, 100);
  umidadePercentual = constrain(umidadePercentual, 0, 100);

  Serial.print("Valor Cru: ");
  Serial.print(valorSensor);
  Serial.print("  |  Umidade: ");
  Serial.print(umidadePercentual);
  Serial.println("%");
  delay(1000);

  if (umidadePercentual < 20) {
    digitalWrite(pinBomba, HIGH);
    delay(2000);
    digitalWrite(pinBomba, LOW);
    Serial.println("Aguardando antes da proxima verificacao...");
    delay(5000);
  }
  else {
    Serial.println("Solo úmido");
  }
  delay(500);
}




//creditos: https://marobotic.com/2023/10/22/automatic-solar-tracker-system-using-arduino-ldr-and-servo-motor/
void TrackSolar() {
  int val1 = analogRead(ldr1);
  int val2 = analogRead(ldr2);

  if ((abs(val1 - val2) <= tolerancia) || (abs(val2 - val1) <= tolerancia)) {
  } else {
    if (val1 > val2)
    {
      pos = pos + 1;
    }
    if (val1 < val2)
    {
      pos = pos - 1;
    }
  }
  if (pos > 180) {
    pos = 180;
  }
  if (pos < 0) {
    pos = 0;
  }
  myservo.write(pos);
  delay(50);
}

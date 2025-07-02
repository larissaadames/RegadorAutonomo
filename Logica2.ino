#include <Servo.h>

// --- OBJETOS E DEFINIÇÕES DE PINOS ---
Servo myservo;

const int pinServo = 3;      
const int pinLDR1 = A1; 
const int pinLDR2 = A2;
const int pinUmidade = A0;
const int pinBomba = 8;

// --- VARIÁVEIS DO TRACKER ---
int posServo = 90; //posicao inicial do servo
int tolerancia = 20;

// --- VARIÁVEIS E CALIBRAÇÃO DO SENSOR DE UMIDADE ---
const int valorAr = 489;
const int valorAgua = 193;
const int limiteUmidade = 30; // Valor de ativacao da bomba

unsigned long tempoAnterior = 0; // última verificacao da umidade
const long intervalo = 5000;      // Intervalo entre verificações de umidade


void setup() {
  myservo.attach(pinServo);
  pinMode(pinBomba, OUTPUT);
  digitalWrite(pinBomba, HIGH); 

  myservo.write(posServo);
  Serial.begin(9600);
  Serial.println("Sistema Final Iniciado!");
}

void loop() {
  TrackSolar();

  unsigned long tempoAtual = millis(); // tempo atual do "cronômetro"

  if (tempoAtual - tempoAnterior >= intervalo) { // verificação de intervalo da checagem
    tempoAnterior = tempoAtual;
  

    bomba();
  }
}


void bomba() {
  int valorSensor = analogRead(pinUmidade);
  int umidadePercentual = map(valorSensor, valorAr, valorAgua, 0, 100);
  umidadePercentual = constrain(umidadePercentual, 0, 100);

  Serial.print("VERIFICACAO - Umidade: ");
  Serial.print(umidadePercentual);
  Serial.println("%");

  if (umidadePercentual < limiteUmidade) {
    Serial.println(" -> Solo seco! Ativando ciclo de rega...");
   
    digitalWrite(pinBomba, LOW);
    delay(2000);                 
    digitalWrite(pinBomba, HIGH);
    Serial.println("Ciclo de rega finalizado.");
  } else {
    Serial.println(" -> Solo umido. Nenhuma acao necessaria.");
  }
}

//creditos: https://marobotic.com/2023/10/22/automatic-solar-tracker-system-using-arduino-ldr-and-servo-motor/
void TrackSolar() {
  int val1 = analogRead(pinLDR1);
  int val2 = analogRead(pinLDR2);

  if (abs(val1 - val2) > tolerancia) {
    if (val1 > val2) {
      posServo++;
    } else {
      posServo--;
    }
  }

  posServo = constrain(posServo, 0, 180);
  myservo.write(posServo);
  delay(50);
}

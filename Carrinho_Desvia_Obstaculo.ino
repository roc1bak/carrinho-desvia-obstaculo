// CÓDIGO CARRINHO DESVIA OBSTACULO 
#define MOTOR_A_IN1 21
#define MOTOR_A_IN2 18
#define MOTOR_B_IN1 22
#define MOTOR_B_IN2 23
#define TRIG_ESQ 13
#define ECHO_ESQ 14
#define TRIG_CENTRO 25
#define ECHO_CENTRO 26
#define TRIG_DIR 32
#define ECHO_DIR 33

// Distâncias dos sensores 
float distanciaEsq;
float distanciaCentro;
float distanciaDir;

// Distância mínima para detectar objetos
const int DISTANCIA_MINIMA = 25;

void setup() {
  Serial.begin(115200);

  // Configuração dos motores
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);

  // Configuração dos sensores
  pinMode(TRIG_ESQ, OUTPUT);
  pinMode(ECHO_ESQ, INPUT);

  pinMode(TRIG_CENTRO, OUTPUT);
  pinMode(ECHO_CENTRO, INPUT);
  
  pinMode(TRIG_DIR, OUTPUT);
  pinMode(ECHO_DIR, INPUT);
  
  pararMotores();
  
  Serial.println("Conectado");
}

void loop() {
  distanciaEsq = medirDistancia(TRIG_ESQ, ECHO_ESQ);
  delay(40);

  distanciaCentro = medirDistancia(TRIG_CENTRO, ECHO_CENTRO);
  delay(40);

  distanciaDir = medirDistancia(TRIG_DIR, ECHO_DIR);
  delay(40);

  if (distanciaCentro < DISTANCIA_MINIMA &&
      distanciaEsq < DISTANCIA_MINIMA &&
      distanciaDir < DISTANCIA_MINIMA) {


    re();
    delay(400);

    pararMotores();
    delay(100);

    virarDireita();
    delay(500);
  }

  else if (distanciaCentro < DISTANCIA_MINIMA) {

    if (distanciaEsq > distanciaDir) {
      virarEsquerda();
      delay(350);
    } else {
      virarDireita();
      delay(350);
    }
  }

  else if (distanciaEsq < DISTANCIA_MINIMA) {

    // Obstáculo à esquerda
    virarDireita();
    delay(250);
  }

  else if (distanciaDir < DISTANCIA_MINIMA) {

    // Obstáculo à direita
    virarEsquerda();
    delay(250);
  }

  else {

    // Caminho livre
    frente();
  }

  delay(50);
}

// =====================================
// FUNÇÃO PARA MEDIR DISTÂNCIA
// =====================================

float medirDistancia(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duracao = pulseIn(echo, HIGH, 25000);

  if (duracao == 0) {
    return 999;
  }

  return duracao * 0.0343 / 2.0;
}

// =====================================
// CONTROLE DOS MOTORES
// =====================================

void frente() {
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);

  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, LOW);
}

void re() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);

  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, HIGH);
}

void virarDireita() {
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);

  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, LOW);
}

void virarEsquerda() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);

  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, LOW);
}

void pararMotores() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);

  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, LOW);
}

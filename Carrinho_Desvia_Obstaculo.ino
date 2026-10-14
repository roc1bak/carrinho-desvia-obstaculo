#define MOTOR_A_IN1 21
#define MOTOR_A_IN2 18
#define MOTOR_B_IN1 32
#define MOTOR_B_IN2 33
void setup() {

  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);

  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);


}

void loop() {
   // Dois motores para frente
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN1,HIGH);
  digitalWrite(MOTOR_B_IN2,LOW);
}

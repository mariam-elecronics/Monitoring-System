const int gasSensor = A0;
const int buzzer = 2;
const int motor = 3;

int gasValue;
int gasLimit = 500;

bool manualActivate = false;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(motor, LOW);

  Serial.begin(9600);
}

void loop() {

  gasValue = analogRead(gasSensor);

  Serial.println(gasValue);

  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command == '1') {
      manualActivate = true;
    }

    if (command == '0') {
      manualActivate = false;
    }
  }

  if (gasValue >= gasLimit || manualActivate == true) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
  }

  delay(200);
}
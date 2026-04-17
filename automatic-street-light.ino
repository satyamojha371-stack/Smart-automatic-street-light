// Pin Definitions
int LDR = A0;

int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
int IR4 = 5;

int LED1 = 6;
int LED2 = 9;
int LED3 = 10;
int LED4 = 11;

// Brightness levels
int dimLight = 60;
int fullLight = 255;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(LDR);

  // Night condition
  if (ldrValue < 600) {

    int sensor1 = digitalRead(IR1);
    int sensor2 = digitalRead(IR2);
    int sensor3 = digitalRead(IR3);
    int sensor4 = digitalRead(IR4);

    // LED 1
    if (sensor1 == LOW)
      analogWrite(LED1, fullLight);
    else
      analogWrite(LED1, dimLight);

    // LED 2
    if (sensor2 == LOW)
      analogWrite(LED2, fullLight);
    else
      analogWrite(LED2, dimLight);

    // LED 3
    if (sensor3 == LOW)
      analogWrite(LED3, fullLight);
    else
      analogWrite(LED3, dimLight);

    // LED 4
    if (sensor4 == LOW)
      analogWrite(LED4, fullLight);
    else
      analogWrite(LED4, dimLight);

  } 
  // Day condition
  else {
    analogWrite(LED1, 0);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    analogWrite(LED4, 0);
  }
}

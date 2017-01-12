#define MOTOR 5
#define SLIDE A0
#define BUTTON 3
#define LED 4

boolean isOn = true;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
//  if(digitalRead(BUTTON) == HIGH) { //while button pressed
//    isOn = !isOn; //toggle state
//    while(digitalRead(BUTTON) == HIGH); //dang till lifted
//  }

  isOn = digitalRead(BUTTON) == LOW;
  
  if(isOn) {
    digitalWrite(LED, LOW);
    digitalWrite(MOTOR, HIGH);
    delayMicroseconds(map(analogRead(SLIDE), 0, 1023, 1000, 2000));
    digitalWrite(MOTOR, LOW);
    delayMicroseconds(1000);
  } else {
    digitalWrite(LED, HIGH);
    digitalWrite(MOTOR, LOW);
  }  
}


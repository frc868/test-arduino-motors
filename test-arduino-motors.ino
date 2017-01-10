#include <Victor.h>
#include <VictorQueue.h>

#define MOTOR 0
#define SLIDE 0
#define BUTTON 1

Victor motor(MOTOR);
Victor *victors[1] = {&motor};
VictorQueue queue(1, victors);

boolean isOn = true;

void setup() {
  pinMode(BUTTON, INPUT);
}

void loop() {
  if(digitalRead(BUTTON) == HIGH) {
    isOn = !isOn; //toggle the state
    while(digitalRead(BUTTON) == HIGH); //hang until button is released
  }

  if(isOn) {
    motor.setSpeed(analogRead(SLIDE) / 512 - 1); //gives value -1 to 1
  }

  queue.checkQueue;
}


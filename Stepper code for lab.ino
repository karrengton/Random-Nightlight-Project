#include <Stepper.h> // Include the header file

#define STEPS 32


Stepper stepper(STEPS, 8, 10, 9, 11);
int Pval = 0;
int potVal = 0;
void setup() {
  Serial.begin(9600);
  stepper.setSpeed(1000);
}

void loop() {
potVal = map(analogRead(A0),0,1023,0,2048);
if (potVal>Pval)
  stepper.step(5);
if (potVal<Pval)
  stepper.step(-5);
Pval = potVal;
Serial.println(Pval);
}
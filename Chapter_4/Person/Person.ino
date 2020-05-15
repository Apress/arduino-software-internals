#include "Person.h"

// Declare a class object.
Person me;
Person wife("Alison", "Dunbar");


void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print(me);
    Serial.print(" + ");
    Serial.println(wife);
    delay(1000);
}

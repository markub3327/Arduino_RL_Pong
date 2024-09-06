#include <Arduino.h>
#include "environment.h"

Environment env;

void setup() {
    // Init serial link
    Serial.begin(9600);
}

void loop() {
    env.run();
    delay(10);
}

#include "cpu.h"

void setup() {
    
}

void loop() {
    // delay to make sure everything is set up
    delay(2000);
    
    cpu_t* cpu = cpu_create(32);
}
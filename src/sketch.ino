#include <Arduino.h>
#include "nav.h"
#include "sens.h"

float obs_map[MAP_W][MAP_H];
float bb_map[MAP_W][MAP_H];

DFRobotIRPosition ir;

void setup() {
    Serial.begin(19200);

    // Set up sensors
    ir.begin();

    // Init maps
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
            bb_map[i][j] = 0;
        }
    }

    Serial.println(F("Finished setup"));
}

void loop() {
    unsigned long ts = millis();    // track how long each loop takes
    ir_update(&ir, &obs_map);

    // Pathfind
    std::vector<v2d_s> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);
    //Serial.println(F("Time to run A*:"));
    //Serial.print(millis() - ts, DEC);
    //Serial.println(F("\n\n\n"));
    //Serial.print(F("Free Memory Available: "));
    //Serial.println(getFreeMemory());
    //Serial.println(F("\n\n"));
    //Serial.println(F("Looped"));

    delay(50);
}

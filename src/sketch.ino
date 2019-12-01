#include <Arduino.h>
#include "nav.h"
#include "sens.h"

float obs_map[MAP_W][MAP_H];
float bb_map[MAP_W][MAP_H];

DFRobotIRPosition ir;

void setup() {
    Serial.begin(19200);

    // Init sensors
    ir.begin();
    pinMode(TRIG_PIN_R, OUTPUT);
    pinMode(TRIG_PIN_L, OUTPUT);
    pinMode(ECHO_PIN_R, INPUT);
    pinMode(ECHO_PIN_L, INPUT);

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

    // Update maps
    bool bb_updated = ir_update(&ir, &bb_map);
    bool obs_updated = ult_update(&obs_map);

    // Update route
    if (bb_updated || obs_updated) {
        std::vector<v2d_s> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);
    }

    // Compute and set setpoint
    // TODO compute and set setpoint

    delay(50);
}

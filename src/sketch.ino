#include <Arduino.h>
#include "nav.h"

float obs_map[MAP_W][MAP_H];
float bb_map[MAP_W][MAP_H];

DFRobotIRPosition ir;

void setup() {
    //Serial.begin(9600);
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
    // Update target map
    ir.requestPosition();
    if (ir.available()) {
        for (int i = 0; i < 4; i++) {   // IR camera tracks 4 hottest points
            int px = ir.readX(i);
            int py = ir.readY(i);

            if (px == 1023 && py == 1023) {
                int j = 0;
                //Serial.println(F("No heat source found :("));
                // TODO actually do the projection and figure out our location
            } else {
                Serial.println(F("Found a heat source!"));
            }
        }
    } else {
        Serial.println("Device not available");
    }

    // Pathfind
    unsigned long ts = millis();
    std::vector<v2d_s> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);
    //Serial.println(F("Time to run A*:"));
    //Serial.print(millis() - ts, DEC);
    //Serial.println(F("\n\n\n"));
    //Serial.print(F("Free Memory Available: "));
    //Serial.println(getFreeMemory());
    //Serial.println(F("\n\n"));
    //Serial.println(F("Looped"));

    delay(500);
}

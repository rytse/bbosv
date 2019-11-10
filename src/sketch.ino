#include <Arduino.h>
#include "nav.h"

float obs_map[MAP_W][MAP_H];
float bb_map[MAP_W][MAP_H];

void setup() {
    Serial.begin(9600);

    // Init obstacle map
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
            bb_map[i][j] = 0;
        }
    }
}

void loop() {
    unsigned long ts = millis();
    std::vector<v2d_s> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);
    Serial.println(F("Time to run A*:"));
    Serial.print(millis() - ts, DEC);
    Serial.println(F("\n\n\n"));
    Serial.print(F("Free Memory Available: "));
    Serial.println(freeMemory());
    Serial.println(F("\n\n"));

    delay(1000);
}

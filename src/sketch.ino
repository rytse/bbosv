#include <Arduino.h>
#include <MemoryFree.h>
#include "nav.h"

// static int obs_map[MAP_W][MAP_H];
int obs_map[MAP_W][MAP_H];

void setup() {
    Serial.begin(9600);

    Serial.println("starting obs_map init");

    // Init obstacle map
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
        }
    }

    // For testing purposes, let's add some stuff to it!
    // for (int i = 10; i < 15; i++) {
    //     for (int j = 10; j < 40; j++) {
    //         obs_map[i][j] = 1;
    //     }
    // }
    // for (int i = 25; i < 30; i++) {
    //     for (int j = 0; j < 30; j++) {
    //         obs_map[i][j] = 1;
    //     }
    // }

    // for (int i = 40; i < 45; i++) {
    //     for (int j = 10; j < 60; j++) {
    //         obs_map[i][j] = 1;
    //     }
    // }

    Serial.println("finished obs_map init");
}

void loop() {
    Serial.println("Starting loop\n");
    unsigned long ts = millis();

    std::vector<v2d> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);

    // Serial.print(millis() - ts, DEC);
    Serial.println("");

    Serial.print("freeMemory()=");
    Serial.println(freeMemory());

    delay(1000);
}

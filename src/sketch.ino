#include <Arduino.h>
#include "nav.h"

//char obs_map[MAP_W][MAP_H];
//char **obs_map;
static char obs_map[MAP_H];

void setup() {
    Serial.begin(9600);

    Serial.println("starting obs_map init");
    obs_map[0] = 0;
/*
    obs_map = malloc(sizeof(char *) * MAP_W);
    for (int i = 0; i < MAP_W; i++) {
        obs_map[i] = malloc(sizeof(char) * MAP_H);
    }
    */

    //Serial.print(obs_map[0][0], DEC);

    // Init obstacle map
    /*
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            Serial.print(j, DEC);
            //obs_map[i][j] = 0;
        }
    }
    */
    Serial.println("finished obs_map init");

    /*

    // For testing purposes, let's add some stuff to it!
    for (int i = 10; i < 15; i++) {
        for (int j = 10; j < 40; j++) {
            obs_map[i][j] = 1;
        }
    }
    for (int i = 25; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            obs_map[i][j] = 1;
        }
    }

    for (int i = 40; i < 45; i++) {
        for (int j = 10; j < 60; j++) {
            obs_map[i][j] = 1;
        }
    }
    */
}

void loop() {
    /*
    unsigned long ts = millis();
    std::vector<v2d> route = a_star(5, 5, MAP_W - 10, MAP_H - 10, &obs_map);
   // Serial.print(millis() - ts, DEC);
   */
    Serial.println("test");
    Serial.print(millis(), DEC);
    Serial.println("");
    delay(1000);
}

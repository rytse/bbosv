#include "sens.h"

bool ir_update(DFRobotIRPosition *ir, float (*bb_map)[MAP_W][MAP_H]) {
    ir->requestPosition();
    if (ir->available()) {
        for (int i = 0; i < 4; i++) {   // IR camera tracks 4 hottest points
            int px = ir->readX(i);
            int py = ir->readY(i);

            if (!(px == 1023 && py == 1023)) {
                Serial.println(F("Found a heat source!"));
                // TODO update bb_map
                return true;
            }
        }
    } else {
        return false;
    }
}

bool ult_update(float (*obs_map)[MAP_W][MAP_H]) {
    // TX waveform
    digitalWrite(TRIG_PIN_R, LOW); 
    digitalWrite(TRIG_PIN_L, LOW); 
    delayMicroseconds(2); 
    digitalWrite(TRIG_PIN_R, HIGH);
    digitalWrite(TRIG_PIN_L, HIGH);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_R, LOW);
    digitalWrite(TRIG_PIN_L, LOW);

    // RX waveform
    long dur_r = pulseIn(ECHO_PIN_R, HIGH); // TODO figure out if we really need long
    long dur_l = pulseIn(ECHO_PIN_L, HIGH);
    
    // Calculate ToF
    int dist_r = SOUND_SPEED * (dur_r / 2); // TODO figure out if we can really use int
    int dist_l = SOUND_SPEED * (dur_l / 2);

    // If there are valid returns, update map
    if (dist_r < MAX_ECHO_DIST && dist_r > MIN_ECHO_DIST) {
        Serial.print(F("Right Distance: "));
        Serial.print(dist_r, DEC);
        Serial.println(F(""));

        // TODO update obs_map
        return true;
    // TODO handle left side
    } else {
        Serial.println(F("No ultrasonic update"));
        return false;
    }
}

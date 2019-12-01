#include "sens.h"

bool ir_update(DFRobotIRPosition *ir, float (*obs_map)[MAP_W][MAP_H]) {
    ir->requestPosition();
    if (ir->available()) {
        for (int i = 0; i < 4; i++) {   // IR camera tracks 4 hottest points
            int px = ir->readX(i);
            int py = ir->readY(i);

            if (!(px == 1023 && py == 1023)) {
                Serial.println(F("Found a heat source!"));
                return true;
            }
        }
    } else {
        return false;
    }
}

#include "nav.h"

#define TRIG_PIN_R 12
#define ECHO_PIN_R 13
#define TRIG_PIN_L 14   // TODO get correct pin numbers!!
#define ECHO_PIN_L 15

#define SOUND_SPEED 0.0343

#define MAX_ECHO_DIST 38
#define MIN_ECHO_DIST 1

bool ir_update(DFRobotIRPosition *ir, float (*bb_map)[MAP_W][MAP_H]);
bool ult_update(float (*obs_map)[MAP_W][MAP_H]);

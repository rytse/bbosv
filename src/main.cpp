#include "nav.h"
#include <iostream>

int main(void) {
    // Initialize black box and obstacle position estimate matrices
    int obs_map_est[MAP_W][MAP_H];
    int bb_map_est[MAP_W][MAP_H];
    int obs_map_thresh[MAP_W][MAP_H];
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map_est[i][j] = 0;
            obs_map_thresh[i][j] = 0;
            bb_map_est[i][j] = 0;
        }
    }


    while (true) {

        // Read sensors
        // Re-compute maps
        // A* if necessary
        // Compute curvature setpoint
        // Compute motor command
        // Set motor pwm

        if (0) {    // when you finish the mission, break
            break;
        }
    }


    return 0;
}

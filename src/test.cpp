#include "nav.h"
#include <iostream>

/*
static int obs_map[MAP_W][MAP_H];

int main() {
    // int obs_map[MAP_W][MAP_H];
    int m2p[MAP_W][MAP_H];

    // Init obsmap
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
            m2p[i][j] = 0;
        }
    }
    for (int i = 2; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            obs_map[i][j] = 1;
            m2p[i][j] = 1;
        }
    }

    for (int i = 5; i < 6; i++) {
        for (int j = 2; j < MAP_H; j++) {
            obs_map[i][j] = 1;
            m2p[i][j] = 1;
        }
    }

    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            std::cout << obs_map[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";

    std::cout << "Done initializing obs_map" << std::endl;
    std::vector<v2d_s> route = a_star(0, 0, MAP_W - 1, MAP_H - 1, &obs_map);
    std::cout << "Done computing route.\n\nPath:" << std::endl;

    for (int i = 0; i < (int) route.size(); i++) {
        m2p[route[i].x][route[i].y] = 2;
    }

    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            std::cout << m2p[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/

#include "nav.h"
#include <iostream>

//std::vector<v2d> a_star(int, int, int, int, int (*obs_map)[MAP_W][MAP_H]);
std::vector<v2d> a_star(int xs, int ys, int xd, int yd, int (*obs_map)[MAP_W][MAP_H]);

int main() {

    int obs_map[MAP_W][MAP_H];
    int m2p[MAP_W][MAP_H];

    // Init obsmap
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
            m2p[i][j] = 0;
        }
    }
    for (int i = 10; i < MAP_W - 10; i++) {
        obs_map[i][MAP_H / 2] = 1;
        m2p[i][MAP_H / 2] = 1;
    }
    for (int i = 10; i < MAP_H - 10; i++) {
        obs_map[MAP_W / 2][i] = 1;
        m2p[MAP_W / 2][i] = 1;
    }

    std::cout << "Done initializing obs_map" << std::endl;
    std::vector<v2d> route = a_star(5, 5, MAP_W - 10, MAP_H - 10, &obs_map);
    std::cout << "Done computing route.\n\nPath:" << std::endl;

    for (int i = 0; i < (int) route.size(); i++) {
        m2p[route[i].x][route[i].y] = 2;
    }

    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            std::cout << m2p[i][j];
        }
        std::cout << std::endl;
    }


    return 0;
}

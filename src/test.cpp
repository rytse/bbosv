// #include "nav.h"
// #include <iostream>

// static int obs_map[MAP_W][MAP_H];

// #ifndef DEBUG_CONFIG
// int main() {
//     // int obs_map[MAP_W][MAP_H];
//     int m2p[MAP_W][MAP_H];

//     // Init obsmap
//     for (int i = 0; i < MAP_W; i++) {
//         for (int j = 0; j < MAP_H; j++) {
//             obs_map[i][j] = 0;
//             m2p[i][j] = 0;
//         }
//     }
//     for (int i = 10; i < 15; i++) {
//         for (int j = 10; j < 40; j++) {
//             obs_map[i][j] = 1;
//             m2p[i][j] = 1;
//         }
//     }
//     for (int i = 25; i < 30; i++) {
//         for (int j = 0; j < 30; j++) {
//             obs_map[i][j] = 1;
//             m2p[i][j] = 1;
//         }
//     }

//     for (int i = 40; i < 45; i++) {
//         for (int j = 10; j < 60; j++) {
//             obs_map[i][j] = 1;
//             m2p[i][j] = 1;
//         }
//     }

//     // for (int i = 10; i < MAP_H - 10; i++) {
//     //     obs_map[MAP_W / 2][i] = 1;
//     //     m2p[MAP_W / 2][i] = 1;
//     // }


//     std::cout << "Done initializing obs_map" << std::endl;
//     std::vector<v2d> route = a_star(5, 5, MAP_W - 10, MAP_H - 10, &obs_map);
//     std::cout << "Done computing route.\n\nPath:" << std::endl;

//     for (int i = 0; i < (int) route.size(); i++) {
//         m2p[route[i].x][route[i].y] = 2;
//     }

//     for (int i = 0; i < MAP_W; i++) {
//         for (int j = 0; j < MAP_H; j++) {
//             std::cout << m2p[i][j];
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }
// #endif

#ifndef NAV_H
#define NAV_H

#include <Arduino.h>
#include <DFRobotIRPosition.h>
#include <math.h>
#include <stdint.h>
#include <iterator>
#include <vector>
#include <queue>
#include <MemoryFree.h>

// Cells are CELL_SIZE x CELL_SIZE mm
#define CELL_SIZE 20

// Map dimensions are in number of cells
#define MAP_W 20
#define MAP_H 20
#define BOT_W 20
#define BOT_H 15

// Heuristic cost. Diagonal paths cost more so that A* is encouraged to find paths where the OSV
// just drives straight
#define DIAG_COST 15 
#define STRAIGHT_COST 10

struct Node {
    int x;
    int y;
    int level;
    int priority;

    Node(int _x, int _y, int _level, int _priority) {
        x = _x;
        y = _y;
        level = _level;
        priority = _priority;
    }

    Node() {
        x = 0;
        y = 0;
        level = 0;
        priority = 0;
    }
};

/**
 * Type representing a 2D vector with an x and a y component
 */
typedef struct v2d_s {
    int x;
    int y;

    v2d_s(int _x, int _y) {
        x = _x;
        y = _y;
    }
} v2d_s;

uint8_t est_cost(uint8_t, uint8_t, uint8_t, uint8_t);
bool operator<(const Node &, const Node &);
std::vector<v2d_s> a_star(uint8_t, uint8_t, uint8_t, uint8_t, const float (*obs_map)[MAP_W][MAP_H]);

#endif  /* NAV_H */

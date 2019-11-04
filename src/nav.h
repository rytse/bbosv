#ifndef NAV_H
#define NAV_H

#include <Arduino.h>
//#include <pnew.cpp>
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

//extern int obs_map[MAP_W][MAP_H];

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
struct v2d {
    int x;
    int y;

    v2d(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

int est_cost(int, int, int, int);
bool operator<(const Node &, const Node &);
std::vector<v2d> a_star(int, int, int, int, const int (*obs_map)[MAP_W][MAP_H]);

#endif  /* NAV_H */

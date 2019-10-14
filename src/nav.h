#include <vector>

// Cells are CELL_SIZE x CELL_SIZE mm
#define CELL_SIZE 20

// Map dimensions are in number of cells
#define MAP_W 60
#define MAP_H 60
#define BOT_W 20
#define BOT_H 15

// Heuristic cost. Diagonal paths cost more so that A* is encouraged to find paths where the OSV
// just drives straight
#define DIAG_COST 15
#define STRAIGHT_COST 10

int obs_map[MAP_W][MAP_H];

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
};

struct Coord {
    int x;
    int y;

    Coord(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

int est_cost(int, int, int, int);
bool operator<(const Node &, const Node &);
std::vector<Coord> a_star(int, int, int, int);

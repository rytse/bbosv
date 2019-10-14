// #include "Enes100.h"
// #include "Tank.h"

#include "nav.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

int est_cost(int xc, int yc, int xd, int yd) {
    return (xc - xd) * (xc - xd) + (yc - yd) * (yc - yd);
}

// Define node comparison to be the comparison of their
// priorities
bool operator<(const Node &a, const Node &b) {
    return a.priority > b.priority;
}

std::vector<Coord> a_star(int xs, int ys, int xd, int yd) {
    int open_map[MAP_W][MAP_H];
    int closed_map[MAP_W][MAP_H];
    int route_map[MAP_W][MAP_H][2];	// hold the parent node of each vertex

    std::priority_queue<Node> pq[2]; // priority queue of processed and unprocessed vertices
    int pqi = 0;	// priority queue index

    // Init map to 0
    for (int x = 0; x < MAP_W; x++) {
        for (int y = 0; y < MAP_H; y++) {
            closed_map[x][y] = 0;
            open_map[x][y] = 0;
            route_map[x][y][0] = -1;
            route_map[x][y][1] = -1;
        }
    }

    // Set up and declare the "past" and "next nodes" and add the past/current node to the
    // priority queue and open map
    Node *n0 = new Node(xs, ys, 0, est_cost(xs, ys, xd, yd));
    pq[pqi].push(*n0);
    open_map[n0->x][n0->y] = n0->priority;

    // Explore the graph, starting with the top priority node
    while (!pq[pqi].empty()) {
        n0 = new Node(pq[pqi].top().x, pq[pqi].top().y,
                      pq[pqi].top().level,
                      pq[pqi].top().priority);

        // Set past node as "explored"
        pq[pqi].pop();
        open_map[n0->x][n0->y] = 0;
        closed_map[n0->x][n0->y] = 1;

        // Check if done, and if so, retrace the path
        if (n0->x == xd && n0->y == yd) {
            int x = xd;
            int y = yd;
            std::vector<Coord> path_s;

            // Trace the direction map
            while (x != xs || y != ys) {
                path_s.push_back(Coord(x, y));
                x += route_map[x][y][0];
                y += route_map[x][y][1];
            }

            return path_s;
        }

        // Explore child nodes
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }

                int xdx = n0->x + i - 1;
                int ydy = n0->y + j - 1;

                if (xdx < 0 || xdx > MAP_W - 1 || ydy < 0 || ydy > MAP_H - 1 ||
                        obs_map[xdx][ydy] == 1 || closed_map[xdx][ydy] == 1) {
                    continue;
                }

                Node *m0 = new Node(xdx, ydy, n0->level, n0->priority);
                if (i - 1 != 0 && j - 1 != 0) { // prioritize non bendy bendy paths
                    m0->level += DIAG_COST;
                } else {
                    m0->level += STRAIGHT_COST;
                }
                m0->priority = m0->level + est_cost(m0->x, m0->y, xd, yd);

                // If it isn't in the open map, yet, add it
                if (open_map[m0->x][m0->y] == 0) {
                    open_map[m0->x][m0->y] = m0->priority;
                    pq[pqi].push(*m0);

                    route_map[m0->x][m0->y][0] = -(i - 1);
                    route_map[m0->x][m0->y][1] = -(j - 1);
                } else if (open_map[m0->x][m0->y] > m0->priority) {
                    open_map[m0->x][m0->y] = m0->priority;

                    route_map[m0->x][m0->y][0] = -(i - 1);
                    route_map[m0->x][m0->y][1] = -(j - 1);

                    while (!(pq[pqi].top().x == m0->x && pq[pqi].top().y == m0->y)) {
                        pq[1 - pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pq[pqi].pop();

                    if (pq[pqi].size() > pq[1 - pqi].size()) {
                        pqi = 1 - pqi;
                    }

                    while (!pq[pqi].empty()) {
                        pq[1 - pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pqi = 1 - pqi;
                    pq[pqi].push(*m0);
                } else {
                    delete m0;
                }
            }
        }

        delete n0;
    }

    std::cout << "Zero length path!" << std::endl;
    std::vector<Coord> frep;
    return frep;
}


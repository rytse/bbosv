#include "nav.h"

uint8_t est_cost(uint8_t xc, uint8_t yc, uint8_t xd, uint8_t yd) {
    return pow((xc - xd) * (xc - xd) + (yc - yd) * (yc - yd), 4);
}

// Define node comparison to be the comparison of their
// priorities
bool operator<(const Node &a, const Node &b) {
    return a.priority > b.priority;
}

std::vector<v2d_s> a_star(uint8_t xs, uint8_t ys, uint8_t xd, uint8_t yd,
        const float (*obs_map)[MAP_W][MAP_H]) {

    uint8_t open_map[MAP_W][MAP_H];
    //std::bitset<MAP_W> closed_map[MAP_H];
    uint8_t closed_map[MAP_W][MAP_H];
    int8_t route_map[MAP_W][MAP_H][2];	// hold the parent node of each vertex

    std::priority_queue<Node> pq[2]; // priority queue of processed and unprocessed vertices
    uint8_t pqi = 0;	// priority queue index

    // Init map to 0
    for (uint8_t x = 0; x < MAP_W; x++) {
        for (uint8_t y = 0; y < MAP_H; y++) {
            closed_map[x][y] = 0;
            open_map[x][y] = 0;
            route_map[x][y][0] = -1;
            route_map[x][y][1] = -1;
        }
    }

    // Set up and declare the "past" and "next nodes" and add the past/current node to the
    // priority queue and open map
    Node n0 = Node(xs, ys, 0, est_cost(xs, ys, xd, yd));
    pq[pqi].push(n0);
    open_map[n0.x][n0.y] = n0.priority;

    // Explore the graph, starting with the top priority node
    while (!pq[pqi].empty()) {
        n0 = Node(pq[pqi].top().x, pq[pqi].top().y,
                      pq[pqi].top().level,
                      pq[pqi].top().priority);

        // Set past node as "explored"
        pq[pqi].pop();

        open_map[n0.x][n0.y] = 0;
        closed_map[n0.x][n0.y] = 1;
        
        // Check if done, and if so, retrace the path
        if (n0.x == xd && n0.y == yd) {
            uint8_t x = xd;
            uint8_t y = yd;
            std::vector<v2d_s> path_s;

            // Trace the direction map
            while (x != xs || y != ys) {
                path_s.push_back(v2d_s(x, y));
                x += route_map[x][y][0];
                y += route_map[x][y][1];
            }

            return path_s;
        }

        // Explore child nodes
        for (uint8_t i = 0; i < 3; i++) {
            for (uint8_t j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }

                int xdx = n0.x + i - 1;
                int ydy = n0.y + j - 1;

                if (xdx < 0 || xdx > MAP_W - 1 || ydy < 0 || ydy > MAP_H - 1 ||
                        (*obs_map)[xdx][ydy] == 1 || closed_map[xdx][ydy] == 1) {
                    continue;
                }

                Node m0 = Node(xdx, ydy, n0.level, n0.priority);
                if (i - 1 != 0 && j - 1 != 0) { // prioritize non bendy bendy paths
                    m0.level += DIAG_COST;
                } else {
                    m0.level += STRAIGHT_COST;
                }
                m0.priority = m0.level + est_cost(m0.x, m0.y, xd, yd);

                // If it isn't in the open map, yet, add it
                if (open_map[m0.x][m0.y] == 0) {
                    open_map[m0.x][m0.y] = m0.priority;
                    pq[pqi].push(m0);

                    route_map[m0.x][m0.y][0] = -(i - 1);
                    route_map[m0.x][m0.y][1] = -(j - 1);
                } else if (open_map[m0.x][m0.y] > m0.priority) {
                    open_map[m0.x][m0.y] = m0.priority;

                    route_map[m0.x][m0.y][0] = -(i - 1);
                    route_map[m0.x][m0.y][1] = -(j - 1);

                    while (!(pq[pqi].top().x == m0.x && pq[pqi].top().y == m0.y)) {
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
                    pq[pqi].push(m0);
                } else {
                    //delete m0;
                }
                //delete m0;
            }
        }

        
        //delete n0;
    }

    for (uint8_t i = 0; i < 2; i++) {
        while (!pq[i].empty()) {
            pq[i].pop();
        }
    }

    //delete n0;

    std::vector<v2d_s> frep;
    return frep;
}

#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <utility>
using namespace std;

/**
 * Class to solve the problem of connecting all points with the minimum cost.
 * This is achieved using Prim’s algorithm with a priority queue (min-heap).
 */
class Solution {
public:
    /**
     * Function to find the minimum cost to connect all points on a 2D plane.
     * The cost between two points is the Manhattan distance between them.
     *
     * @param points A vector of coordinates representing points on a 2D grid.
     * @return The minimum total cost to connect all points.
     */
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Build an adjacency list with Manhattan distances between all pairs
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                mp[i].push_back({j, dis});
                mp[j].push_back({i, dis});
            }
        }

        using p = pair<int, int>; // {cost, node}
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0}); // Start with point 0 at cost 0

        vector<bool> inmst(n, false); // Track inclusion in MST
        int cost = 0;

        // Prim's algorithm using min-heap
        while (!pq.empty()) {
            auto [currCost, u] = pq.top();
            pq.pop();

            // Skip if node already included in MST
            if (inmst[u]) continue;

            inmst[u] = true;
            cost += currCost;

            // Add all neighbors of current node
            for (auto& [v, w] : mp[u]) {
                if (!inmst[v]) {
                    pq.push({w, v});
                }
            }
        }

        return cost;
    }
};

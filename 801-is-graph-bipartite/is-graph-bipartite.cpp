#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>> adj, int curr, vector<int>& color,
                           int currColor) {
        color[curr] = currColor; // Color the current node

        // Visit all adjacent vertices
        for (int& v : adj[curr]) {
            // If the adjacent vertex has the same color → not bipartite
            if (color[v] == color[curr])
                return false;

            // If not colored yet, recursively color it with opposite color
            if (color[v] == -1) {
                if (!checkBipartiteDFS(adj, v, color, 1 - currColor))
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> color(V, -1); // -1 means uncolored

        // Try to color each component
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!checkBipartiteDFS(adj, i, color, 0)) // Start with color 0
                    return false;
            }
        }
        return true;
    }
};

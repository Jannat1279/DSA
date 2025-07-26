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


/*
Example:
graph = {
    {1, 3},   // Node 0 is connected to 1 and 3
    {0, 2},   // Node 1 is connected to 0 and 2
    {1, 3},   // Node 2 is connected to 1 and 3
    {0, 2}    // Node 3 is connected to 0 and 2
};

➤ At Node 0:
Color = 0
Neighbors: 1, 3
color[0] = 0

➤ Move to Node 1:
Not colored, so assign 1 (opposite of 0)
color[1] = 1
Neighbors: 0, 2
0 is already colored 0 — ✅ OK (different)
2 is unvisited → go deeper

➤ Move to Node 2:
Assign color 0
color[2] = 0
Neighbors: 1, 3
1 is colored 1 — ✅ OK
3 is unvisited → go deeper

➤ Move to Node 3:
Assign color 1
color[3] = 1
Neighbors: 0, 2
0 is colored 0 — ✅ OK
2 is colored 0 — ✅ OK

Step 4: All nodes visited with proper alternating colors
No adjacent nodes have the same color

So the graph is bipartite


*/

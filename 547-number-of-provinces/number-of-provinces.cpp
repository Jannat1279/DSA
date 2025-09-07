class Solution {
public:
    int n; // number of nodes (cities)
    
    // Depth First Search function to visit all connected cities
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true; // mark current city as visited
        
        // Visit all neighbours of city u
        for(int v = 0; v < n; v++) {
            // If there is a road between u and v, and v is not visited yet
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited); // recursively visit v
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size(); // total number of cities
        
        vector<bool> visited(n, false); // to keep track of visited cities
        int count = 0; // number of provinces
        
        // Loop through all cities
        for(int i = 0; i<n; i++) {
            if(!visited[i]) { 
                // Found a new province (group of connected cities)
                count++;
                dfs(isConnected, i, visited); 
                // Mark all cities in this province as visited
            }
        }
        
        return count; // return total provinces
    }
};

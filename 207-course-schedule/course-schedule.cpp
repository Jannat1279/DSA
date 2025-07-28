class Solution {
public:
    // Helper function to perform topological sort using Kahn's Algorithm
    // Returns true if it's possible to process all nodes (i.e., no cycle exists)
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> que;  // Queue for nodes with indegree 0 (no prerequisites)
        int count = 0;   // Counter for how many nodes we've processed

        // Add all nodes with 0 indegree to the queue initially
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        // Start processing nodes
        while (!que.empty()) {
            int u = que.front(); // Get the current node
            que.pop();

            // Decrease indegree of all its adjacent (dependent) nodes
            for (int& v : adj[u]) {
                indegree[v]--;

                // If indegree becomes 0, it means it can now be processed
                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        // If we've processed all nodes, return true
        // Otherwise, a cycle exists, and it's not possible to finish all tasks
        return count == n;
    }

    // Main function to determine if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;       // Adjacency list for graph
        vector<int> indegree(numCourses, 0);       // Store indegree of each node

        // Build the graph and indegree array
        for (auto& vec : prerequisites) {
            int a = vec[0]; // Course to take
            int b = vec[1]; // Prerequisite course

            // Add edge: b → a (to take course a, you need to complete b first)
            adj[b].push_back(a);
            indegree[a]++; // Increment indegree of course a
        }

        // Use Kahn's algorithm to check for cycle
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

/*
Example:
numCourses = 4
prerequisites = {{1, 0}, {2, 1}, {3, 2}}
0 → 1
1 → 2
2 → 3

indegree = [0, 0, 0, 0]

// After processing [1, 0] → indegree[1]++
indegree = [0, 1, 0, 0]

// After [2, 1] → indegree[2]++
indegree = [0, 1, 1, 0]

// After [3, 2] → indegree[3]++
indegree = [0, 1, 1, 1]

🔸 Step 2: Initialize queue with courses having indegree 0
queue = [0]    // Only course 0 has no prerequisites
count = 1      // We can start course 0

🔸 Step 3: BFS Traversal (Kahn's Algorithm)
🟢 Process 0:
0 → 1: decrement indegree[1] from 1 to 0
indegree = [0, 0, 1, 1]
Add 1 to queue, count++
queue = [1]
count = 2

🟢 Process 1:
1 → 2: decrement indegree[2] from 1 to 0
indegree = [0, 0, 0, 1]
Add 2 to queue, count++
queue = [2]
count = 3

🟢 Process 2:
2 → 3: decrement indegree[3] from 1 to 0
indegree = [0, 0, 0, 0]
Add 3 to queue, count++
queue = [3]
count = 4

🟢 Process 3:
No neighbors → done
Queue is empty now.

🔸 Final Check:
count = 4 == numCourses = 4
→ return true
*/

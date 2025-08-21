class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char, int> mp;

        // Count frequency of each task
        for(char &ch : tasks) {
            mp[ch]++;
        }

        // Max-heap to always pick the task with the highest remaining frequency
        priority_queue<int> pq;

        // Push all task frequencies into the max-heap
        for(auto &it : mp) {
            pq.push(it.second);
        }

        int time = 0;  // total time taken

        // Keep scheduling until all tasks are done
        while(!pq.empty()) {
            vector<int> temp;  // stores remaining counts of tasks after processing one round

            // Try to execute (p+1) tasks in each round
            for(int i = 1; i <= p+1; i++) {
                if(!pq.empty()) {
                    // Process the most frequent task
                    temp.push_back(pq.top() - 1); // reduce its count by 1
                    pq.pop();
                }
            }

            // Push remaining (unfinished) tasks back into the heap
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }

            // If heap is empty, all tasks are done → just add the number of tasks executed
            if(pq.empty())
                time += temp.size();
            else
                // Otherwise, a full cycle of (p+1) time units has passed
                time += (p+1);
        }

        return time;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Create a count array of size n+1 (1-based indexing)
        // count[i] = net trust score of person i
        // - Decrease by 1 for each person they trust (outgoing trust)
        // - Increase by 1 for each person who trusts them (incoming trust)
        vector<int> count(n + 1);

        // Iterate through the trust relationships
        for (vector<int>& vec : trust) {
            // vec[0] trusts vec[1]
            count[vec[0]]--; // trusting someone → not judge
            count[vec[1]]++; // being trusted by someone → maybe judge
        }

        // Look for a person with trust score == n - 1
        // They are trusted by everyone else, but trust no one
        for (int i = 1; i <= n; i++) {
            if (count[i] == n - 1) {
                return i; // This person is the judge
            }
        }

        // If no judge found, return -1
        return -1;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Using vector as a stack
        vector<int> st;
        for (int& a : asteroids) {
            while (!st.empty() && a < 0 && st.back() > 0) {
                int sum = a + st.back();
                if (sum < 0) {
                    // a is greater
                    st.pop_back();
                } else if (sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop_back();
                    a = 0;
                    break;
                }
            }
            if (a != 0) {
                st.push_back(a);
            }
        }
        return st;
    }
};
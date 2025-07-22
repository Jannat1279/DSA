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

/*
Example:
vector<int> asteroids = {5, 10, -5};

💥 Meaning of each value:
Positive → asteroid is moving right
Negative → asteroid is moving left

📦 Step-by-step execution:
Initial stack (st): []

1. a = 5
No collision (stack empty).
Push to stack → st = [5]

2. a = 10
No collision (10 > 0, top of stack is also > 0).
Push to stack → st = [5, 10]

3. a = -5
Check collision: -5 is going left, 10 on top is going right → collision!
sum = -5 + 10 = 5 → 10 is larger.
So a = 0 (destroyed), don't push anything.

✅ Final result:
st = [5, 10]
So, the return value will be:
[5, 10]
*/

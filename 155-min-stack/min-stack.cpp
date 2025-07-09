class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        } else {
            min = std::min(st.top().second, x);
        }
        st.push({x, min});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/*
Example:
MinStack s;

s.push(5);           // Stack: [(5, 5)]              → current min = 5
s.push(3);           // Stack: [(5, 5), (3, 3)]      → current min = 3
s.push(7);           // Stack: [(5, 5), (3, 3), (7, 3)] → current min = 3
s.push(2);           // Stack: [(5, 5), (3, 3), (7, 3), (2, 2)] → current min = 2

s.getMin();          // Returns 2
s.top();             // Returns 2

s.pop();             // Removes (2, 2) → Stack now: [(5, 5), (3, 3), (7, 3)]
s.getMin();          // Returns 3
s.top();             // Returns 7

s.pop();             // Removes (7, 3)
s.getMin();          // Returns 3

s.pop();             // Removes (3, 3)
s.getMin();          // Returns 5

s.pop();             // Removes (5, 5)

*/

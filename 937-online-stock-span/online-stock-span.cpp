class StockSpanner {
public:
    // Stack to store pairs of {price, span}
    // The stack helps maintain a decreasing order of prices
    stack<pair<int, int>> st;

    // Constructor: Initializes the StockSpanner object
    StockSpanner() {}

    // Function to calculate and return the stock span for the given price
    int next(int price) {
        int span = 1; // Span starts at 1 for the current day

        // While stack is not empty and top price is less than or equal to
        // current price we aggregate the spans since current price is greater
        // than or equal to all those previous prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the lower/equal price
            st.pop(); // Remove it from stack since it is now included
        }

        // Push the current price and its span to the stack
        st.push({price, span});

        // Return the total span for this price
        return span;
    }
};

/*
Example:

StockSpanner ss;
ss.next(100);
ss.next(80);
ss.next(60);
ss.next(70);
ss.next(60);
ss.next(75);
ss.next(85);

We'll track:
The input price
The span returned

Step-by-step:
1. ss.next(100)
Stack is empty → no smaller/equal past prices
Span = 1
Push (100, 1)
✅ Return: 1
📦 Stack: [(100, 1)]

2. ss.next(80)
80 < 100 → can’t pop
Span = 1
Push (80, 1)
✅ Return: 1
📦 Stack: [(100, 1), (80, 1)]

3. ss.next(60)
60 < 80 → can’t pop
Span = 1
Push (60, 1)
✅ Return: 1
📦 Stack: [(100, 1), (80, 1), (60, 1)]

4. ss.next(70)
70 > 60 → pop (60, 1) → span += 1 → span = 2
70 < 80 → stop
Push (70, 2)
✅ Return: 2
📦 Stack: [(100, 1), (80, 1), (70, 2)]

5. ss.next(60)
60 < 70 → can’t pop
Span = 1
Push (60, 1)
✅ Return: 1
📦 Stack: [(100, 1), (80, 1), (70, 2), (60, 1)]

6. ss.next(75)
75 > 60 → pop (60, 1) → span = 2
75 > 70 → pop (70, 2) → span = 4
75 < 80 → stop
Push (75, 4)
✅ Return: 4
📦 Stack: [(100, 1), (80, 1), (75, 4)]

7. ss.next(85)
85 > 75 → pop (75, 4) → span = 5
85 > 80 → pop (80, 1) → span = 6
85 < 100 → stop
Push (85, 6)
✅ Return: 6
📦 Stack: [(100, 1), (85, 6)]

Final Output:
[1, 1, 1, 2, 1, 4, 6]

*/

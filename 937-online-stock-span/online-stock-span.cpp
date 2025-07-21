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

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
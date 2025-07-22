class Solution {
public:
    typedef long long ll;

    // Function to find the Next Smaller to the Left (NSL) for each element
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n); // result[i] stores index of NSL of arr[i]
        stack<int> st;         // stack to store indices (not values)

        for (int i = 0; i < n; i++) {
            // Pop all elements from stack which are >= current element
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            // If stack is empty, no smaller element on the left
            result[i] = st.empty() ? -1 : st.top();

            // Push current index to stack
            st.push(i);
        }

        return result;
    }

    // Function to find the Next Smaller to the Right (NSR) for each element
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n); // result[i] stores index of NSR of arr[i]
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop all elements from stack which are > current element
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack is empty, no smaller element on the right
            result[i] = st.empty() ? n : st.top();

            // Push current index to stack
            st.push(i);
        }

        return result;
    }

    // Function to compute the sum of minimums of all subarrays
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n); // Nearest Smaller to Left
        vector<int> NSR = getNSR(arr, n); // Nearest Smaller to Right

        ll sum = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            ll left = i - NSL[i]; // Number of elements to the left where arr[i]
                                  // is the min
            ll right =
                NSR[i] -
                i; // Number of elements to the right where arr[i] is the min

            // Total number of subarrays where arr[i] is the minimum:
            // left choices to start * right choices to end
            ll totalWays = left * right;

            // Contribution of arr[i] in all such subarrays
            ll contribution = arr[i] * totalWays;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};

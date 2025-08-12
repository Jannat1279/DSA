class KthLargest {
public:
    int K; // The K value — we want to find the K-th largest number
    // Min-heap to store the largest K elements
    // The smallest element in this heap (top) will be the K-th largest overall
    priority_queue<int, vector<int>, greater<int>> pq;

    // Constructor: takes k and an initial list of numbers
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int& num : nums) {
            pq.push(num);         // Add each number to the heap
            if (pq.size() > k)    // If heap has more than K elements
                pq.pop();         // Remove the smallest to keep only the largest K
        }
    }
    
    // Add a new number and return the current K-th largest number
    int add(int val) {
        pq.push(val);             // Add the new number
        if (pq.size() > K)        // If heap has more than K elements
            pq.pop();             // Remove smallest to keep size K
        return pq.top();          // Top of the min-heap = K-th largest element
    }
};

/*
Example:
int k = 3;
vector<int> nums = {4, 5, 8, 2};
KthLargest obj(k, nums);

Step-by-step (Constructor):

Add 4 → heap = [4]
Add 5 → heap = [4, 5]
Add 8 → heap = [4, 5, 8]
Add 2 → heap = [2, 5, 8] → size > 3 → remove 2 → heap = [4, 5, 8]
Now pq.top() = 4, which is the 3rd largest.

Operations:

obj.add(3); // heap = [3, 5, 8] → remove 3 → top = 4
obj.add(5); // heap = [4, 5, 8] → top = 5
obj.add(10); // heap = [5, 8, 10] → top = 5
obj.add(9); // heap = [8, 9, 10] → top = 8
obj.add(4); // heap = [8, 9, 10] → top = 8
*/

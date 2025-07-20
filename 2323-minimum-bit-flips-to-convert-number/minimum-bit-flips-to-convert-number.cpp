class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR of start and goal gives a number where bits are 1 if start and
        // goal differ at that bit position
        int ans = start ^ goal;

        int cnt = 0; // Counter to count the number of differing bits (bit flips
                     // required)

        // Iterate through the first 31 bits (sufficient for most integer
        // ranges)
        for (int i = 0; i < 31; i++) {
            // Check if the i-th bit is set in the XOR result
            if (ans & (1 << i)) {
                cnt++; // If it is, that means a bit flip is needed at this
                       // position
            }
        }

        // Return total number of differing bits
        return cnt;
    }
};

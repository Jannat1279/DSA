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

/*
Example:
start = 10;   // Binary: 1010  
goal  = 7;    // Binary: 0111

Step 1: XOR the numbers
start ^ goal = 1010 ^ 0111 = 1101 (which is 13 in decimal)
This result (1101) shows where the bits differ:

Bit 0 (rightmost): 0 vs 1 → different → flip
Bit 1: 1 vs 1 → same → no flip
Bit 2: 0 vs 1 → different → flip
Bit 3: 1 vs 0 → different → flip

So there are 3 differing bits.

Step 2: Count the number of 1s in the result
Binary 1101 → has 3 ones → 3 bit flips required.
*/

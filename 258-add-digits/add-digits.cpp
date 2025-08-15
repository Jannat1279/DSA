class Solution {
public:
   
    int addDigits(int num) {
        // If num is 0, the sum of its digits is 0
        if (num == 0)
            return 0;

        // Digital root property:
        // The sum of digits repeats every multiple of 9.
        // If num is divisible by 9 (and not zero), its digital root is 9
        if (num % 9 == 0)
            return 9;

        // Otherwise, the digital root is simply num % 9
        return num % 9;
    }
};

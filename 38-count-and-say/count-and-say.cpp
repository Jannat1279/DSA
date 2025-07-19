class Solution {
public:
    string countAndSay(int n) {
        // Base case: the first term of the sequence is always "1"
        if (n == 1)
            return "1";

        // Recursively get the (n-1)th term
        string say = countAndSay(n - 1);

        // This will store the final result for the nth term
        string result = "";

        // Loop through the string we got from the previous step
        for (int i = 0; i < say.length(); i++) {
            int count = 1;    // Count of the current digit
            char ch = say[i]; // The current digit we are processing

            // Count how many times the current digit repeats consecutively
            while (i < say.length() - 1 && say[i] == say[i + 1]) {
                count++;
                i++; // Move to the next character
            }

            // Append the count followed by the digit itself to the result
            result += to_string(count) + string(1, ch);
        }

        // Return the final constructed term for the current n
        return result;
    }
};

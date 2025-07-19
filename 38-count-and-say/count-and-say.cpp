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

/*
Example:
n = 5
🔁 Sequence Construction Step-by-Step:
We’ll build each level recursively:

🧩 n = 1
Base case → return "1"

🧩 n = 2
Previous = "1"
Description: one 1 → "11"

🧩 n = 3
Previous = "11"
Description: two 1s → "21"

🧩 n = 4
Previous = "21"
Description:
one 2
one 1
→ "1211"

🧩 n = 5
Previous = "1211"
Breakdown:
one 1
one 2
two 1s
→ "111221"

✅ Output:
"111221"
*/

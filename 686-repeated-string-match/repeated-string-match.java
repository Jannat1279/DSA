class Solution {
     public int repeatedStringMatch(String A, String B) {
    int count = 1;  // Keeps track of how many times A is repeated
    StringBuilder sb = new StringBuilder(A);  // Start with A once in the string builder

    // Keep appending A to itself until the length of the result is at least the length of B
    while (sb.length() < B.length()) {
        sb.append(A);  // Append A again
        count++;       // Increase the repeat count
    }

    // Check if the current repeated string contains B as a substring
    if (sb.toString().contains(B)) {
        return count;  // If yes, return the count of repetitions
    }

    // Append one more A and check again (to cover overlapping cases)
    if (sb.append(A).toString().contains(B)) {
        return count + 1;  // If B is found now, return count + 1
    }

    // If B is still not a substring, return -1 indicating it's not possible
    return -1;
}

}
/*
Example:
💻 Input:
A = "abcd";
B = "cdabcdab";

🔄 Step-by-Step Execution:
Initial Setup:
count = 1;
sb = "abcd";
First while loop check:
sb.length() = 4
B.length() = 8 → sb.length() < B.length() → true

➡ Append A → sb = "abcdabcd"
➡ count = 2

Second while loop check:
sb.length() = 8
B.length() = 8 → sb.length() < B.length() → false

Exit the loop.

First contains check:
sb = "abcdabcd"
Does it contain "cdabcdab"? ❌ No

Append one more A:
sb = "abcdabcd" + "abcd" = "abcdabcdabcd"
Now check if it contains "cdabcdab" ✅ Yes

✅ Final Result:
return count + 1 = 2 + 1 = 3
*/

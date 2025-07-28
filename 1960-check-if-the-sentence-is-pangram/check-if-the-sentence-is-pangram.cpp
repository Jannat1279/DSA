class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Create a frequency array for 26 lowercase letters
        vector<int> arr(26, 0);
        int count = 0; // To count how many unique letters we've seen

        for (char& ch : sentence) {
            int index = ch - 'a'; // Convert character to index (0 for 'a', ..., 25 for 'z')

            // If this character is encountered for the first time
            if (arr[index] == 0) {
                arr[index]++;  // Mark it as seen
                count++;       // Increment unique character count
            }
        }

        // If all 26 letters are seen at least once, return true
        return (count == 26);
    }
};

/*
Example:
Input: "leetcode"
Letters in "leetcode": l, e, t, c, o, d

Total unique letters = 6
count = 6 < 26
Output: false
*/

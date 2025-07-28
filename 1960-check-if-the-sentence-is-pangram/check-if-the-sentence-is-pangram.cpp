class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Assign 26 alphabets with 0 frequency
        vector<int> arr(26,0);
        int count=0;
        for(char& ch:sentence){
            int index=ch-'a';
            if(arr[index]==0){
                arr[index]++;
                count++;
            }
        }
        return (count==26);  // Represents all the alphabets
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

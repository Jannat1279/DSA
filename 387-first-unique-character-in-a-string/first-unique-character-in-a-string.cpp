// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int j=0;
//         for(int i=0;i<s.length();i++){
//             bool check=true;
//             for(int j=0;j<s.length();j++){
//                 if(i==j)continue;
//                 if(s[i]==s[j]){
//                     check=false;
//                     break;
//                 }
//             }
//             if(check)return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};   // Array to store frequency of each character (for 26 lowercase letters)

        // Step 1: Count frequency of each character in the string
        for (char &ch : s) {
            arr[ch - 'a']++;  
            // 'ch - 'a'' gives index between 0-25 for each lowercase letter
            // Example: 'a' → 0, 'b' → 1, ..., 'z' → 25
        }

        // Step 2: Find the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (arr[s[i] - 'a'] == 1) {
                return i;   // Return index of the first non-repeating character
            }
        }

        // Step 3: If no unique character found
        return -1;
    }
};

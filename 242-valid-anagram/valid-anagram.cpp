class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};

/*
Example:
s = "listen"
t = "silent"
🧠 Step-by-step Execution:
Step 1: Length Check
if (s.length() != t.length()) return false;
s.length() = 6, t.length() = 6 → ✅ Pass

Step 2: Sort Both Strings
sort(s.begin(), s.end());  // s = "eilnst"
sort(t.begin(), t.end());  // t = "eilnst"

Step 3: Compare Characters One by One
for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) return false;
}
All characters match at each index → ✅ Pass

✅ Final Output:
return true;
*/

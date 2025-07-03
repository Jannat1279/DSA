class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for(int j=0;j<s.length();j++){
            if(s[j]==')')count--;
            if(count!=0)ans.push_back(s[j]);
            if(s[j]=='(')count++;
        }
        return ans;
    }
};
/*
 How It Works : Step-by-step on input "(()())(())"

| Char | count before | Action                  | ans    | count after |
| ---- | ------------ | ----------------------- | ------ | ----------- |
| (    | 0            | skip (count != 0 false) |        | 1           |
| (    | 1            | add '('                 | (      | 2           |
| )    | 2            | add ')'                 | ()     | 1           |
| (    | 1            | add '('                 | ()(    | 2           |
| )    | 2            | add ')'                 | ()()   | 1           |
| )    | 1            | skip (count becomes 0)  | ()()   | 0           |
| (    | 0            | skip                    | ()()   | 1           |
| (    | 1            | add '('                 | ()()(  | 2           |
| )    | 2            | add ')'                 | ()()() | 1           |
| )    | 1            | skip                    | ()()() | 0           |

When you see ')', you're closing a level. If this ')' brings the count back to 0, then it is the outermost closing bracket, and you should not include it in ans.
If you had added ')' to ans before decreasing count, you'd be mistakenly adding the outermost closing parentheses.

Time: O(n) where n is the length of string s
Space: O(n) for storing the answer string

*/

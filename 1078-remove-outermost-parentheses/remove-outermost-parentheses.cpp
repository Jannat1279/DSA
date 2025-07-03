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
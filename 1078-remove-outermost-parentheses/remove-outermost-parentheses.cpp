class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for(char ch:s){
            if(ch==')')count--;
            if(count!=0)ans.push_back(ch);
            if(ch=='(')count++;
        }
        return ans;
    }

   
};
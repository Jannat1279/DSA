#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string x=strs[0],y=strs[n-1],answer="";
        for(int i=0;i<x.size();i++){
            if(x[i]==y[i])answer+=x[i];
            else break;
        }
        return answer;
    }
};

/*
Input: strs = ["flower", "flow", "flight"]
After sorting: ["flight", "flow", "flower"]
x = "flight"
y = "flower"
x[0] = 'f' == y[0] = 'f' → ans = "f"
x[1] = 'l' == y[1] = 'l' → ans = "fl"
x[2] = 'i' != y[2] = 'o' → break
Output : "fl"

*/

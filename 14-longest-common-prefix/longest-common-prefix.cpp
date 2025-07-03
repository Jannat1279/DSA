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
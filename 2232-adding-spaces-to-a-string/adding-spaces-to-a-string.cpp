class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m=s.length();
        int n=spaces.size();
        string result="";

        int j=0;
        for(int i=0;i<m;i++){
            // Finding the index for space
            if(j<n && i==spaces[j]){
                result+=" ";
                j++;
            }
            // Till you don't find the index for space, simply add the character to the result
            result+=s[i];
        }
        return result;
    }
};
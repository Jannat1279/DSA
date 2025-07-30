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

/*
Example:
s = "CodeInCpp"
spaces = {4, 6}

Output:
"Code In Cpp"

Space at index 4 → "Code InCpp"

Space at index 6 → "Code In Cpp"
*/

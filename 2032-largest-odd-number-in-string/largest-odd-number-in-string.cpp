class Solution {
public:
    string largestOddNumber(string num) {
        for(int j=num.length()-1;j>=0;j--){
            if((num[j]-'0')%2!=0){
                // j+1 because 2nd value is not inclusive.
                return num.substr(0,j+1);
            }
        }
        return "";
    }
};
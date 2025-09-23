// time - O(n), space - O(n)

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

/*
Input:  num = "35420"
Check from right to left:

num[4] = '0' → even

num[3] = '2' → even

num[2] = '4' → even

num[1] = '5' → odd!

So return num.substr(0, 2) → "35"
*/

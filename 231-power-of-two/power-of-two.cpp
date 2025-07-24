class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)return true;
        while(n!=0){
            if(n%2!=0)return false;  //odd number
            if(n==2)return true;
            else{
                n=n/2;
            }
        }
        return false;
    }
};

/*
Example:

n = 8
We want to check if 8 is a power of 2.

🔄 Steps:
Check if n == 1 → it's not, move on.
Start loop since n != 0
n = 8 → even → not odd → continue
→ divide by 2 → n = 4

n = 4 → even → continue
→ divide by 2 → n = 2

n = 2 → this is 2, return true

✅ Result: true
Because 8 → 4 → 2 → confirmed power of 2.
*/

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
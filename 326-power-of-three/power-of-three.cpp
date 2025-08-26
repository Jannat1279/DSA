// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n==1)return true;
//         while(n>0){
//             if(n%3!=0)return false;
//             if(n==3)return true;
//             else{
//                 n/=3;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base cases
        if (n == 1) return true;       // 3^0 = 1
        if (n <= 0 || n % 3 != 0) return false;

        // Recursive case
        return isPowerOfThree(n / 3);
    }
};

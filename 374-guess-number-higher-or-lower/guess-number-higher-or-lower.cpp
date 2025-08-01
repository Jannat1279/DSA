class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            int guessRes=guess(mid);
            if(guessRes==0){
                return mid;
            }
            // The number is greater than the pick, move to the LHS 
            else if(guessRes==-1){
                right=mid-1;
            }
            // The number is less than mid, move to the RHS
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};
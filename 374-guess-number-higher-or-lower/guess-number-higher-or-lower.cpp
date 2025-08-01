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
            // The number is less than pick, move to the RHS
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};

/*
Example:
Let's say n = 10, and the number picked is 7.

We'll simulate what happens in your code.

🔍 Step-by-Step Trace:
left = 1, right = 10

🟢 Iteration 1:
mid = 1 + (10 - 1)/2 = 5
guess(5) → returns 1 (5 is lower than 7)
Move to right: left = mid + 1 = 6

🟢 Iteration 2:
mid = 6 + (10 - 6)/2 = 8
guess(8) → returns -1 (8 is higher than 7)
Move to left: right = mid - 1 = 7

🟢 Iteration 3:
mid = 6 + (7 - 6)/2 = 6
guess(6) → returns 1 (6 is lower than 7)
Move to right: left = mid + 1 = 7

🟢 Iteration 4:
mid = 7 + (7 - 7)/2 = 7
guess(7) → returns 0 ✅ found!

✅ Output:
The function returns 7
*/

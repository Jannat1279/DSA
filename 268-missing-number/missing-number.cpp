class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sum will store the summation of the elements present in the array
        // i.e. nums
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }
        // This is the actual sum claculated using math formula.
        int actualSum = (n * (n + 1)) / 2;
        int missingNumber = actualSum - sum;
        return missingNumber;
    }
};
/*
Example:
nums=[3, 0, 1]
for(){
sum=3 //nums[0]
sum=3 //nums[1]
sum=4 //nums[2]
}
actualSum=3(3+1)/2=6

actualSum-sum=6-4=2 (answer)
*/

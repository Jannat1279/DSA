class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
        }
        return (count<=1);
    }
};
// Key point: A rotated and sorted array cannot have more than 1 drop.

/*
Example:
nums = [3,4,5,1,2]

Compare each element with next (circular):
3 < 4 → fine
4 < 5 → fine
5 > 1 → break (count = 1)
1 < 2 → fine
2 < 3 → fine (because we wrap around with % n)

count = 1 → return true ✅ (this is a rotated sorted array).
*/

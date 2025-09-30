// time - O(log n), space - O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<=right){
            int m=left+(right-left)/2;
            if(nums[m]==target)return m;
            else if(nums[m]<target)left=m+1;
            else{right=m-1;}
        }
        return -1;
    }
};
/*
Example:
nums = [6,8,9,10,12], target=10
Step 1: mid=index(2) -> 9 low=mid+1
Step 2: low=3, high=4, mid=3(target=10, index-3)
return 3;
*/

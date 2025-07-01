class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0;
	int high=n-1;
    // If all elements are less than target, then the correct insert position is at the end (index n).
	int result=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]>=target){
			result=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	
	}
		return result;
    }
};
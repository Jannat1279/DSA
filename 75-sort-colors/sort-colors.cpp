class Solution {
public:
    void swaps(vector<int>& nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int start=0, end=nums.size()-1, curPos=0;
        while(curPos<=end){
            // Swaping both currPos and start and incrementing both.
            if(nums[curPos]==0)swaps(nums,curPos++,start++);
            else if(nums[curPos]==2)swaps(nums,curPos,end--);
            else{
                curPos++;
            }
        }
    }
};
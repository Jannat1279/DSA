class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i=0;
    for(int k=1;k<nums.size();k++){
        if(nums[k]!=nums[i]){
            nums[i+1]=nums[k];
	    i++;
            }
        }
    return i+1;
    }
};
/*
nums=[1, 1, 2, 2, 2, 3, 4]

| `k` | `nums[k]` | `nums[i]` | Action                 | `nums` after step         | `i` |
| --- | --------- | --------- | ---------------------- | ------------------------- | --- |
| 1   | 1         | 1         | same → skip            | [1, 1, 2, 2, 2, 3, 4, 4]  | 0   |
| 2   | 2         | 1         | new → set nums\[1] = 2 | [1, 2, 2, 2, 2, 3, 4, 4]  | 1   |
| 3   | 2         | 2         | same → skip            | -                         | 1   |
| 4   | 2         | 2         | same → skip            | -                         | 1   |
| 5   | 3         | 2         | new → set nums\[2] = 3 | [1, 2, 3, 2, 2, 3, 4, 4]  | 2   |
| 6   | 4         | 3         | new → set nums\[3] = 4 | [1, 2, 3, 4, 2, 3, 4, 4]  | 3   |
| 7   | 4         | 4         | same → skip            | -                         | 3   |
*/

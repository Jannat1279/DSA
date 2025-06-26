class Solution {
public:
// There cannot be mpre than 2 elements that appear more than 3 times.
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        map<int, int> mpp;
        // least occurrence of the majority element:
        int mini = int(n / 3) + 1;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ls.push_back(nums[i]);
            }
            else if(ls.size()==2)break;
        }
        return ls;
    }
};
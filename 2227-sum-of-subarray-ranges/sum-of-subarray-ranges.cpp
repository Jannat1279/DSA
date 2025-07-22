class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            long long largest=nums[i], smallest=nums[i];
            for(int j=i+1;j<n;j++){
                smallest=min(smallest,(long long)nums[j]);
                largest=max(largest,(long long)nums[j]);
                sum+=largest-smallest;
            }
           
        }
        return sum;
    }
};

/*
Example:
nums = {1, 2, 3}

✅ Step-by-step Execution:
All subarrays of nums:

Subarray	Min	        Max	        Range (Max - Min)
[1]	        1	         1	                0
[1, 2]	    1	         2	                1
[1, 2, 3]	1	         3	                2
[2]        	2	         2                	0
[2, 3]	    2	         3                	1
[3]        	3	         3              	0

Add up all the ranges:
0 + 1 + 2 + 0 + 1 + 0 = 4

🧮 Internally in the code:
Outer loop: i = 0
largest = 1, smallest = 1

→ j = 1 → nums[j] = 2
→ smallest = min(1, 2) = 1
→ largest = max(1, 2) = 2
→ sum += 2 - 1 = 1

→ j = 2 → nums[j] = 3
→ smallest = 1
→ largest = 3
→ sum += 3 - 1 = 2
(Current sum: 3)

i = 1
largest = 2, smallest = 2

→ j = 2 → nums[j] = 3
→ smallest = 2
→ largest = 3
→ sum += 3 - 2 = 1
(Current sum: 4)

i = 2
only subarray is [3], range = 0 → nothing added

✅ Final Output:
return 4
*/

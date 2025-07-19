class Solution {
public:
    // Function to find the first occurrence of 'needle' in 'haystack'
    int strStr(string haystack, string needle) {
        int n = haystack.size(); // Length of haystack string
        int m = needle.size();   // Length of needle string

        // Loop through each possible starting index in haystack
        // Only go up to (n - m) because a match can't start after that
        for (int i = 0; i <= n - m; i++) {
            // Extract substring of length 'm' starting at index 'i' from
            // haystack Compare it directly with needle
            if (haystack.substr(i, m) == needle) {
                return i; // If match found, return starting index
            }
        }

        // If no match is found, return -1
        return -1;
    }
};

/*
Example:
haystack = "mississippi";
needle = "issip";
💡 Goal:
Find the first index where "issip" occurs in "mississippi".
(If not found, return -1.)

🧠 Step-by-Step Execution:
haystack length n = 11, needle length m = 5
We check all substrings of length 5 in haystack:

i	haystack.substr(i, 5)	Equals "issip"?
0	"missi"	❌ No
1	"issis"	❌ No
2	"ssiss"	❌ No
3	"sissi"	❌ No
4	"issip"	✅ Yes

✅ Output:
return 4;
*/

// time - O(n k log k)
// space - O(n.k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to group anagrams by their sorted string
        // Key: sorted version of the string
        // Value: list of original strings that are anagrams
        unordered_map<string, vector<string>> mp;

        // Loop through each string in the input
        for (auto str : strs) {
            string temp = str;

            // Sort the string to get the canonical form
            // All anagrams will have the same sorted form
            sort(temp.begin(), temp.end());

            // Add the original string to the vector mapped by the sorted string
            mp[temp].push_back(str);
        }

        // Prepare the final result by collecting all groups of anagrams
        vector<vector<string>> result;
        for (auto it : mp) {
            result.push_back(
                it.second); // it.second is a vector of grouped anagrams
        }

        // Return all grouped anagrams
        return result;
    }
};

/*
Example:
strs = {"eat", "tea", "tan", "ate", "nat", "bat"}
Sorted forms:

"eat" → "aet"
"tea" → "aet"
"tan" → "ant"
"ate" → "aet"
"nat" → "ant"
"bat" → "abt"

So the map becomes:

"aet" → ["eat", "tea", "ate"]
"ant" → ["tan", "nat"]
"abt" → ["bat"]

Final output:

[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
*/

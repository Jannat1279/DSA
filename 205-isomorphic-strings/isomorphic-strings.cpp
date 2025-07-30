class Solution {
public:
    bool isIsomorphic(string s, string t) {
    // Two hash maps to store character mappings
    unordered_map<char, char> mp1;  // maps characters from s -> t
    unordered_map<char, char> mp2;  // maps characters from t -> s (for reverse validation)
    
    int m = s.length(); // both strings are assumed to be the same length

    for (int i = 0; i < m; i++) {
        char ch1 = s[i]; // character from s
        char ch2 = t[i]; // character from t

        // Check if a mapping already exists in both directions
        // 1. ch1 is already mapped to something different than ch2
        // 2. ch2 is already mapped to something different than ch1
        if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || 
            (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
            return false; // conflicting mapping found → not isomorphic
        }

        // Record the mapping in both maps
        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }

    return true; // All mappings are consistent → strings are isomorphic
}

};

/*
❌ Example:

s = "ab"
t = "aa"

Step-by-step mapping:
'a' → 'a'
→ Map: mp1[a]=a, mp2[a]=a

'b' → 'a'
→ mp2[a] == a already, now trying to map another letter 'b' → 'a' → ❌ conflict
*/

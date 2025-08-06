class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // create a row with i+1 elements initialized to 1

            // update values in between first and last
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }
        return triangle;        
    }
};
/*
Example:
i = 0
row = [1]
→ triangle = [[1]]

i = 1
row = [1, 1]
→ triangle = [[1], [1, 1]]

i = 2
row = [1, 1, 1]
→ update middle: row[1] = triangle[1][0] + triangle[1][1] = 1 + 1 = 2
→ row = [1, 2, 1]
→ triangle = [[1], [1, 1], [1, 2, 1]]'

i = 3
row = [1, 1, 1, 1]
→ row[1] = 1 + 2 = 3
→ row[2] = 2 + 1 = 3
→ row = [1, 3, 3, 1]

i = 4
row = [1, 1, 1, 1, 1]
→ row[1] = 1 + 3 = 4
→ row[2] = 3 + 3 = 6
→ row[3] = 3 + 1 = 4
→ row = [1, 4, 6, 4, 1]

✅ Final Output for numRows = 5:
[
 [1],
 [1, 1],
 [1, 2, 1],
 [1, 3, 3, 1],
 [1, 4, 6, 4, 1]
]

*/

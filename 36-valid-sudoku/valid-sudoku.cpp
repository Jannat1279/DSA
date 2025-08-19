class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of seen numbers in rows, columns, and 3x3 boxes
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        // Traverse each cell of the board
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                
                // Skip empty cells
                if(board[r][c] == '.') {
                    continue;
                }
            
                // Convert character '1'–'9' into integer index 0–8
                int val = board[r][c] - '1';

                // ✅ Check row: if this number already appeared in row `r`
                if(rows[r][val] == 1) {
                    return false;
                }
                rows[r][val] = 1; // Mark as seen in this row

                // ✅ Check column: if this number already appeared in column `c`
                if(cols[c][val] == 1) {
                    return false;
                }
                cols[c][val] = 1; // Mark as seen in this column

                // ✅ Check 3x3 sub-box
                // Each box is indexed from 0 to 8
                // Formula: boxInd = (r / 3) * 3 + (c / 3)
                int boxInd = 3 * (r / 3) + (c / 3);
                
                if(boxes[boxInd][val] == 1) {
                    return false;
                }
                boxes[boxInd][val] = 1; // Mark as seen in this box
            }
        }

        // If no conflicts found, the Sudoku is valid
        return true;
    }
};

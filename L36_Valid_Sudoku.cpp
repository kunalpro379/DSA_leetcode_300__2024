class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>columns[9];
        unordered_set<char>subgrids[3][3];

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
               char currentChar=board[row][col];
                if(currentChar=='.') continue;

                if(rows[row].count(currentChar)||columns[col].count(currentChar)||subgrids[row/3][col/3].count(currentChar))
                {return false;}

                rows[row].insert(currentChar);
                columns[col].insert(currentChar);
                subgrids[row/3][col/3].insert(currentChar);
            }
        }return true;
            }
};
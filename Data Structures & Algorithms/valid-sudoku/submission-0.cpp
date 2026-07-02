class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < 9; i++){
            unordered_set<char> row;
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                if (row.find(board[i][j]) != row.end())
                    return false;
                row.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++){
            unordered_set<char> column;
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.')
                    continue;
                if (column.find(board[j][i]) != column.end())
                    return false;
                column.insert(board[j][i]);
            }
        }

        for (int r = 0; r < 9; r+=3){
            for (int c = 0; c < 9; c += 3){
                unordered_set<char> box;
                for (int i = r; i < r + 3; i++){
                    for (int j = c; j < c + 3; j++){
                        if (board[i][j] == '.')
                            continue;
                        if (box.find(board[i][j]) != box.end())
                            return false;
                        box.insert(board[i][j]);
                    }
                }

            }
        }
        return true;
        
    }
};

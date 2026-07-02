class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char x = board[i][j];
                int bidx = (i/3)*3 + (j/3);
                if (x == '.')
                    continue;
                if (row[i].count(x))
                    return false;
                if (col[j].count(x))
                    return false;
                if (box[bidx].count(x))
                    return false;
                row[i].insert(x);
                col[j].insert(x);
                box[bidx].insert(x);
            }
        }
        return true;
    }
};

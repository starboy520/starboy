class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int size = board.size();
        if (size < 3) return false;
        
        for (int i = 0; i < size; i++) {
            vector<int> tmp(10, 0);
            for (int j = 0; j < size; j++) {
                if(board[i][j] == '.') continue;
                else {
                    tmp[board[i][j]-'0']++;
                    if (tmp[board[i][j] - '0'] >= 2) return false;
                }
            }
        }
        
        for (int i = 0; i < size; i++) {
            vector<int> tmp(10, 0);
            for (int j = 0; j < size; j++) {
                if(board[j][i] == '.') continue;
                else {
                    tmp[board[j][i]-'0']++;
                    if (tmp[board[j][i]-'0'] >= 2) return false;
                }
            }
        }
        
        for (int i = 0; i < size; i+=3) {
            for (int j = 0; j < size; j+=3) {
                vector<int> tmp(10, 0);
                for (int k = i; k < i+3; k++) {
                    for (int m = j; m < j+3; m++) {
                        if (board[k][m] == '.') continue;
                        else {
                            tmp[board[k][m]-'0']++;
                            if (tmp[board[k][m]-'0'] >=2 ) return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
};

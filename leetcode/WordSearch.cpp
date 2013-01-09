class Solution {
public:

    bool search(vector<vector<char> >& board, int row, int column, vector<vector<int> >& tmp, string s, int begin, int end) {
        int m = board.size();
        int n = board[0].size();
        
        if (begin > end) {
            return true;
        }
        //if (begin == end && s[begin] == board[row][column]) return true;
        
        if (row >= m || row < 0 || column >= n || column < 0) return false;
        
        if (board[row][column] != s[begin]) {
            return false;
        }
        
        int ts = tmp[row][column];
        if (ts != -1) return false;
        
        for (int i = 0; i < 4; i++) {
            tmp[row][column] = i;
            if (i == 0) {
                //if (row+1 < m) { 
                    if (true == search(board, row+1, column, tmp, s, begin+1, end))
                        return true;
                //}
            }
            
            if (i == 1) {
                //if (column +1 < n) {
                    if (true == search(board, row, column+1, tmp, s, begin+1, end))
                        return true;
                //}
            }
            if (i == 2) {
                //if (row-1 >= 0) {
                    if (true == search(board, row-1, column, tmp, s, begin+1, end))
                        return true;
                //}
                
            }
            if (i == 3) {
                //if (column -1 >= 0) {
                    if (true == search(board, row, column-1, tmp, s, begin+1, end))
                        return true;
                //}
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();
            
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int> > tmp(m, vector<int>(n, -1));
                    if (search(board, i, j, tmp, word, 0, word.length()-1) == true) 
                        return true;
                }
            }
        }
        return false;
    }
};

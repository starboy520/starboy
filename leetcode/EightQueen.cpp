
class Solution {
public:
    vector<string> printsolution(int** a, int n) {
        vector<string> result;
        for (int i = 0; i < n ; i++) {
            string cur;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    cur.append(".");
                } else {
                    cur.append("Q");
                }
            }
            result.push_back(cur);
        }
        return result;
    }

    bool isSafe(int **a, int n, int row, int col) {
        for (int i = 0; i < col; i++) {
            if (a[row][i] == 1) return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (a[i][j] == 1) return false;
        }

        for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
            if (a[i][j] == 1) return false;
        }
        return true;
    }

    bool solutions(int** a, int n, int col, vector<vector<string> > & result) {
        if (col >= n) {
            vector<string> res = printsolution(a, n);
            result.push_back(res);
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(a, n, i, col)) {
                a[i][col] = 1;
                solutions(a, n, col+1, result);
                a[i][col] = 0;
            }
        }

        return false;
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if (n == 0) return result;
        int **a = new int*[n];
        for (int i = 0; i < n; i++) {
          a[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }

        solutions(a, n, 0, result);

        return result;
    }
};

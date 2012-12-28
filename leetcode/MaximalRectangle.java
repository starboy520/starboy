public class Solution {
    public int maximalRectangle(char[][] matrix)
    {
        if (matrix == null || matrix.length == 0)
            return 0;

        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    dp[i][j] = j > 0 ? dp[i][j - 1] + 1 : 1;
            }

        int max = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int k = i;
                    int min = dp[i][j];
                    while (k >= 0 && matrix[k][j] == '1')
                    {
                        min = Math.min(min, dp[k][j]);
                        max = Math.max(max, min * (i - k + 1));
                        k--;
                    }
                }
            }

        return max;
    }
}

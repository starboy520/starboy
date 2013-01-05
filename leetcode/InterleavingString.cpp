class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        int t = size1 + size2;

        if (t != size3) return false;

        bool match[size1+1][size2+1];

        //memset(match, sizeof(match), false);

        for (int i = 0; i <= size1; i++)
          for (int j = 0; j <= size2; j++)
            match[i][j] = false;

        match[0][0] = true;
        for (int i = 1; i <= size1; i++) {
            char c1 = s1[i-1];
            char c3 = s3[i-1];
            if (c1 == c3) {
              match[i][0] = true;
            } else {
              break;
            }
        }

        for (int i = 1; i <= size2; i++) {
            char c2 = s2[i-1];
            char c3 = s3[i-1];
            if (c2 == c3) {
              match[0][i] = true;
            } else
              break;
        }

        for (int i = 1; i <= size1; i++) {
            char c1 = s1[i-1];
            for (int j = 1; j <= size2; j++) {
                char c2 = s2[j-1];
                int k = i+j;
                char c3 = s3[k-1];
                if (c1 == c3) {
                  match[i][j] = match[i-1][j] || match[i][j];
                }
                if (c2 == c3) {
                  match[i][j] = match[i][j-1] || match[i][j];
                }
            }
        }
        return match[size1][size2];
    }
};

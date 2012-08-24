#include <stdio.h>


// 第一类斯特林数
// f(n,k) = f(n-1,k-1) + kf(n-1, k)

int stiring1(int n, int k) {
    int a[n+1][k+1];
    int i, j;
    for (i = 1; i <= n; i++) {
        a[i][1] = 1;
        if (i <= k)
            a[i][i] = 1;
    }

    for ( i = 3; i <= n; i++) {
        for ( j = 2; j < i && j <= k; j++) {
            a[i][j] = a[i-1][j-1] + j * a[i-1][j];
        }
    }

    return a[n][k];
}


// 第二类斯特林数

int stiring2(int n, int k) {

}


int main() {
    printf("%d\n", stiring1(9, 1));
    printf("%d\n", stiring1(9,4));
    printf("%d\n", stiring1(9, 9));
    printf("%d\n", stiring1(9, 8));

    return 0;
}

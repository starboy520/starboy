/* 给一个长度为N的整数数组，
 * 只允许用乘法，不能除法，
 * 计算任意N-1个数的乘积最大值
 */

/* 用两个额外的数组
 * f[i] 表示前i个元素的成绩
 * b[i] 表述后i个元素的乘积
 *
 * 则e[i] 表示除去i 之外其他n-1
 * 个元素的乘积
 *
 * 则 e[i] = f[i-1] * b[i+1];
 */
#include <climits>
#include <cstdio>
int maxmulti(int *a, int n) {
    int *f = new int[n+1];
    int *b = new int[n+2];
    f[0] = 1;
    b[n+1] = 1;

    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1] * a[i-1];
        b[n-i+1] = b[n-i+2] * a[n-i];
    }

    int max =  INT_MIN;
    for (int i = 1; i <= n; i++) {
        int temp = f[i-1] * b[i+1];
        if ( max < temp)
            max = temp;
    }

    delete[] f;
    delete[] b;
    return max;
}

int main() {
    int a[] = {1,5,4,2,-7};
    int max = maxmulti(a, 5);
    printf("%d\n", max);
    return 0;
}


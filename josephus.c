#include <stdio.h>
//有1到N个人坐成一圈报数，报道M出局，下一位再从1开始报数，
//如此持续，直到剩下一位为止，报告此人的编号，X， 输入M，N，求出X

int josephus(int n, int m) {
    if (n==1)
        return 1;

    int i;
    int s = 0; // 需要注意
    for (i = 2; i <= n; i++)
        s = (s+m)%i;

    return s+1;
}

int main() {
    pritf("%d\n", josephus( 10, 3));
    return 0;
}

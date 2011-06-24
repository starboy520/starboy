#include <stdio.h>
//卡特兰数  c(2n,n) -c(2n,n+1) = 1/n+1 *c(2n,n)
// 
int katalan(int n) {
    int i;
    int a = n+2;
    int b = 2;
    int value = 1;
    while (a <= 2*n) {
        value *= a;
        a++;
        while ((value % b) ==0 && b <= n) {
            value = value /b;
            b++;
        }
    }
    while ( b <= n) {
        value = value/b;
        b++;
    }
    return value;
}

int main() {
    int n = 5;
    printf("%d\n", katalan(n));
    return 0;
}


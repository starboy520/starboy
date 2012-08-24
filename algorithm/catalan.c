#include <stdio.h>
//卡特兰数  c(2n,n) -c(2n,n+1) = 1/n+1 *c(2n,n)
// 
long long int catalan(int n) {
    long long int  i;
    long long int  a = n+2;
    long long int  b = 2;
    long long int  value = 1;
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
    printf("%lld\n", catalan(n));
    printf("%lld\n", catalan(4));
    printf("%lld\n", catalan(1));
    printf("%lld\n", catalan(2));
    printf("%lld\n", catalan(20));
    return 0;
}


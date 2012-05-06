/*
 * Problem Describe:
 * the number of ways to partition a set of n things into k nonempty subsets
 *
 */


/* How to solve that?
 * wo denote {n,k}, 
 *
 * {0,1}=0
 * {0,0}=1
 * {n,0}=0 for n > 0
 * {n,1}=1 for n > 0
 *
 * {n,2} = 2^{n-1}-1: one of the subset contain the last object and 
 *                    and some subset of the first n-1 objects 
 *                    there are 2^{n-1} ways to choose the latter subset:
 *                          since each of the first n-1 object is either 
 *                          in it or not in, but we must not exclude all of the objects
 *                          because we need to nonempty set
 *
 *{n,k}= k{n-1, k} + {n-1,k-1}
 */

#include <stdio.h>

int stirling(int n, int k) {
    if (n==0 && k==0)
        return 1;
//    else if (n ==0 && k!=0)
//        return 0;
//    else if (k==0 && n!=0)
//        return 0;
    else{
        int a[n+1][k+1];
        int i;
        for (i=1; i <= n; i++) {
            a[i][1] = 1;
            a[i][0] = 0;
            a[i][i] = 1;
        }

        int j;
        for (i=2; i <= n; i++) 
        {
            for (j=2; j < i && j<=k; j++)
                a[i][j]=j*a[i-1][j] + a[i-1][j-1];

        }
        return a[n][k];
    }
}

int main(){
    int n = 9;
    int k = 4;
    printf("%d\n",stirling(n,k));
    return 0;
}



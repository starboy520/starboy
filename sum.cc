// input two integern, m;
// choose from 1,2,3,...,n some integers to sum to m
// print all all possible combination.
#include <string.h>
#include <iostream>
using namespace std;
void printSolution(int* flag, int length) {
    for (int i = 0; i < length; i++) {
        if(flag[i] == 1) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

void knapsack(int m, int n, int* flag, int len) {
    if (m <1 || n < 1)
        return;
    if (m < n) 
        n = m;
    if (m == n) {
        flag[n-1] = 1;
        printSolution(flag, len);
        flag[n-1] = 0;
    }

    flag[n-1] = 1;
    knapsack(m-n, n-1, flag, len);
    flag[n-1] = 0;

    knapsack(m, n-1, flag, len);
}

int main() {
    int n = 9;
    int m = 12;
    int *flag = new int[n];
    memset(flag, 0, sizeof(flag));

    knapsack(m, n, flag, n);
    delete[] flag;

    return 0;
}

#include <iostream>
using namespace std;

/*
 * 题目描述：
 * 求500万以内的所有亲和数
 * 如果两个数a和b，a的所有真因数之和等于b,b的所有真因数之和等于a,则称a,b是一对亲和数。
 * 例如220和284，1184和1210，2620和2924。
 */

#define NUM 5000001
int sum[NUM];

int main() {
    int i,j;
    for (i=1; i < NUM; i++) 
        sum[i] = 1;

    for (i = 2; 2*i <= NUM; i++) {
        j = i + i;
        while ( j < NUM ){
            sum[j] += i;
            j += i;
        }
    }

    for (i = 1; i < NUM; i++) {
        if (sum[i] >= i && sum[i] <= NUM && sum[sum[i]]==i)
            cout << i << " " << sum[i] <<endl;
    }

    return 0;
}




// 
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
using namespace std;

bool concate(int *stick, int* flag, int left_sum, int target_sum, int unused_num, int all_num, int current_flag) {
    if (unused_num == 0 && left_sum == 0)
       return true;
    if (left_sum == 0) {
       left_sum = target_sum;
       current_flag++;
    }
    for (int i = 0; i < all_num; i++) {
       if (flag[i] != 0)
           continue;
       if (stick[i] > left_sum)
           continue;
       flag[i] = current_flag;
       if (concate(stick, flag, left_sum-stick[i], target_sum, unused_num-1, all_num, current_flag))
           return true;
       flag[i] = 0;
       if (stick[i] == left_sum || left_sum == target_sum)
           break;
    }
    return false;
}

int main() {
       int n = 10;
       int a[10] = {1,2,3,4,5,6,7,8,9,10};
       int flag[10] = {0};

       sort(a, a+10,  greater<int> ());
       int sum = 0;
       for (int i = 0; i < 10; i++) {
           sum += a[i];
       }

       int m = 5;
       int num  = sum/m;
       
       if (concate(a, flag, 0, num, n, n, 0)) {
           cout << num << endl;
       }

       for (int i = 0; i < 10; i++) {
           cout << flag[i] << " ";
       }
       cout << endl;
    return 0;
}

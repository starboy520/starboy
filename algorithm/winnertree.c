#include <stdio.h>

/*setup winner tree
 * n个人存放在a[n] 
 * 则需要的比赛是 n-1 场
 * 我们把这n个人和n-1场比赛的胜者放在一起，
 * 是一个完全二叉树
 * 用一个2n-1的元素的数组表示 W【2*n-1】为简化我们W[0]不用所以
 * W【2N】
 * 
 * 首先这n个人需要放在这个数组的最后
 * 为了让它是一个完全二叉树，需要一点技巧
 * 首先计算出数的高度为 h = height(2n-1)
 * 则最后一层应该存放的元素个数为（2n-1) - (1+2+4 +...2^(h-1)) -> k个元素
 * W[2^(h-1)] = a[0], ..... W[2^(h-1)+k-1] = a[0+k-1]
 * 然后其他的元素一次向前存 
 */

int height (int num) {
    int i = 0;
    while (num != 0) {
        num >>= 1;
        i++;
    }
    return i;
}

int pow1(int base, int po) {
    int temp = 1;
    int i;
    for (i = 1; i <= po; i++)
        temp *= base;
    return temp;
}

void initial(int *a, int n, int *tree) {
//    int *tree = (int *) malloc(sizeof(int) * 2*n); //index from 1,2, 2n-1
    int h = height(2*n-1);
    printf("height is %d\n", h);

    int left = 2*n - pow1(2, h-1);  // 最后一层剩余的个数 

    int i;
    for(i = 0; i < left; i++)     //建立一下
        tree[pow1(2,h-1)+i] = a[i];

    int innode = n-left;
    for (i = 0; i < innode; i++) 
        tree[pow1(2,h-1)-1-i] = a[n-1-i];

    for (i = n-1; i >= 1; i--)
        tree[i] = winner(tree[2*i], tree[2*i+1]);

}

int winner(int i , int j) {
    if (i < j)
        return i;
    return j;
}

int main() {
    int a[8] = {1,2,3,4,5,6,7,8};
    int tree[16];
    initial(a, 8, tree);
    int i;
    for(i = 1; i <= 15; i++)
        printf("%d\n", tree[i]);

    return 0;
}

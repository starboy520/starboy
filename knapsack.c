#include <stdio.h>
/**********************************************88

��������ĺ���˼��
      a[i][j] = a[i-1][j]   if j< cube[i]
      a[i][j] = max(a[i][j],a[i-1][j-1]+value[i])  j>=cube[i]
**************************************************************/

void knapsack(int **a, int *cube, int *value, int capacity, int n)
{
    /********
             a[][] Ϊ������������Ž�ֵ
            cube[] �����
            value[] Ϊÿ���ļ�ֵ,
            capacity Ϊ�������������
            n Ϊ������ܸ���
   ********/

    int i,j;
    for(i=0; i<=n;i++)
        a[i][0]=0;
    for(i=0;i<=capicaty;i++)
        a[0][i]=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=capacity; j++)
        {
            a[i][j] = a[i-1][j];
            if(cube[i]<j)
            {
                if(a[i][j]< a[i-1][j-1]+value[i])
                    a[i][j] = a[i-1][j-cube[i]]+value[i];
            }
        }
    }
}
int main()
{
	int C = 11;
	int value[] = {0, 3, 4, 5, 7};
	int cube[] = {0, 2, 3, 5, 7};
	int **a;
	a = (char **)malloc(sizeof(int) * 5)
	int i;
	for(i=0;i<=5;i++)
	{
		a[i] = (char *)malloc(sizeof(int) *11)

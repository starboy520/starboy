#include <stdio.h>
#define MAX 1000
#include <malloc.h>
//int d[MAX][MAX];
//int list[MAX];
//int state[MAX] = {0};
#define INF 10000
int d[6][6] = {0,  2, 4, INF,INF,INF,
               2,  0, 1, 4,  2,  INF,
               4,  1, 0, INF,3,  INF,
               INF,4,INF,0,  3,  2,
               INF,2, 3, 4,  0,  2,
               INF,INF,INF,2,2,0};
int state[6] = {0};
int list[6];
int n=6;
void dijkstra()
{
    int i,j;
    for(i=0;i<n;i++)
        list[i] = d[0][i];
    for(i=0;i<n;i++)
    {
        int c = INF;
        int k;
        for(j=0;j<n;j++)
        {
            if(list[j]<c && state[j] == 0)
            {
                c = list[j];
                k = j;
            }
            state[k] = 1;
        }
        for(j=0;j<n;j++)
        {
            if(state[j] == 0)
            {
                if(list[k]+d[k][j]<list[j])
                    list[j] = list[k]+d[k][j];
            }
        }
    }
}



int main()
{
   /* int **d;
    int i;
    d = (int **)malloc(sizeof(int)*6);
    for(i=0;i<6;i++)
        d[i] = (int *)malloc(sizeof(int)*6);*/
    int i;
//    int d[6][6] = {0,6,3,INF,INF,INF,6,0,2,5,INF,INF,3,2,0,3,4,INF,INF,5,3,0,2,3,INF,INF,INF,3,5,0};
//    int state[6] = {0};
//   int list[6];
    dijkstra();
    for(i=0;i<6;i++)
    {
        printf("%d\n",list[i]);
    }
    return 0;
}




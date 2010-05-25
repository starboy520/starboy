#include <stdio.h>
#define N 10   // the number of activities
int s[N+2];    // activities begins
int f[N+2];    //activities ends
int dp[N+2][N+2]; 
/* dp[i][j] represent the subproblem  max activities in s(i,j) ,
 * s(i,j) ={ak,f[i]<s[k]<f[k]<s[j]} ,which represent the set end after a[i]
 * and before a[j], the we need to solve the problem only know S(0,n+1);
 *
 * and s[0]=f[0]=0; f[n+1]=s[n+1]=INT_MAX;
 * also if i>=j ,we know dp[i][j]=0;
 *
 * dp[i][j] = 0 if(S(i,j)=NULL)
 * dp[i][j] = max(dp[i][k]+dp[k][j]+1)  1<k<j
 *
 */

void dp_activity_problem()
{
	int i,j,l,k;
	for(i = 0; i <= N+1; i++)
			dp[i][i] = 0;
	for(d = 1; d< N+2; d++)
	{
		for(i = 0; i < N+2-d; i++)
		{
			j = i+d ;
			for(k = i+1; k <= d; k++)
			{
				if(f[i] <=  s[k]  && f[k] <= s[i])
				{
					if( dp[i][k]+dp[k][j]+1 > dp[i][j])
						dp[i][j] = dp[i][k]+dp[k][j]+1;
				}
			}
		}
	}
}

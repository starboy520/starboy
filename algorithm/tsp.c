#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_N 10

int mypow(int x, int y)
{
	return (int)pow((double)x,(double)y);
}

struct path
{
	int current;
	int cost;
	long set;
	struct path *lastNode;
	struct path *next;
};

struct path *D[MAX_N];

/* 下面三个函数是集合中子集的相关操作，集合利用二进制代码表示
 * 比如包含n个元素从1到n标记，利用二进制汇总对应的位置表示
 * 比如第k位是1，表示k包含在这个子集中
 */
/*功能判断i是否在自己set中，
 * 采用安位与的方法
 * 返回一表示存在，返回0表示不存在
 */
int inSet(int i, int set)
{
	if( (mypow(2,i-1)&set)>0)
		return 1;
	else
		return 0;
}

/* 功能是向集合set中添加元素i
 * 将set第i位设置为1， 表示i被添加到set中
 */

int insertSet(int i, int set)
{
	if(inSet(i, set)==0)
		return set|mypow(2,i-1);
	return set;
}

/*功能是从集合中删除元素i
 * 将set中的第i位设置成0，表示从集合s中删除了
 */
int deleteSet(int i, int set)
{
	if(inSet(i,set))
	{
		set = ~(mypow(2,i-1))&set;
	}
	return set;
}



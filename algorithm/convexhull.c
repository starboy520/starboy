#include <stdio.h>
#include <math.h>
#define MAX_SIZE 100

//define the point set(x,y) coordinate and the angle with respect to the original point
typedef struct P
{
    double x;
    double y;
    double ang;
}Point;

// stack record
Point stack[MAX_SIZE];
int top=0;
//void pop();
//void push();
//void find_min_y(Point p[], int n);   //p[0]find the minimum y_coordinate point witht most right x_coordinate and store the point in p[0]

//int split(Point p[], int, int);
//void quicksort(Point, int , int);   //sort the ang in every point
//void convex(Point p[], int n);       //find the convexhull

double dis(Point p1, Point p2)    //the distance of two point
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void push(Point x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    if (top > 0)
    {
        top--;
    }
}

void find_min_y(Point p[], int n)
{
    Point tmp = p[0];
    int i;
    int j=0;
    for(i=1; i<n;i++)
    {
        if((p[i].y<tmp.y) || (p[i].y == tmp.y && p[i].x> tmp.x))
        {
            tmp = p[i];
            j = i;
        }
    }
    Point temp = p[0];
    p[0] = p[j];
    p[j] = temp;
}


void compute_cons(Point p[], int n)
{
    int i;
    for(i=1;i<n;i++)
        p[i].ang = acos((p[i].x-p[0].x)/dis(p[i], p[0]));
}


int split(Point p[], int low ,int high)
{
        int i,j;
        Point tmp;
        tmp = p[low];
        i = low;
        for(j = low+1; j<=high; j++)
        {
            if ((p[j].ang<tmp.ang) || (p[j].ang == tmp.ang && dis(p[0],p[j])< dis(p[0],tmp) ) )
            {
                i++;
                if( i!=j)
                {
                    Point temp;
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
        Point tp1= p[low];
        p[low] = p[i];
        p[i] = tp1;

        return i;
}

void quicksort(Point p[], int low, int high)
{
    if(low < high)
    {
        int w = split(p, low, high);
        quicksort(p,low, w-1);
        quicksort(p, w+1, high);
    }
}

void convex(Point p[], int n)
{
     find_min_y(p, n);
     compute_cons(p, n);
     quicksort(p, 1,n-1);
     push(p[n-1]);
     push(p[0]);
     int k = 1;
     while(k<n-1)
     {
         Point p1 = stack[top-1];
         Point p2 = stack[top];
         double tmp = (p2.x-p1.x)*(p[k].y-p1.y)-(p[k].x-p1.x)*(p2.y-p1.y); //×óÐý£¬
         if(tmp>0.0)
         {
            push(p[k]);
            k++;
         }
         else
            pop();
     }
}
/*
int main()
{
    int n;
    int i;
    printf("please input the size of the set of the point :");
    scanf("%d", &n);
    Point p[n];
    for(i = 0; i < n; i++)
    {
        printf("input the x and y coordinate of Point[%d]:",i);
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    convex(p, n);
    for(i = top; i>0; i--)
    {
        printf("%lf,%lf\n", stack[i].x,stack[i].y);
    }

}

*/

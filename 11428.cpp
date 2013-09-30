/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11428.inp"
#define fo "11428.out"
/**/
using namespace std;
/**/
int n;
/**/
long long cube(long long val)
{
    return (val * val * val);
}
/**/
void input()
{
    long i,j;
    int tmp;
    bool f;
    
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        i = 0;
        f = false;
        while(cube(i+1) - cube(i) <= n)
        {
            j = i+1;
            while(cube(j) - cube(i) <= n)
            {
                if(cube(j) - cube(i) == n)
                {
                    f = true;
                    break;
                }
                j++;
            }
            if(f)
                break;
            i++;
        }
        
        if(f)
            printf("%d %d\n",j,i);
        else
            printf("No solution\n");
    }
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

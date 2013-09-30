/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "11728.inp"
#define fo "11728.out"
/**/
using namespace std;
/**/
void input()
{
    int i,j,id;
    int n,sum;
    bool f;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        printf("Case %d: ",id++);
        f = false;
        for(i=n;i>=1;i--)
        {
            sum = 0;
            for(j=1;j<=i/2;j++)
                if(i % j == 0)
                    sum += j;
            sum += i;
            if(sum == n)
            {
                f = true;
                printf("%d\n",i);
                break;
            }
        }
        if(!f)
            printf("-1\n");
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

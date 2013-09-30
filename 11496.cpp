/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11496.inp"
#define fo "11496.out"
/**/
using namespace std;
/**/
int a[10010];
/**/
void input()
{
    int i;
    int n;
    int p;
    
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0] = a[n];
        a[n+1] = a[1];
        p = 0;
        for(i=1;i<=n;i++)
            if(a[i] > a[i-1] && a[i] > a[i+1])
                p++;
            else if(a[i] < a[i-1] && a[i] < a[i+1])
                p++;
        printf("%d\n",p);
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

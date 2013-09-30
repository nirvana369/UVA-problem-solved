/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12621.inp"
#define fo "12621.out"
#define diet 1000
/**/
using namespace std;
/**/
bool d[3000];
int a[110];
int n,m;
long maxdiet;
/**/
void khoitao()
{
    int i;
    for(i=0;i<=diet;i++)  
        d[i] = false;
    d[0] = true;
    maxdiet = 0;
}
/**/
void solve()
{
    int i,j;
    
    for(i=0;i<m;i++)
        for(j=diet-a[i];j>=0;j--)
            if(d[j])
                d[a[i] + j] = true;
                
    for(i=n;i<diet;i++)
        if(!d[i])
            maxdiet++;
        else
            break;
            
    maxdiet+=n;
    
    if(maxdiet < 1000)
        printf("%ld\n",maxdiet*10);
    else
        printf("NO SOLUTION\n");
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        scanf("%d",&m);
        n /= 10;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            a[i] /= 10;
        }
        solve();
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

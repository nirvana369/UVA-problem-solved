/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10125.inp"
#define fo "10125.out"
/**/
using namespace std;
/**/
long a[1010];
int n;
/**/
void sapxep()
{
    int i,j;
    long temp;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
}
/**/
void solve()
{
    int i,j,k,l;
    for(i=n;i>0;i--)
    {
        for(j=1;j<=n;j++)
            for(k=j+1;k<=n;k++)
                for(l=k+1;l<=n;l++)
                    if(i != j && i != k && i != l)
                        if(a[j] + a[k] + a[l] == a[i])
                        {
                            printf("%ld\n",a[i]);
                            return;
                        }
    }
    printf("no solution\n");
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=1;i<=n;i++)
            scanf("%ld",&a[i]);
        sapxep();
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

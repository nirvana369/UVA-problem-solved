/*
                                            Hoang Linh
                                        
                                    Problem: LOTTO - 441 (441.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "441.inp"
#define fo "441.out"
/**/
using namespace std;
/**/
int a[14];
int n;
/**/
void solve()
{
    int i,j,k,l,m,o;
    for(i=0;i<=n-6;i++)
        for(j=i+1;j<n;j++)
            for(k=j+1;k<n;k++)
                for(l=k+1;l<n;l++)
                    for(m=l+1;m<n;m++)
                        for(o=m+1;o<n;o++)
                            printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[o]);
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        if(id != 1)
            printf("\n");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        solve();
        id++;
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

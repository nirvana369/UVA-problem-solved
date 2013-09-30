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
#include <vector>

#define fi "10227.inp"
#define fo "10227.out"
/**/
using namespace std;
/**/
int a[110][110];
int p,t;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=p;i++)
        for(j=1;j<=t;j++)
            a[i][j] = 0;
}
/**/
void solve()
{
    int i,j,k;
    bool opi;
    int kq;
    
    kq = 0;
    
    for(i=1;i<=p;i++)
    {
        opi = false;    
        for(j=i-1;j>0;j--)
        {
            opi = false;
            for(k=1;k<=t;k++)
                if(a[i][k] != a[j][k])
                    break;
            if(k > t)
            {
                opi = true;
                break;
            }
        }
        if(!opi)
            kq++;
    }
    printf("%d\n",kq);        
}
/**/
void input()
{
    char s[100];
    int ntest;
    int x,y;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&p,&t);
        khoitao();
        gets(s);
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            sscanf(s,"%d %d",&x,&y);
            a[x][y] = 1;
        }
        solve();
        if(ntest)
            printf("\n");
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

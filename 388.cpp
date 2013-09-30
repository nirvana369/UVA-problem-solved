/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "388.inp"
#define fo "388.out"
#define maxgt 32000
/**/
using namespace std;
/**/
int a[30][30];
double val[30];
int n;
/**/
double rate(int m)
{
    int i;
    double gt;
    if(m == 0 || m == 1)
        return 1;
    gt = 1;
    for(i=1;i<m;i++)
        gt *= 0.95;
    return gt;
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=26;i++)
    {
        for(j=0;j<=26;j++)
            a[i][j] = maxgt;
        val[i] = 0;
    }
}
/**/
void solve()
{
    int i,j,k;
    int kt;
    
    for(k=0;k<=26;k++)
        for(i=0;i<=26;i++)
            for(j=0;j<=26;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    
    kt = 0;
    for(i=1;i<=26;i++)
        if(val[i] * rate(a[0][i]) > val[kt] * rate(a[0][kt]))
            kt = i;
    printf("Import from %c\n",kt+64);
}
/**/
void input()
{
    int i;
    double gt;
    char s[1000];
    int x,y;
    
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        while(n--)
        {
            scanf("%s %lf",&s,&gt);
            x = s[0] - 64;
            val[x] = gt;
            scanf("%s",&s);
            i = 0;
            while(s[i])
            {
                if(s[i] == '*')
                    a[x][0] = a[0][x] = 1;
                else
                {
                    y = s[i] - 64;
                    a[x][y] = a[y][x] = 1;
                }
                i++;
            }
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

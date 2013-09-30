/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "270.inp"
#define fo "270.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[710];
int dp;
/**/
int checkline(int i1,int i2)
{
    int i;
    int dem;
    int a,b,c;
    
    a = p[i1].y - p[i2].y;
    b = p[i2].x - p[i1].x;
    c = -(a * p[i1].x + b * p[i1].y);
    
    dem = 2;
    for(i=i2;i<dp;i++)
        if(i != i1 && i != i2)
            if((c + a * p[i].x + b * p[i].y) == 0)
                dem++;
    return dem;
}
/**/
void solve()
{
    int i,j;
    int maxline,tmp;
    
    maxline = 2;
    for(i=0;i<dp;i++)
        for(j=i+1;j<dp;j++)
        {
            tmp = checkline(i,j);
            if(tmp > maxline)
                maxline = tmp;
        }
    printf("%d\n",maxline);
}
/**/
void input()
{
    int ntest;
    char s[1000];
    scanf("%d",&ntest);
    gets(s);
    gets(s);
    while(ntest--)
    {
        dp = 0;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            sscanf(s,"%d %d",&p[dp].x,&p[dp].y);    
            dp++;
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

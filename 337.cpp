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

#define fi "337.inp"
#define fo "337.out"
/**/
using namespace std;
/**/
char a[12][12],s[1000];
int n,x,y;
bool overw;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            a[i][j] = ' ';
}
/**/
void chen(int vt)
{
    int i;
    for(i=9;i>y;i--)
        a[x][i] = a[x][i-1];
    a[x][y] = s[vt];
}
/**/
int xuly(int vt)
{
    int i;
    if(s[vt+1] >= '0' && s[vt+1] <= '9')
    {
        x = s[vt+1] - 48;
        y = s[vt+2] - 48;
        return vt+2;
    }
    else if(s[vt+1] == 'b')
        y = 0;
    else if(s[vt+1] == 'c')
        khoitao();
    else if(s[vt+1] == 'd')
    {
        if(x < 9)
            x += 1;
    }
    else if(s[vt+1] == 'e')
    {
        for(i=y;i<10;i++)
            a[x][i] = ' ';
    }
    else if(s[vt+1] == 'h')
    {
        x = 0;
        y = 0;
    }
    else if(s[vt+1] == 'i')
    {
        overw = false;
    }
    else if(s[vt+1] == 'l')
    {
        if(y > 0)
            y -= 1;
    }
    else if(s[vt+1] == 'o')
    {
        overw = true;
    }
    else if(s[vt+1] == 'r')
    {
        if(y < 9)
            y += 1;
    }
    else if(s[vt+1] == 'u')
    {
        if(x > 0)
            x -= 1;
    }
    else if(s[vt+1] == '^')
    {
        if(overw)
            a[x][y] = '^';
        else
            chen(vt+1);
        if(y < 9)
            y += 1;
    }
        
    return vt+1;
}
/**/
void solve()
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] == '^')
            i = xuly(i);
        else
        {
            if(overw)
                a[x][y] = s[i];
            else
                chen(i);
            if(y < 9)
                y += 1;
        }
}
/**/
void output()
{
    int i,j;
    printf("+");
    for(i=0;i<10;i++)
        printf("-");
    printf("+\n");
    for(i=0;i<10;i++)
    {
        printf("|");
        for(j=0;j<10;j++)
            printf("%c",a[i][j]);
        printf("|\n");
    }
    printf("+");
    for(i=0;i<10;i++)
        printf("-");
    printf("+\n");
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
        gets(s);
        khoitao();
        x = 0;
        y = 0;
        overw = true;
        for(i=0;i<n;i++)
        {
            gets(s);
            solve();
        }
        printf("Case %d\n",id++);
        output();
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

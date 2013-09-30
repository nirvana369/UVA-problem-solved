/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "1198.inp"
#define fo "1198.out"
#define maxgt 32000
/**/
using namespace std;
/**/
int a[50][50];
bool d[50];
int n,m;
vector<int > dinh;
/**/
void xuly(char s[])
{
    int i,dem;
    char tmp[10];
    int y;
    
    i = 0;
    dem = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            dem = 0;
            sscanf(tmp,"%d",&y);
            dinh.push_back(y);
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        sscanf(tmp,"%d",&y);
        dinh.push_back(y);
    }
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = maxgt;
}
/**/
void _relax()
{
    int i,j,k;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
}
/**/
void _reset()
{
    int i;
    for(i=1;i<=n;i++)
        d[i] = true;
}
/**/
void solve()
{
    int i,j,k;
    int x,y;
    
    _reset();
    
    for(i=0;i<dinh.size();i++)
        d[dinh[i]] = false;
    
    for(i=0;i<dinh.size();i++)
        for(j=i+1;j<dinh.size();j++)
        {
            x = dinh[i];
            y = dinh[j];
            for(k=1;k<=n;k++)
                if(a[x][k] + a[k][y] == a[x][y])
                    d[k] = false;
        }
    
    for(i=1;i<=n;i++)
        if(d[i])
        {
            printf("no\n");
            return;
        }
    printf("yes\n");
}
/**/
void input()
{
    int i,j;
    char s[1000];
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        gets(s);
        for(i=1;i<=n;i++)
        {
            dinh.clear();
            gets(s);
            xuly(s);
            for(j=0;j<dinh.size();j++)
                a[i][dinh[j]] = a[dinh[j]][i] = 1;
        }
        _relax();
        
        scanf("%d",&m);
        gets(s);
        for(i=0;i<m;i++)
        {
            gets(s);
            dinh.clear();
            xuly(s);
            solve();
        }
            
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

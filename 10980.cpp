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

#define fi "10980.inp"
#define fo "10980.out"
/**/
using namespace std;
/**/
float p[30];
int sl[30],d[30];
float p1,val;
int m;
/**/
void khoitao()
{
    int i;
    for(i=0;i<m;i++)
        d[i] = 0;
}
/**/
void dq(int soluong,float gt)
{
    int i,j;
    if(soluong <= 0)
    {
        if(gt < val)
            val = gt;
        return;
    }
    for(i=0;i<m;i++)
        if(!d[i])
        {
            j = 1;
            while(true) 
            {
                if(gt + p[i] * j < val)
                {
                    d[i] = 1;
                    dq(soluong-sl[i]*j,gt+p[i]*j);
                    d[i] = 0;
                }
                else
                    break;
                j++;
            }
        }
}
/**/
void buyitem(int soluong)
{
    int i;
    float temp;
    val = soluong * p1;
    for(i=0;i<m;i++)
    {
        if(soluong % sl[i] == 0)
            temp = p[i] * (soluong / sl[i]);
        else
            temp = p[i] * (soluong / sl[i] + 1);
        if(temp < val)
            val = temp;
    }
    khoitao();
    
    dq(soluong,0);
    
    printf("Buy %d for $%0.2f\n",soluong,val);
}
/**/
void solve(char s[])
{
    int i;
    int l,dem,n_item;
    char temp[100];
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] != ' ')
            temp[dem++] = s[i];
        else
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&n_item);
            buyitem(n_item);
            dem = 0;
        }
}
/**/
void input()
{
    int i;
    int id;
    char s[1000];
    id = 1;
    while(gets(s))
    {
        sscanf(s,"%f %d",&p1,&m);
        for(i=0;i<m;i++)
        {
            gets(s);
            sscanf(s,"%d %f",&sl[i],&p[i]);
        }
        gets(s);
        printf("Case %d:\n",id++);
        solve(s);
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

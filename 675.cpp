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

#define fi "675.inp"
#define fo "675.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[10000];
int kq[10000],d[10000];
int dp,id;
/**/
bool giongnhau(int i,int j)
{
    if(p[i].x == p[j].x && p[j].y == p[i].y)
        return true;
    return false;
}
/**/
bool kiemtra(int i1,int i2)
{
    int a,b,c;
    int i;
    
    a = p[i1].y - p[i2].y;
    b = p[i2].x - p[i1].x;
    c = -(p[i1].x * a + b * p[i1].y);
    
    for(i=0;i<dp;i++)
        if(d[i] != 2)
        {
            if(a * p[i].x + b * p[i].y + c > 0)
                return false;
            if(a * p[i].x + b * p[i].y + c == 0)
            {
                if((p[i].x - p[i1].x) * (p[i].x - p[i2].x) > 0)
                    return false;
                if((p[i].y - p[i1].y) * (p[i].y - p[i2].y) > 0)
                    return false;
            }
        }
    return true;
}
/**/
bool kttrung(int i1,int i,int i2)
{
    int a,b,c;
    
    a = p[i1].y - p[i2].y;
    b = p[i2].x - p[i1].x;
    c = -(p[i1].x * a + b * p[i1].y);
    
    if(a * p[i].x + b * p[i].y + c == 0)
    {
        if((p[i].x - p[i1].x) * (p[i].x - p[i2].x) > 0)
            return true;
        if((p[i].y - p[i1].y) * (p[i].y - p[i2].y) > 0)
            return true;
    }
    return false;
}
/**/
void solve()
{
    int i,j,k;
    int last,dem;   
    bool timthay; 
    
    last = id;
    dem = 0;
    
    while(true)
    {
        for(i=0;i<dp;i++)
            if(d[i] == 0 && !giongnhau(i,id) && kiemtra(i,id))
            {
                d[i] = 1;
                id = i;
                if(dem - 2 >= 0 && kttrung(i,kq[dem-1],kq[dem-2]))
                    kq[dem-1] = i;
                else
                    kq[dem++] = i;
                break;
            }
        if(id == last)
            break;
    }
    timthay = false;
    for(i=0;i<dp;i++)
    {
        for(j=0;j<dem;j++)
        {
            if(giongnhau(i,kq[j]))
            {
                for(k=j;k<dem;k++)
                    printf("%d, %d\n",p[kq[k]].x,p[kq[k]].y);
                for(k=0;k<=j;k++)
                    printf("%d, %d\n",p[kq[k]].x,p[kq[k]].y);
                timthay = true;
                break;
            }
        }
        if(timthay)
            break;
    }
}
/**/
void input()
{
    char s[100];
    int check;
    check = 0;
    while(true)
    {
        dp = id = 0;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            sscanf(s,"%d, %d",&p[dp].x,&p[dp].y);
            if(p[dp].x < p[id].x)
                id = dp;
            else if(p[dp].x == p[id].x)
                if(p[dp].y < p[id].y)
                    id = dp;
            d[dp] = 0;
            dp++;
        }
        if(!dp)
            break;
        dp--;
        if(check)
            printf("\n");
        solve();
        check++;
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

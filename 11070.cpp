/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11070.inp"
#define fo "11070.out"
/**/
using namespace std;
/**/
struct bt{
                double val;
                char flg;
            };
bt a[300];
int c,ut;
/**/
void xuly(char s[])
{
    int i,dem;
    char tmp[1000];
    
    c = ut = 0;
    i = dem = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.')
            tmp[dem++] = s[i];
        else
        {
            if(dem != 0)
            {
                tmp[dem] = 0;
                sscanf(tmp,"%lf",&a[c].val);
                a[c++].flg = 0;
                dem = 0;
            }
            if(s[i] == '+'|| s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(s[i] == '*' || s[i] == '/')
                    ut++;
                a[c++].flg = s[i];
            }
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        sscanf(tmp,"%lf",&a[c].val);
        a[c++].flg = 0;
        dem = 0;
    }
}
/**/
void donmang(int dau,int cuoi)
{
    int i;
    for(i=cuoi+1;i<c;i++)
        a[dau++] = a[i];
    c = dau;
}
/**/
void fixx()
{
    int i,j;
    int dems;
    bool am;
    
    am = false;
    for(i=0;i<c;i++)
    {
        if(a[i].flg == '-')    
            am = !am;
        if(!a[i].flg)
            break;
    }
    if(i != 0)
    {
        if(am)
            a[i].val *= -1;
        donmang(0,i-1);
    }
    
    
    for(i=0;i<c;i++)
    {
        if(!a[i].flg)
        {
            dems = 0;
            for(j=i-1;j>=0;j--)
            {
                if(a[j].flg)
                    dems++;
                else
                    break;
            }
            if(dems > 1)
            {
                if(a[i-1].flg == '-')
                {
                    a[i].val *= -1;
                    donmang(i-1,i-1);
                }
            }
        }
    }
}
/**/
void solve()
{
    int i,j;
    bool am;
    
    fixx();
    
    
    while(c > 1)
    {
        if(ut)
        {
            for(i=1;i<c;i++)
                if(a[i].flg == '*' || a[i].flg == '/')
                {
                    am = false;
                    for(j=i+1;j<c;j++)        
                    {
                        if(a[j].flg == '-')
                            am = !am;
                        if(!a[j].flg)
                            break;
                    }
                    if(am)
                        a[j].val *= -1;
                    if(a[i].flg == '*')
                        a[i-1].val *= a[j].val;
                    else
                        a[i-1].val /= a[j].val;
                    ut--;
                    donmang(i,j);
                    break;
                }
        }
        else
        {
            for(i=1;i<c;i++)
                if(a[i].flg == '+' || a[i].flg == '-')
                {
                    am = false;
                    for(j=i+1;j<c;j++)        
                    {
                        if(a[j].flg == '-')
                            am = !am;
                        if(!a[j].flg)
                            break;
                    }
                    if(am)
                        a[j].val *= -1;
                    if(a[i].flg == '+')
                        a[i-1].val += a[j].val;
                    else
                        a[i-1].val -= a[j].val;
                    donmang(i,j);
                }
        }
    }
    am = false;
    for(i=0;i<c;i++)
    {
        if(a[i].flg == '-')
            am = !am;
        if(!a[i].flg)
            break;
    }
    if(am)
        a[i].val *= -1;
    if(fabs(a[i].val) < 0.0001)
        printf("%0.3lf\n",0);
    else
        printf("%0.3lf\n",a[i].val);
}
/**/
void input()
{
    char s[1000];
    while(!feof(stdin))
    {
        gets(s);
        if(feof(stdin))
            break;
        xuly(s);
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

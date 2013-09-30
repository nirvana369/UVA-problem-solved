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

#define fi "332.inp"
#define fo "332.out"
#define eps 1e-9
/**/
using namespace std;
/**/
int n;
char s[1000];
/**/
long ucln(long a,long b)
{
    long r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
long getbac(int bac)
{
    int i;
    long val;
    val = 1;
    for(i=0;i<bac;i++)
        val *= 10;
    return val;
}
/**/
bool kiemtra(double a,double b,int bac)
{
    long long gt1,gt2;
    double val1,val2;
    val1 = a * pow(10,bac);
    val2 = b * pow(10,bac);
    gt1 = (long long) val1;
    gt2 = (long long) val2;
    if(gt1 == gt2)
        return true;
    return false;
}
/**/
void solve(int id)
{
    int k,i;
    int l;
    long long tu,mau,a,b,tg;
    char temp[100];
    double val2;
    
    l = strlen(s);
    b = a = 0;
    for(k=2,i=0;k<l;k++,i++)
        temp[i] = s[k];
    temp[i] = 0;
    sscanf(temp,"%lld",&b);
    
    for(k=2,i=0;k<l-n;k++,i++)
        temp[i] = s[k];
    temp[i] = 0;
    sscanf(temp,"%lld",&a);
    
    if(n == 0)
    {
        a = 0;
        tu = b - a;
        val2 = pow(10,i);
        mau = (long long) val2;
        tg = ucln(tu,mau);
        tu /= tg;
        mau /= tg;   
    }
    else
    {
        tu = b - a;
        val2 = (pow(10,n) - 1) * pow(10,i);
        mau = (long long) val2;

        if(mau != 0 && tu != 0)
        {
            tg = ucln(tu,mau);
            tu /= tg;
            mau /= tg;
        }
        else
        {
            tu = 0;
            mau = tu + 1;
        }
    }
    printf("Case %d: %lld/%lld\n",id,tu,mau);
}
/**/
void input()
{
    int id;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        if(n < 0)
            break;
        scanf("%s",&s);
        solve(id++);
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

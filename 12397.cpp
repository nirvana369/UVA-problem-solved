/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12397.inp"
#define fo "12397.out"
/**/
using namespace std;
/**/
int rn[4010];
int d[100];
char kq[100];
int dkq;
/**/
void chuyenso(int value)
{
    int i;
    if(value < 10)
    {
        if(value < 4)
        {
            for(i=1;i<=value;i++)
                kq[dkq++] = 'I';
        }
        else if(value == 4)
        {
            kq[dkq++] = 'V';
            kq[dkq++] = 'I';
        }
        else if(value == 5)
            kq[dkq++] = 'V';
        else if(value < 9)
        {
            for(i=1;i<=value-5;i++)
                kq[dkq++] = 'I';
            kq[dkq++] = 'V';
        }
        else if(value == 9)
        {
            kq[dkq++] = 'X';
            kq[dkq++] = 'I';
        }
    }
    else if(value < 100)
    {
        if(value < 40)
        {
            for(i=10;i<=value;i+=10)
                kq[dkq++] = 'X';
        }
        else if(value == 40)
        {
            kq[dkq++] = 'L';
            kq[dkq++] = 'X';
        }
        else if(value == 50)
            kq[dkq++] = 'L';
        else if(value < 90)
        {
            for(i=10;i<=value-50;i+=10)
                kq[dkq++] = 'X';
            kq[dkq++] = 'L';
        }
        else if(value == 90)
        {
            kq[dkq++] = 'C';
            kq[dkq++] = 'X';
        }
    }
    else if(value < 1000)
    {
        if(value < 400)
        {
            for(i=100;i<=value;i+=100)
                kq[dkq++] = 'C';
        }
        else if(value == 400)
        {
            kq[dkq++] = 'D';
            kq[dkq++] = 'C';
        }
        else if(value == 500)
            kq[dkq++] = 'D';
        else if(value < 900)
        {
            for(i=100;i<=value-500;i+=100)
                kq[dkq++] = 'C';
            kq[dkq++] = 'D';
        }
        else if(value == 900)
        {
            kq[dkq++] = 'M';
            kq[dkq++] = 'C';
        }
    }
    else
    {
        for(i=1000;i<=value;i+=1000)
            kq[dkq++] = 'M';
    }
}
/**/
int xulyso(int val)
{
    int i,j;
    int gt,dem;
    int tmp = val;
    gt = 1;
    dkq = 0;
    while(val != 0)
    {
        chuyenso(val % 10 * gt);
        val /= 10;
        gt *= 10;
    }
    dem = 0;
    for(i=0;i<dkq;i++)
        dem += d[kq[i]];
    kq[dkq] = 0;
    return dem;
}
/**/
void _init()
{
    int i;    
    d['I'] = 1;
    d['V'] = 2;
    d['X'] = 2;
    d['L'] = 2;
    d['C'] = 2;
    d['D'] = 3;
    d['M'] = 4;
    
    for(i=1;i<4000;i++)
        rn[i] = xulyso(i);
}
/**/
void input()
{
    int n;    
    _init();
    
    while(scanf("%d",&n) == 1)
        printf("%d\n",rn[n]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

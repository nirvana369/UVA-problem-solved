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

#define fi "10375.inp"
#define fo "10375.out"
#define eps 1e-9
/**/
using namespace std;
/**/
int agt[11000],bgt[11000],d1[11000],d2[11000];
int da,db,dem1,dem2;
int a,b,c,d;
int maxgt,mingt;
/**/
int ucln(int x,int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
/**/
void xuly()
{
    int i,j,k;
    int temp;
    dem1 = dem2 = 0;
    
    
    for(i=0;i<da;i++)
    {
        for(j=0;j<db;j++)
            if(agt[i] == bgt[j])
            {
                agt[i] = 0;
                bgt[j] = 0;
                break;           
            }
    }
    
    for(i=0;i<da-1;i++)
    {
        for(j=i+1;j<da;j++)
        {
            if(agt[i] < agt[j])
            {
                temp = agt[i];
                agt[i] = agt[j];
                agt[j] = temp;
            }
            if(bgt[i] < bgt[j])
            {
                temp = bgt[i];
                bgt[i] = bgt[j];
                bgt[j] = temp;
            }
        }
        if(agt[i] || bgt[i])
            if(agt[i] > bgt[i])
            {
                for(k=bgt[i]+1;k<=agt[i];k++)
                    d1[dem1++] = k;
            }
            else
            {
                for(k=agt[i]+1;k<=bgt[i];k++)
                    d2[dem2++] = k;
            }
    }
    
    if(agt[i] || bgt[i])
            if(agt[i] > bgt[i])
            {
                for(k=bgt[i]+1;k<=agt[i];k++)
                    d1[dem1++] = k;
            }
            else
            {
                for(k=agt[i]+1;k<=bgt[i];k++)
                    d2[dem2++] = k;
            }
}
int solve()
{
    int i,j;
    int temp;

    for(i=0;i<dem1;i++)
    {
        for(j=0;j<dem2;j++)
        {
            temp = ucln(d1[i],d2[j]);
            if(temp != 1)
            {
                d1[i] /= temp;
                d2[j] /= temp;
            }
            if(d1[i] == 1)
                break;
        }
        
    }
}
/**/
void output()
{
    int i;
    double kq,val1,val2;
    
    val1 = val2 = 1.0;
    i = 0;
    while(i < dem1 || i < dem2)
    {
        if(i < dem1 && i < dem2)
            val1 *= (double)d1[i] / d2[i];
        else if(i < dem1)
            val1 *= (double)d1[i];
        else
            val1 *= (double)d2[i];
        i++;
    }
    printf("%0.5lf\n",val1);
}
/**/
void input()
{
    while(scanf("%d %d %d %d",&a,&b,&c,&d) == 4)
    {
        da = db = 0;
        agt[da++] = a;
        agt[da++] = d;
        agt[da++] = c-d;
        
        bgt[db++] = c;
        bgt[db++] = b;
        bgt[db++] = a-b;
        xuly();
        solve();
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

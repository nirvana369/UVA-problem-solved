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

#define fi "10856.inp"
#define fo "10856.out"
/**/
using namespace std;
/**/
long fac[10000000],d[4000000],kq[10000010];
int nt[10000];
int dnt;
/**/
bool isnt(int val)
{
    int i;
    int temp,add;
    
    if(val == 2 || val == 3)
        return true;
    if(val == 1 || val % 2 == 0 || val % 3 == 0)
        return false;
    temp = (int)sqrt(val);
    add = 2;
    for(i=5;i<=temp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;
}
/**/
int xuly(long val)
{
    int i;
    int dem;
    i = 0;
    dem = 0;
    while(val != 1)
    {
        while(val % nt[i] == 0)
        {
            val /= nt[i];
            dem++;
        }
        i++;
        if(i == dnt)
            break;
        if(d[val])
            return dem+1;
    }
    return dem;
}
/**/
void precal()
{
    int i;
    long j,dem;
    dnt = 0;
    for(j=1;j<=3071362;j++)
    {
        d[j] = 0;
        kq[j] = 0;
    }
    for(j=3071362;j<=10000001;j++)
        kq[j] = 0;
    for(i=2;i<10000;i++)
        if(isnt(i))
        {
            nt[dnt++] = i;
            d[i] = 1;
        }
    j = 2;
    dem = 0;
    d[1] = 0;
    while(dem <= 10000000)
    {
        if(d[j] != 1)
        {
            if(isnt(j))
                d[j] = 1;
            else
            {
                for(i=0;i<dnt;i++)
                    if(j % nt[i] == 0)
                    {
                        d[j] = d[j/nt[i]] + 1;
                        break;
                    }
            }
        }
        dem += d[j];
        fac[j] = dem;
        kq[dem] = j;
        j++;
    }
    kq[0] = 0;
}
/**/
void input()
{
    int id;
    long n;
    precal();
    id = 1;
    while(scanf("%ld",&n) == 1)
    {
        if(n < 0)   
            break;
        printf("Case %d: ",id++);
        if(kq[n] == 0 && n != 0)
            printf("Not possible.\n");
        else
            printf("%ld!\n",kq[n]);
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


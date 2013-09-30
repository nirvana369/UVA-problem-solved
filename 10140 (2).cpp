/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10140.inp"
#define fo "10140.out"
#define maxgt 46341
/**/
using namespace std;
/**/
long nt[maxgt],pnt[maxgt],a[1000000];
long dnt;
bool d[maxgt+2];
/**/
void _sieve()
{
    long i,j;
    long tmp;
    
    for(i=3;i<maxgt;i+=2)
        d[i] = true;
    d[1] = false;
    d[2] = true;
        
    dnt = 0;
    nt[dnt] = 2;
    pnt[dnt] = 4;
    dnt++;
    for(i=3;i<maxgt;i+=2)
    {
        if(d[i])
        {
            nt[dnt] = i;
            pnt[dnt] = i*i;
            dnt++;
            if(i < 216)
            {
                tmp = i*2;
                for(j=i*i;j<maxgt;j+=tmp)
                    d[j] = false;
            }
        }
    }
}
/**/
bool chk(long val)
{
    long i;
    if(val < maxgt)
    {
        if(d[val])
            return true;
        return false;
    }
    
    for(i=0; i<dnt && pnt[i] <= val; i++)
    {
        if(val % nt[i] == 0)
            return false;
    }
    return true;
}
/**/
void input()
{
    long l1,l2,u1,u2;
    long i;
    long xp,kt,minp,maxp,tmp,dau,cuoi;
    long da;
    
    _sieve();
    while(scanf("%ld %ld",&xp,&kt) == 2)
    {
        minp = 10000;
        maxp = 0;
        if(xp > kt)
            swap(xp,kt);
        da = 0;
        if(xp <= 2)
            a[da++] = 2;
        if(xp % 2 == 0)
            xp++;
        dau = 0;
        cuoi = kt - xp;
        for(i=dau;i<=cuoi;i+=2)
            if(chk(i+xp))
            {
                a[da++] = i+xp;
                if(da > 1)
                {
                    if(a[da-1] - a[da-2] > maxp)
                    {
                        maxp = a[da-1] - a[da-2];
                        l1 = a[da-2];
                        u1 = a[da-1];
                    }
                    
                    if(a[da-1] - a[da-2] < minp)
                    {
                        minp = a[da-1] - a[da-2];
                        l2 = a[da-2];
                        u2 = a[da-1];
                    }
                }
            }
        ///   
        if(maxp)     
            printf("%ld,%ld are closest, %ld,%ld are most distant.\n",l2,u2,l1,u1);
        else
            printf("There are no adjacent primes.\n");
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

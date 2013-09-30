/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "897.inp"
#define fo "897.out"
#define maxn 10000000
/**/
using namespace std;
/**/
bool use[maxn+10],d[maxn+10];
long nt[maxn],a[20],luu[20],kq[100];
long cnt;
int len,ckq;
bool aprime;
/**/
int xuly(long val)
{
    int i;
    i = 0;
    while(val != 0)
    {
        use[i] = true;
        a[i++] = val % 10;
        val /= 10;
    }
    return i;
}
/**/
void dfs(int id)
{
    int i;
    long val;
    
    if(id == len)
    {
        val = 0;
        for(i=0;i<id;i++)
        {
            val *= 10;
            val += luu[i];
        }
        if(!d[val])
            aprime = false;
        return;
    }
    
    for(i=0;i<len;i++)
        if(use[i])
        {
            use[i] = false;
            luu[id] = a[i];
            
            dfs(id+1);
            
            if(!aprime)
                return;
            
            use[i] = true;
        }
}
/**/
void _init()
{
    long i,j,k;
    
    for(i=0;i<=maxn;i++)
        d[i] = true;
    
    d[0] = false;
    d[1] = false;
    cnt = 0;
    for(i=2;i<=maxn;i++)
        if(d[i])
        {
            nt[cnt++] = i;
            if(i < 3163)
                for(j=i*i;j<=maxn;j+=i)
                    d[j] = false;
        }
    j = 0;
    for(i=0;i<cnt;i++)
    {
        len = xuly(nt[i]);
        aprime = true;
        dfs(0);
        if(aprime)
            kq[j++] = nt[i];
    }
    ckq = j;
}
/**/
void input()
{
    int i;
    long n,m;
    _init();
    while(scanf("%ld",&n) && n)
    {
        if(n >= kq[ckq-1])
        {
            printf("0\n");
            continue;
        }
        if(n < 10)
            m = 10;
        else if(n < 100)
            m = 100;
        else if(n < 1000)
            m = 1000;
        for(i=0;i<ckq;i++)
            if(kq[i] > n && kq[i] < m)
            {
                printf("%d\n",kq[i]);
                m = -1;
                break;
            }
        if(m != -1)
            printf("0\n");
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

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
#include <vector>

#define fi "12532.inp"
#define fo "12532.out"
/**/
using namespace std;
/**/
struct cay{
                long xp,kt;
                bool z;
                long neg;
            };
            
cay t[400000];
int a[100010];
long n,k;
char kq[100010];
/**/
void ctree(long id,long dau,long cuoi)
{
    long mid;
    
    t[id].xp = dau;
    t[id].kt = cuoi;
    
    if(dau == cuoi)
    {
        t[id].neg = 0;
        
        if(a[dau] == 0)
            t[id].z = true;
        else
            t[id].z = false;
            
        if(a[dau] < 0)
            t[id].neg++;
        return;   
    }
    
    mid = (dau + cuoi) / 2;
    
    ctree(id*2,dau,mid);
    ctree(id*2+1,mid+1,cuoi);
    
    t[id].neg = t[id*2].neg + t[id*2+1].neg;
    t[id].z = false;
    
    if(t[id*2].z || t[id*2+1].z)
        t[id].z = true;
}
/**/
void utree(long id,long vt)
{
    long mid;
    
    if(t[id].xp == t[id].kt)
    {
        t[id].neg = 0;
        
        if(a[t[id].xp] == 0)
            t[id].z = true;
        else
            t[id].z = false;
            
        if(a[t[id].xp] < 0)
            t[id].neg++;
        return;   
    }
    
    mid = (t[id].xp + t[id].kt) / 2;
    
    if(vt <= mid)
        utree(id*2,vt);
    else
        utree(id*2+1,vt);
        
    t[id].neg = t[id*2].neg + t[id*2+1].neg;
    t[id].z = false;
    
    if(t[id*2].z || t[id*2+1].z)
        t[id].z = true;
}
/**/
long ptree(long id,long dau,long cuoi)
{
    long mid;
    long val1,val2,val3;
    
    if(dau == t[id].xp && cuoi == t[id].kt)
    {
        if(t[id].z)
            return -1;
        return t[id].neg;
    }
    mid = (t[id].xp + t[id].kt) / 2;
    
    if(cuoi <= mid)
        val3 = ptree(id*2,dau,cuoi);
    else if(dau >= mid+1)
        val3 = ptree(id*2+1,dau,cuoi);
    else
    {
        val1 = ptree(id*2,dau,mid);
        val2 = ptree(id*2+1,mid+1,cuoi);
        if(val1 == -1 || val2 == -1)
            return -1;
        val3 = val1 + val2;
    }
    return val3;
}
/**/
void input()
{
    long i,j;
    long x,y,temp;
    char com[10];
    
    while(scanf("%ld %ld",&n,&k) == 2)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ctree(1,1,n);
        j = 0;
        for(i=1;i<=k;i++)
        {
            scanf("%s %ld %ld",&com,&x,&y);
            if(com[0] == 'C')
            {
                a[x] = y;
                utree(1,x);
            }
            else
            {
                temp = ptree(1,x,y);
                if(temp == -1)
                    kq[j++] = '0';
                else if(temp % 2 == 0)
                    kq[j++] = '+';
                else
                    kq[j++] = '-';
            }
        }
        kq[j] = 0;
        printf("%s\n",kq);
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

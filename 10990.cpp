/*
                                                        Hoang Linh
                
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10990.inp"
#define fo "10990.out"
#define maxn 2000000
/**/
using namespace std;
/**/
bool d[maxn+10];
long phi[maxn+10],dphi[maxn+10],nt[maxn];
long cnt;
/**/
long calphi(long val)
{
    long i,j;
    long luu[1000];
    long tmp;
    
    tmp = val;
    i = j = 0;
    
    while(i < cnt)
    {
        if(val % nt[i] == 0)
            luu[j++] = nt[i];
        
        while(val % nt[i] == 0)
            val /= nt[i];
        
        if(d[val])
        {
            luu[j++] = val;
            val = 1;
        }
        if(val == 1 || (i < cnt && (nt[i] * nt[i]) > val))
            break;
        i++;
    }
    val = 1;
    for(i=0;i<j;i++) // Euler's Totient Function and Euler's Theorem
    {
        val *= (luu[i] - 1);
        tmp /= luu[i];
    }
    return tmp * val;
}
/**/
void danhdau(long x)
{
    long i;
    if(x > 1414)
        return;
        
    for(i=x*x;i<=maxn;i+=x)
        d[i] = false;
}
/**/
void _init()
{
    long i,j;
    
    for(i=1;i<=maxn;i++)
    {
        d[i] = true;
        dphi[i] = 1;
    }
    
    d[1] = false;
    dphi[1] = 1;
    cnt = 0;
    
    for(i=2;i<=maxn;i++) // seive modified
    {
        if(d[i])    
        {
            phi[i] = i-1; // phi cua so ngto = songto - 1
            dphi[i] += dphi[phi[i]]; // tinh depth phi
            nt[cnt++] = i; // luu so nguyen to
            ////
            danhdau(i);
        }
        else
        {
            phi[i] = calphi(i); // tinh phi cua so nguyen
            dphi[i] += dphi[phi[i]];
        }
    }
    // cong don phi truoc vao phi sau
    dphi[1]--;
    for(i=2;i<=maxn;i++)
    {
        dphi[i]--;
        dphi[i] += dphi[i-1];
    }
}
/**/
void input()
{
    long i;
    int ntest;
    long n,m;
    long sdepth;
    
    _init();
    scanf("%d",&ntest);
    
    while(ntest--)
    {
        scanf("%ld %ld",&m,&n);
        sdepth = dphi[n] - dphi[m-1]; // tru khoang
        printf("%ld\n",sdepth);    
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

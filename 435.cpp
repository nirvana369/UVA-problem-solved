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

#define fi "435.inp"
#define fo "435.out"
/**/
using namespace std;
/**/
int phieu[22],d[1100],dang[22];
int tongsophieu,nuasophieu,p;
/**/
void output()
{
    int i;
    for(i=0;i<p;i++)
        printf("party %d has power index %d\n",i+1,dang[i]);
}
/**/
void init()
{
    int i;
    
    tongsophieu=0;
    for(i=0;i<p;i++)
        tongsophieu=tongsophieu+phieu[i];    
    nuasophieu=tongsophieu/2;

    for(i=0;i<=tongsophieu;i++)
        d[i]=0;
    d[0]=1;
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=tongsophieu;i++)
        d[i]=0;
    d[0]=1;
}
/**/
void danhdau(int vt)
{
    int i,j;
    for(i=0;i<p;i++)
    {
        if(i!=vt)
        {
            for(j=tongsophieu;j>=0;j--)
            {
                if(d[j]!=0)
                {
                    d[j+phieu[i]]=d[j+phieu[i]]+d[j];
                }
            }
        }
    }
}
/**/
void power(int vt)
{
    int i;
    int dem;
    dem=0;
    for(i=nuasophieu;i>=1;i--)
    {
        if(d[i]!=0)
        {
            if(i+phieu[vt]>nuasophieu)
            {
                dem=dem+d[i];
            }
        }
    }
    dang[vt]=dem;
}
/**/
void solve()
{
    int i;
    
    init();
    
    for(i=0;i<p;i++)
    {
       khoitao();
       danhdau(i);
       power(i); 
    }
    output();
}
/**/
void input()
{
    int itest,ip,ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d",&p);
        for(ip=0;ip<p;ip++)
            scanf("%d",&phieu[ip]);
        solve();
        printf("\n");
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


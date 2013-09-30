/*
                                                    Hoang Linh
                                        
                                        Problem: MISCHIEVOUS CHILDREN - 10338 (10338.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10338.inp"
#define fo "10338.out"
/**/
using namespace std;
/**/
int a[25],b[100],d[100];
/**/
void khoitao()
{
    int i;
    for(i=65;i<91;i++)
        d[i] = 0;
}
/**/
int ucln(int gta,int gtb)
{
    int r;
    while(gtb != 0)
    {
        r = gta % gtb;
        gta = gtb;
        gtb = r;
    }
    return gta;
}
/**/
void input()
{
    char temp[10000];
    int ntest;
    int id,l,dem,gt;
    int i,j,k;
    long long kq;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%s",&temp);
        khoitao();
        l = strlen(temp);
        for(i=0;i<l;i++)
        {
            d[temp[i]]++;
            a[i] = i + 1;
        }
        dem = 0;
        for(i=65;i<91;i++)
            if(d[i] > 1)
                for(j=2;j<=d[i];j++)
                {
                    b[dem] = j;    
                    dem++;
                }
        for(i=1;i<l;i++)
            for(j=0;j<dem;j++)
            {
                gt = ucln(a[i],b[j]);
                if(gt != 1)
                {
                    a[i] /= gt;
                    b[j] /= gt;
                }
            }
            
        kq = 1;
        for(i=0;i<l;i++)    
            kq *= a[i];
        printf("Data set %d: %lld\n",id,kq);
        id++;
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

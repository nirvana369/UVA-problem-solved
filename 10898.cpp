#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10898.inp"
#define fo "10898.out"
/**/
using namespace std;
/**/
int cb[10][10],gia[10],p[10],mon[10];
int ncombo,nmon,npeople;
long maxprice;
/**/
void solve()
{
    int i,j,k;
    int temp;
    long tong;
    bool thua;
    
    
    if(!ncombo)
    {
        maxprice = 0;
        for(k=0;k<nmon;k++)
            maxprice += p[k] * mon[k];
    }
    
    for(i=0;i<ncombo;i++)
    {
        j = 0;
        while(true)
        {
            thua = false;
            for(k=0;k<nmon;k++)
            {
                temp = cb[i][k] * j;
                if(temp > p[k])
                {
                    thua = true;
                    break;
                }
            }
            if(thua)
                break;
            j++;
        }
        j--;
        tong = j * gia[i];
        for(k=0;k<nmon;k++)
            tong += (p[k] - (cb[i][k] * j)) * mon[k];
        if(tong < maxprice)
            maxprice = tong;
    }
    printf("%ld\n",maxprice);
}
/**/
void input()
{
    int i,j;
    while(true)
    {
        nmon = -1;
        scanf("%d",&nmon);
        if(nmon == -1)
            break;
        for(i=0;i<nmon;i++)
            scanf("%d",&mon[i]);
        scanf("%d",&ncombo);
        for(i=0;i<ncombo;i++)
        {
            for(j=0;j<nmon;j++)
                scanf("%d",&cb[i][j]);
            scanf("%d",&gia[i]);
        }
        scanf("%d",&npeople);
        for(i=0;i<npeople;i++)
        {
            maxprice = 1000000000;
            for(j=0;j<nmon;j++)
                scanf("%d",&p[j]);
            solve();
            if(maxprice == 1000000000)
                printf("0\n");
        }
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

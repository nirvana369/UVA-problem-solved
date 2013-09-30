/*
                                            Hoang Linh
                                        
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "861.inp"
#define fo "861.out"
///////////////////////
using namespace std;
/**/
int n,k;
int d[10][10],cheot[60],cheop[60];
long white[60],black[60];
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j] = 0;
    
    for(i=1;i<20;i++)
    {
        cheot[i] = 0;
        cheop[i] = 0;
    }
    
    for(i=1;i<=k+1;i++)
    {
        black[i] = 0;
        white[i] = 0;
    }
}
/**/
void dequyw(int hang,int cot,int id)
{
    int i,j;
    
    if(id <= k)
        white[id]++;
    else 
        return;

    for(i=hang;i<=n;i++)
    {
        for(j=cot;j<=n;j=j+2)
        {
            if(d[i][j] == 0 && cheot[i-j+n] == 0 && cheop[i+j] == 0)
            {
                cheot[i-j+n] = 1;
                cheop[i+j] = 1;

                dequyw(i,j,id+1);

                cheot[i-j+n] = 0;
                cheop[i+j] = 0;
            }
        }
        if((i+1)%2 == 0)
            cot = 1;
        else
            cot = 2;
    }
}
/**/
void dequyb(int hang,int cot,int id)
{
    int i,j;
    
    if(id <= k)
        black[id]++;
    else 
        return;

    for(i=hang;i<=n;i++)
    {
        for(j=cot;j<=n;j=j+2)
        {
            if(d[i][j] == 0 && cheot[i-j+n] == 0 && cheop[i+j] == 0)
            {
                cheot[i-j+n] = 1;
                cheop[i+j] = 1;

                dequyb(i,j,id+1);

                cheot[i-j+n] = 0;
                cheop[i+j] = 0;
            }
        }
        if((i+1)%2 == 0)
            cot = 2;
        else
            cot = 1;
    }
}
/**/
void datw()
{
    int i,j;
    int temp;
    for(i=1;i<=n;i++)
    {
        if(i%2 == 0)
            temp = 1;
        else
            temp = 2;
        for(j=temp;j<=n;j=j+2)
        {
            d[i][j] = 1;
            cheot[i-j+n] = 1;
            cheop[i+j] = 1;
            dequyw(i,j,1);
            
            d[i][j] = 0;
            cheot[i-j+n] = 0;
            cheop[i+j] = 0;
        }
    }
}
/**/
void datb()
{
    int i,j;
    int temp;
    for(i=1;i<=n;i++)
    {
        if(i%2 == 0)
            temp = 2;
        else
            temp = 1;
        for(j=temp;j<=n;j=j+2)
        {
            d[i][j] = 1;
            cheot[i-j+n] = 1;
            cheop[i+j] = 1;
            dequyb(i,j,1);
            
            d[i][j] = 0;
            cheot[i-j+n] = 0;
            cheop[i+j] = 0;
        }
    }
}
/**/
void solve()
{
    int i,j;
    long long maxxep;
    datw();
    datb();
    
    maxxep = 0;
    for(i=1;i<k;i++)
        maxxep = maxxep + white[i] * black[k-i];
    maxxep = maxxep + white[k] + black[k];
    printf("%lld\n",maxxep);
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d",&n,&k);
        if(!n && !k)
            break;
        khoitao();
        if(k >= n*2)
            printf("0\n");
        else if(k == 0)
            printf("1\n");
        else
            solve();
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

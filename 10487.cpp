/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10487.inp"
#define fo "10487.out"
/**/
using namespace std;
/**/
long long t[4000000],a[1100];
long dt;
/**/
void swapt(int i,int j)
{
    long long temp;
    temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}
/**/
void utree(long i)
{
    if(i == 1)
        return;
    if(t[i] > t[i/2])
    {
        swapt(i,i/2);
        utree(i/2);
    }
}
/**/
void mtree(long i)
{
    if(i*2+1 <= dt)
    {
        if(t[i*2+1] > t[i*2])
        {
            if(t[i*2+1] > t[i])
            {
                swapt(i*2+1,i);
                mtree(i*2+1);
            }
        }
        else if(t[i*2] > t[i])
        {
            swapt(i*2,i);
            mtree(i*2);
        }
    }
    else if(i*2 <= dt)
    {
        if(t[i*2] > t[i])
        {
            swapt(i*2,i);
            mtree(i*2);
        }
    }
}
/**/
void solve()
{
    long i;
    long temp;
    dt--;
    temp = dt;
    
    while(dt != 0)
    {
        swapt(1,dt);
        dt--;
        mtree(1);
    }

    dt = temp;
    t[0] = t[1];
    t[dt+1] = t[dt];
}
/**/
void input()
{
    int i,id;
    int n,m;
    long long temp;
    long j;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        printf("Case %d:\n",id);
        dt = 1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            for(j=i-1;j>=0;j--)
            {
                t[dt] = a[i] + a[j];
                utree(dt);
                dt++;
            }
        }
        solve();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&temp);
            printf("Closest sum to %lld is ",temp);
            for(j=1;j<=dt;j++)
                if(t[j] == temp)
                {
                    printf("%lld",t[j]);
                    break;
                }
                else if(t[j] > temp)
                {
                    if(t[j] - temp <= temp - t[j-1])
                        printf("%lld",t[j]);
                    else
                        printf("%lld",t[j-1]);
                    break;
                }
            if(j == dt+1)
                printf("%lld",t[dt]);
            printf(".\n");
        }
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

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

#define fi "10742.inp"
#define fo "10742.out"
/**/
using namespace std;
/**/
int d[1000010];
long nt[100000],cnt[1000010];
long dnt;
/**/
void _init()
{
    long i,j;
    
    for(i=2;i<=1000000;i++)
        d[i] = 1;
        
    cnt[1] = 0;    
    dnt = 1;
    for(i=2;i<=1000000;i++)
        if(d[i])
        {
            cnt[i] = cnt[i-1] + 1;
            nt[dnt++] = i;
            
            if(i <= 1000)
                for(j=i*i;j<=1000000;j+=i)
                    d[j] = 0;
        }
        else
            cnt[i] = cnt[i-1];
}
/**/
void input()
{
    long i;
    long temp,n;
    long long countw;
    int id;
    
    _init();
    id = 1;
    while(scanf("%ld",&n))
    {
        if(!n)
            break;
        i = 1;
        countw = 0;
        while(i < dnt)
        {
            temp = cnt[n-nt[i]] - i;
            if(temp >= 1)
                countw += temp;
            else
                break;
            i++;
        }
        printf("Case %d: %lld\n",id++,countw);
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

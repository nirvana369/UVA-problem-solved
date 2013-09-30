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

#define fi "11621.inp"
#define fo "11621.out"
/**/
using namespace std;
/**/
priority_queue <long, vector <long>, greater <long> > pq;
long pf[400];
int id;
/**/
void precal()
{
    int i,j;
    long long maxgt,temp;
    id = 0;
    maxgt = (long)pow(2,31)-1;
    for(i=0;i<31;i++)
        for(j=0;j<20;j++)
        {
            temp = pow(2,i) * pow(3,j);
            if(temp > 0 && temp <= maxgt)
                pq.push(temp);
        }
    while(!pq.empty())
    {
        pf[id++] = pq.top();
        pq.pop();
    }
}
/**/
void input()
{
    int i;
    long long n;
    precal();
    while(true)
    {
        scanf("%lld",&n);
        if(!n)
            break;
        for(i=0;i<id;i++)
            if(pf[i] >= n)
            {
                printf("%ld\n",pf[i]);
                break;
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

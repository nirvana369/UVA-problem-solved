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

#define fi "10539.inp"
#define fo "10539.out"
#define maxgt 1000000000000ll
/**/
using namespace std;
/**/
priority_queue <long long, vector <long long>, greater <long long> > pq;
int nt[1000100];
long long al[100000];
long da,node;
/**/
long long expon(long val,long mu)
{
    int i;
    long long value;
    value = val;
    for(i=1;i<mu;i++)
        value *= val;
    return value;
}
/**/
void precal()
{
    long i,j;
    long long temp;

    while(!pq.empty())
        pq.pop();

    for(i=2;i<=1000000;i++)
        nt[i] = 0;

    for(i=2;i<=1000000;i++)
        if(nt[i] == 0)
        {
            if(i <= 1000)
                for(j=i*i;j<=1000000;j+=i)
                    nt[j] = 1;
            j = 2;
            while(true)
            {
                temp = expon(i,j);
                if(temp <= maxgt)
                    pq.push(temp);
                else
                    break;
                j++;
            }
        }
    da = 1;
    while(!pq.empty())
    {
        al[da++] = pq.top();
        pq.pop();
    }
}
/**/
void bins(long long val,long dau,long cuoi)
{
    long mid;
    if(dau == cuoi)
    {
        node = dau;
        return;
    }
    mid = (dau + cuoi) / 2;
    if(val < al[mid])
        bins(val,dau,mid);
    else if(val > al[mid])
        bins(val,mid+1,cuoi);
    else
    {
        node = mid;
        return;
    }
}
/**/
void input()
{
    long long val;
    int ntest;
    long cuoi,dau;
    
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lld",&val);
        bins(val,1,da-1);
        
        if(al[node] >= val)
            dau = node - 1;
        else
            dau = node;
        scanf("%lld",&val);
        bins(val,1,da-1);
        if(al[node] > val)
            cuoi = node - 1;
        else
            cuoi = node;
        printf("%ld\n",cuoi-dau);
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

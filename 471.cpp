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

#define fi "471.inp"
#define fo "471.out"
/**/
using namespace std;
/**/
long n,id;
int d[11];
long long num[9000000];
priority_queue <long long, vector <long long>, greater <long long> > pq;
/**/
void khoitao()
{
    int i;
    for(i=0;i<10;i++)
        d[i] = 0;
}
/**/
void dq(long long val)
{
    int i;
    
    num[id++] = val;
    
    if(val != 0)
        i = 0;
    else
        i = 1;
    while(i < 10)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            dq(val*10+i);
            d[i] = 0;
        }
        i++;
    }
}
/**/
void precal()
{
    id = 0;
    khoitao();
    dq(0);
}
/**/
bool kiemtra(long long val)
{
    khoitao();
    while(val != 0)
    {
        if(d[val % 10] == 0)
            d[val % 10] = 1;
        else
            return false;
        val /= 10;
    }
    return true;
}
/**/
void solve()
{
    long i;
    long long temp;
    while(!pq.empty())
        pq.pop();
    for(i=1;i<id;i++)
        if(num[i] % n == 0 && kiemtra(num[i]/n))
            pq.push(num[i]);
            
    while(!pq.empty())
    {
        temp = pq.top();
        cout << temp << " / " << temp / n << " = " << n << endl;
        pq.pop();
    }
}
/**/
void input()
{
    int ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        solve();
        if(ntest)
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

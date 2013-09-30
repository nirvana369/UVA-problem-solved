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

#define fi "11850.inp"
#define fo "11850.out"
/**/
using namespace std;
/**/
priority_queue <int, vector<int>, greater <int> > pq;
int a[2000];
/**/
bool solve()
{
    int i,j;
    int xp,fuel;
    
    xp = 0;
    fuel = 200;
    i = 0;
    while(!pq.empty())    
    {
        a[i++] = pq.top();
        pq.pop();
    }
    
    j = 0;
    while(j != i)
    {
        if(a[j] <= xp + fuel)
        {
            xp = a[j];
            fuel = 200;
            j++;
        }
        else
            break;
    } 
    
    if(xp + fuel < 1422)
        return false;

    fuel = xp + fuel - 1422;    
    xp = 1422;
    if(xp - fuel <= a[i-1])
        return true;
    else
        return false;
}
/**/
void input()    
{
    int tval;
    int n;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        while(!pq.empty())
            pq.pop();
        while(n--)
        {
            scanf("%d",&tval);
            pq.push(tval);
        }
        if(solve())
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
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

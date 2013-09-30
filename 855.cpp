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

#define fi "855.inp"
#define fo "855.out"
/**/
using namespace std;
/**/
priority_queue <int, vector <int>, less <int> > px;
priority_queue <int, vector <int>, less <int> > py;
int nhang,ncot;
long k;
/**/
void solve()
{
    int temp;
    int street,avenue;
    if(k % 2 != 0)
        temp = (k + 1) / 2;
    else
        temp = k / 2;
    
    while(k != temp)
    {
        px.pop();
        py.pop();
        k--;
    }
    street = px.top();
    avenue = py.top();
    printf("(Street: %d, Avenue: %d)\n",street,avenue);
}
/**/
void input()
{
    int ntest;
    long i;
    int x,y;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %ld",&nhang,&ncot,&k);
        while(!px.empty())
            px.pop();
        while(!py.empty())
            py.pop();
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&x,&y);
            px.push(x);
            py.push(y);
        }
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

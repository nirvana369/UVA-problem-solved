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

#define fi "10440.inp"
#define fo "10440.out"
/**/
using namespace std;
/**/
int car[2000];
int m,n,t;
/**/
void sapxep()
{
    int i,j;
    int temp;
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
            if(car[i] > car[j])
            {
                temp = car[i];
                car[i] = car[j];
                car[j] = temp;
            }
}
/**/
void solve()
{
    int i;
    int go,xp,dem;
    
    sapxep();
    go = xp = 0;
    for(i=(m+n-1)%n;i<m;i+=n)
    {
        go = xp > car[i] ? xp : car[i];
        xp = go + t * 2;
    }
    xp -= t;
    cout << xp << " " << (m+n-1)/n << endl;
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&n,&t,&m);
        for(i=0;i<m;i++)
            scanf("%d",&car[i]);
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

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

#define fi "11900.inp"
#define fo "11900.out"
/**/
using namespace std;
/**/
int n,p,q;
int egg[35];
/**/
void sapxep()
{
    int i,j;
    int temp;
    
    for(i=0;i<p;i++)
        for(j=i+1;j<n;j++)
            if(egg[i] > egg[j])
            {
                temp = egg[i];
                egg[i] = egg[j];
                egg[j] = temp;
            }
}
/**/
void solve(int id)
{
    int i,kq;
    
    for(i=0,kq=0;i<p;i++,kq++)
    {
        q -= egg[i];
        if(q < 0)
            break;
    }
    printf("Case %d: %d\n",id,kq);
}
/**/
void input()
{
    int i;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&egg[i]);
        p = n > p ? p : n; 
        sapxep();
        solve(id++);
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

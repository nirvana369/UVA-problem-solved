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

#define fi "1246.inp"
#define fo "1246.out"
#define maxgt 29000
/**/
using namespace std;
/**/
int nt[30000];
int dnt;
int l,h;
/**/
bool isnt(int val)
{
    int i;
    int temp,add;
    
    if(val == 2 || val == 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0 || val < 2)
        return false;
    temp = (int)sqrt(val);
    add = 2;

    for(i=5;i<=temp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;
}
/**/
void solve()
{
    int temp;
    int i,j;
    bool tontai;
    
    if(l > h)
    {
        temp = l;
        l = h;
        h = temp;
    }
    
    tontai = true;
    for(i=l;i<=h;i++)
        if(nt[i])
        {
            if(tontai)
            {
                printf("%d",i);
                tontai = false;
            }
            else
                printf(" %d",i);
        }
    if(tontai)
        printf("-1");
}
/**/
void precal()
{
    int i,j;
    for(i=0;i<=maxgt;i++)
        nt[i] = 1;
    nt[0] = nt[1] = 0;
    for(i=2;i<=maxgt;i++)
    {
        for(j=i;j<=maxgt;j+=i)
            nt[j]++;
    }
    for(i=1;i<=maxgt;i++)
        if(isnt(nt[i]))
            nt[i] = 1;
        else
            nt[i] = 0;
}
/**/
void input()
{
    int ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&l,&h);
        solve();
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

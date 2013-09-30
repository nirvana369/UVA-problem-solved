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

#define fi "10646.inp"
#define fo "10646.out"
/**/
using namespace std;
/**/
int val[30];
char c[53][3];
/**/
void solve(int id)
{
    int i;
    int vt,gt,kq;
    
    vt = 26;
    kq = 0;
    for(i=0;i<3;i++)
    {
        gt = val[vt--];
        kq += gt;
        vt -= 10 - gt;
    }
    if(kq >= vt)
        kq = kq - vt + 25;
    printf("Case %d: %s\n",id,c[kq]);
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
        for(i=0;i<52;i++)
        {
            scanf("%s",&c[i]);
            if(i < 27)
                val[i] = (c[i][0] >= '0' && c[i][0] <= '9') ? (c[i][0] - 48) : 10;
        }
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

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

#define fi "11074.inp"
#define fo "11074.out"
/**/
using namespace std;
/**/
int nhang,ncot,t,n,s;
/**/
void solve()
{
    int i,j,k,tn,tt,f,f1;
    f1 = 0;
    tn = 0;
    for(i=0;i<nhang;i++)
    {
        if(!f1)
        {
            if(tn == t)
            {
                f1 = 1;
                tn = 0;
            }
            k = 0;
            f = 0;
        }
        else
        {
            if(tn == s)
            {
                tn = 0;
                f1 = 0;
            }
            k = 0;
            f = 0;
        }
        for(j=0;j<ncot;j++)
        {
            if(f1)
            {
                if(!f)
                {
                    if(k < t)
                        printf("*");
                    else
                    {
                        printf(".");
                        k = 0;
                        f = 1;
                    }
                }
                else
                {
                    if(k < s)
                        printf(".");
                    else
                    {
                        printf("*");
                        k = 0;
                        f = 0;
                    }
                }
                k++;
            }
            else
                printf("*");
        }
        printf("\n");
        tn++;
    }
    printf("\n");
}
/**/
void input()
{
    int id;
    id = 1;
    while(scanf("%d %d %d",&s,&t,&n) == 3)
    {
        if(!s && !t && !n)
            break;
        nhang = n*s+((n+1)*t);
        ncot = nhang;
        printf("Case %d:\n",id++);
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

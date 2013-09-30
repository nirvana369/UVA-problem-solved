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

#define fi "402.inp"
#define fo "402.out"
/**/
using namespace std;
/**/
int n,x;
int card[21],d[52];
/**/
void solve()
{
    int i,j,id,dem;
    bool first;
    
    for(i=1;i<=n;i++)
        d[i] = 0;
        
    if(n > x)
    {
        i = 1;
        j = 0;
        id = n;
        dem = 0;
        while(id != x)
        {
            if(d[i] == 0)
            {
                dem++;
                if(dem == card[j])
                {
                    d[i] = 1;
                    id--;
                    dem = 0;
                }
            }
            i++;
            if(i > n)
            {
                i = 1;
                dem = 0;
                j++;
            }
            if(j == 20)
                break;
        }
    }
    first = false;
    for(i=1;i<=n;i++)
    {
        if(d[i] == 0)
        {
            if(first)
                printf(" ");
            printf("%d",i);
            first = true;
        }
    }
    printf("\n\n");
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        n = x = 0;
        scanf("%d %d",&n,&x);
        if(!n && !x)
            break;
        for(i=0;i<20;i++)
            scanf("%d",&card[i]);
        printf("Selection #%d\n",id++);
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

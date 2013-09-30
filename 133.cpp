/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "133.inp"
#define fo "133.out"
/**/
using namespace std;
/**/
int n,m,k;
/**/
void solve()
{
    bool a[25];
    int i;
    int pos1,pos2,tmp,d;
    
    for(i=1;i<=n;i++)
        a[i] = true;
    pos1 = 1;
    pos2 = n;
    tmp = 0;
    
    while(tmp < n)
    {
        d = 0;
        while(true)
        {
            if(a[pos1])
                d++;
            if(d == k)
                break;
            pos1++;
            if(pos1 > n)
                pos1 = 1;
        }
        
        d = 0;
        while(true)
        {
            if(a[pos2])
                d++;
            if(d == m)
                break;
            pos2--;
            if(pos2 == 0)
                pos2 = n;
        }
        a[pos1] = a[pos2] = false;
        if(pos1 == pos2)
        {
            tmp++;
            printf("%3d",pos1);
            if(tmp != n)
                printf(",");
        }
        else
        {
            tmp += 2;
            printf("%3d%3d",pos1,pos2);
            if(tmp != n)
                printf(",");
        }
    }
    printf("\n");
}
/**/
void input()
{
    while(scanf("%d %d %d",&n,&k,&m))
    {
        if(!n && !k && !m)
            break;
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

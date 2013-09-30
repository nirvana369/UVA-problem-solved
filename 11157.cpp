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

#define fi "11157.inp"
#define fo "11157.out"
/**/
using namespace std;
/**/
long stone[300];
long dist;
int dvt,n;
/**/
long getmax(long a,long b)
{
    return (a > b) ? a : b;
}
/**/
void input()
{
    int i;
    char s[100];
    char size;
    long pos,kq;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %ld",&n,&dist);
        
        stone[0] = 0;
        stone[1] = 0;
        dvt = 1;
        for(i=1;i<=n;i++)
        {
            scanf("%s",&s);
            sscanf(s,"%c-%ld",&size,&pos);
            stone[++dvt] = pos;
            if(size == 'B')
                stone[++dvt] = pos;
        }
        stone[++dvt] = dist;
        stone[++dvt] = dist;
        kq = 0;
        for(i=2;i<=dvt;i++)
            kq = getmax(stone[i]-stone[i-2],kq);
        printf("Case %d: %ld\n",id++,kq);
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

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

#define fi "10919.inp"
#define fo "10919.out"
/**/
using namespace std;
/**/
void input()
{
    int i,k,j;
    int n,nmeet,m;
    bool meet;
    char s[1000];
    map<string, int> mmap;
    
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        scanf("%d",&m);
        mmap.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",&s);
            mmap[s] = 1;
        }
        meet = true;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&k,&nmeet);
            for(j=0;j<k;j++)
            {
                scanf("%s",&s);
                if(meet)
                    if(mmap[s])
                        nmeet--;
            }
            if(nmeet > 0)
                meet = false;
        }
        if(meet)
            printf("yes\n");
        else
            printf("no\n");
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

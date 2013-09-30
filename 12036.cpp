/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12036.inp"
#define fo "12036.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest,id;
    int n,val;
    int i,j;
    int d[105];
    bool yes;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<101;i++)
            d[i] = 0;
            
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&val);
                d[val]++;
            }
        yes = true;
        for(i=0;i<101;i++)
            if(d[i] > n)
            {
                yes = false;
                break;
            }
            
        if(yes)
            printf("Case %d: yes\n",id++);
        else
            printf("Case %d: no\n",id++);
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

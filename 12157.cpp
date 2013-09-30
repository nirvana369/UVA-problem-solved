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

#define fi "12157.inp"
#define fo "12157.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest,id;
    int m,j,temp,n;
    int i;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        m = 0;
        j = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if((temp + 1) % 30 == 0)
                m += (temp + 1) / 30 * 10;
            else
                m += ((temp + 1) / 30 + 1) * 10;
                
            if((temp + 1) % 60 == 0)
                j += (temp + 1) / 60 * 15;
            else
                j += ((temp + 1) / 60 + 1) * 15;
        }
        printf("Case %d: ",id++);
        if(m == j)
            printf("Mile Juice %d\n",m);
        else if(m < j)
            printf("Mile %d\n",m);
        else
            printf("Juice %d\n",j);
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

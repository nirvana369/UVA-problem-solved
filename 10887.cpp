#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10887.inp"
#define fo "10887.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest,id,i,n,m;
    long kq;
    char temp[1000];
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        kq = n * m;
        gets(temp);
        n+=m;
        for(i=0;i<n;i++)
            gets(temp);
        printf("Case %d: %ld\n",id,kq);
        id++;
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

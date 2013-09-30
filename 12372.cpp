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

#define fi "12372.inp"
#define fo "12372.out"
/**/
using namespace std;
/**/
void input()
{
    int l,h,w;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d %d",&l,&h,&w);
        if(l > 20 || h > 20 || w > 20)
            printf("Case %d: bad\n",id++);
        else
            printf("Case %d: good\n",id++);
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

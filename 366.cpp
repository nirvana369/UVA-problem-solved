/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "366.inp"
#define fo "366.out"
/**/
using namespace std;
/**/
int dfsv(int s,int h)
{
    int h1,h2;
    if(h == 1)
        return dfsh(s,ncot);
    if(h <= size)
        return dfsh(h,ncot);
    
}
/**/
void input()
{
    while(scanf("%d %d %d",&size,&nhang,&ncot) && size && nhang && ncot)
    {
        kq = dfsv(1,nhang);
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

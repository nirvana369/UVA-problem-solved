/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11044.inp"
#define fo "11044.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    long nhang,ncot,kq;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&nhang,&ncot);
        kq = (nhang / 3) * (ncot / 3);
        printf("%ld\n",kq);
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

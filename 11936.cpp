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

#define fi "11936.inp"
#define fo "11936.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    int a,b,c;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a + b > c && a + c > b && b + c > a)
            printf("OK\n");
        else
            printf("Wrong!!\n");
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

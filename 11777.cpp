/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11777.inp"
#define fo "11777.out"
/**/
using namespace std;
/**/
void input()
{
    int a[10];
    int id,i;
    int temp;
    int ntest;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        for(i=0;i<4;i++)
            scanf("%d",&a[i]);
        a[4] = 0;
        a[5] = 0;
        for(i=0;i<3;i++)
        {
            scanf("%d",&temp);
            if(temp > a[4])
            {
                a[5] = a[4];
                a[4] = temp;
            }
            else if(temp > a[5])
                a[5] = temp;
        }
        a[4] = (a[4] + a[5]) / 2;
        for(i=1;i<5;i++)
            a[0] += a[i];
        printf("Case %d: ",id);
        if(a[0] < 60)
            printf("F\n");
        else if(a[0] < 70)
            printf("D\n");
        else if(a[0] < 80)
            printf("C\n");
        else if(a[0] < 90)
            printf("B\n");
        else
            printf("A\n");
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

/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10200.inp"
#define fo "10200.out"
/**/
using namespace std;
/**/
int d[10010];
/**/
bool isnt(long value)
{
    int i;
    int add,temp;
    
    temp = (int)sqrt(value);
    add = 2;
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    long temp;
    int i;
    int nt;
    nt = 0;
    for(i=0;i<=10000;i++)
    {
        temp = i * i + i + 41;
        if(isnt(temp))
        {
            nt++;
            d[i] = nt;
        }
        else
            d[i] = nt;
    }
}
/**/
void input()
{
    int i;
    int a,b,dnt;
    long temp;
    double kq;
    precal();
    while(true)
    {
        a = b = -1;
        scanf("%d %d",&a,&b);
        if(a < 0 && b < 0)
            break;
        if(a != 0)
            dnt = d[b] - d[a-1];
        else
            dnt = d[b];
        if(dnt != 0)
        {
            kq = (double)dnt / (b-a+1) * 100;
            printf("%0.2lf\n",kq+1e-7);
        }
        else
            printf("0.00\n");
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

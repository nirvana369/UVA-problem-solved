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

#define fi "347.inp"
#define fo "347.out"
/**/
using namespace std;
/**/
int d[15];
char kq[15];
long isround[10000010];
int maxround;
int l;
long value;
/**/
void khoitao()
{
    int i;
    for(i=0;i<l;i++)
        d[i] = 0;
}
/**/

bool kiemtra()
{
    int i,j;
    int x;
    int vt,temp;
    for(i=0;i<l;i++)
    {
        if(kq[i] == '0')
            return false;
        for(j=i+1;j<l;j++)
            if(kq[i] == kq[j])
                return false;
    }
    x = 0;
    vt = 0;
    temp = kq[0] - 48;
    khoitao();
    while(x != l)
    {
        temp += vt;
        temp %= l;
        if(d[temp] == 0)
        {
            d[temp] = 1;
            x++;
            vt = temp;
            temp = kq[vt] - 48;
        }
        else
            return false;
    }
    return true;
}
/**/
void precal()
{
    long i;
    maxround = 0;
    for(i=1;i<=9999999;i++)
    {
        sprintf(kq,"%ld",i);
        l = strlen(kq);
        if(kiemtra())
            isround[maxround++] = i;
    }
}
/**/
void input()
{
    int i;
    long id;
    id = 1;
    precal();
    while(true)
    {
        scanf("%ld",&value);
        if(!value)
            break;
        for(i=0;i<maxround;i++)
            if(value <= isround[i])
                break;
        printf("Case %ld: %ld\n",id++,isround[i]);
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

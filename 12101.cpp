/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12101.inp"
#define fo "12101.out"
/**/
using namespace std;
/**/
int d[11000],dd[11000],q[10000],nt[11000],kc[10000];
int value,dnt,a,b;
/**/
bool isnt(int giatri)
{
    int i;
    int temp,add;
    
    if(giatri % 2 == 0 || giatri % 3 == 0)
        return false;
    temp = (int)sqrt(giatri);
    add = 2;
    for(i=5;i<=temp;i+=add,add=6-add)
        if(giatri % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    int i;
    dnt = 0;
    for(i=1000;i<10000;i++)
        if(isnt(i))
        {
            d[i] = 1;
            dd[i] = 0;
            nt[dnt++] = i;
        }
        else
            d[i] = 0;
}
/**/
bool kiemtra(int gt)
{
    int i;
    int temp,n1;
    temp = gt % 1000;
    for(i=1000;i<10000;i+=1000)
    {
        value = i + temp;
        if(d[value] == 1 && dd[value] == 0)
            return true;
    }
    n1 = gt / 1000;
    n1 *= 1000;
    temp = gt % 100;
    for(i=0;i<1000;i+=100)
    {
        value = n1 + i + temp;
        if(d[value] == 1 && dd[value] == 0)
            return true;
    }
    n1 = gt / 100;
    n1 *= 100;
    temp = gt % 10;
    for(i=0;i<100;i+=10)
    {
        value = n1 + i + temp;
        if(d[value] == 1 && dd[value] == 0)
            return true;
    }
    n1 = gt / 10;
    n1 *= 10;
    for(i=1;i<10;i++)
    {
        value = n1 + i;
        if(d[value] == 1 && dd[value] == 0)
            return true;
    }
    return false;
}
/**/
int loang()
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    q[0] = a;
    dd[a] = 1;
    kc[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        while(kiemtra(q[dau]))
        {
            cuoi++;
            kc[cuoi] = kc[dau] + 1;
            q[cuoi] = value;
            dd[value] = 1;
            if(value == b)
                return kc[cuoi];
        }
    }
    return 0;    
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<dnt;i++)
        dd[nt[i]] = 0;
}
/**/
void input()
{
    int ntest;
    int temp;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&a,&b);
        if(a != b)
        {
            temp = loang();
            if(temp)
                printf("%d\n",temp);
            else
                printf("Impossible\n");
        }
        else
            printf("0\n");
        if(ntest != 0)
            khoitao();
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

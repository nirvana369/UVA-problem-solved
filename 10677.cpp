/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10677.inp"
#define fo "10677.out"
/**/
using namespace std;
/**/
int b1,b2,dau,cuoi,ds;
int s[1000];
/**/
long long getbac(int bac,int mu)
{
    int i;
    long long value;
    value = 1;
    for(i=0;i<mu;i++)
        value *= bac;
    return value;
}
/**/
long long doibase(int b)
{
    int i;
    long long value;
    
    value = 0;
    for(i=ds-1;i>=0;i--)
        value += s[i] * getbac(b,i);
    return value;
}
/**/
void chuyen(int value,int b)
{
    ds = 0;
    while(value != 0)
    {
        s[ds++] = value % b;
        value /= b;
    }
}
/**/
void solve()
{
    char temp[10];
    int i ;
    int l;
    long long vl1,vl2;
    bool exist;
    
    exist = false;
    for(i=cuoi;i!=dau;i--)
    {
        sprintf(temp,"%d",i);
        l = strlen(temp);
        
        chuyen(i,b1);

        vl1 = doibase(b1);
        vl2 = doibase(b2);
        if(vl2 % vl1 == 0)
        {
            exist = true;
            break;
        }
    }
    if(exist)
        printf("%d\n",i);
    else
        printf("Non-existent.\n");
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d %d",&b1,&b2,&dau,&cuoi);
        solve();
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

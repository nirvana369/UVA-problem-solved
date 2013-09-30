/*
                                            Hoang Linh
                                        
                                    Problem: BASICALLY SPEAKING - 389 (389.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "389.inp"
#define fo "389.out"
/**/
using namespace std;
/**/
char base[200],s1[20000];
int gt[200],a[200];
int b,nb;
/**/
void khoitao()
{
    int i;
    int dem;
    dem = 0;
    for(i='0';i<='9';i++,dem++)
    {
        gt[i] = dem;
        base[dem] = i;
    }
    for(i='A';i<='F';i++,dem++)
    {
        gt[i] = dem;
        base[dem] = i;
    }
}
/**/
long doibac(int giatri,int cs)
{
    int i;
    long value;
    if(cs == 0)
        return 1;
    value = giatri;
    for(i=0;i<cs-1;i++)
        value = value * giatri;
    return value;
}
/**/
void solve()
{
    int i;
    int l,bac;
    long long value;
    l = strlen(s1);
    bac = l-1;
    value = 0;
    for(i=0;i<l;i++,bac--)
        value = value + (long long)gt[s1[i]] * doibac(b,bac);
    if(nb != 10)
    {
        i = 0;
        while(value >= nb)
        {
            a[i] = value % nb;
            value = value / nb;
            i++;
        }
        a[i] = value;
        l = i;
        if(l > 6)
        {
            printf("  ERROR\n");
            return;
        }
        for(i=0;i<6-l;i++)
            printf(" ");
        for(i=l;i>=0;i--)
            printf("%c",base[a[i]]);
        printf("\n");
    }
    else
    {
        if(value > 9999999)
            printf("  ERROR\n");
        else
            printf("%7lld\n",value);
    }
}
/**/
void input()
{
    char temp[10000];
    khoitao();
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        sscanf(temp,"%s %d %d",&s1,&b,&nb);
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

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

#define fi "11787.inp"
#define fo "11787.out"
/**/
using namespace std;
/**/
long gt[7];
int d[100];
char s[600];
int len;
/**/
void khoitao()
{
    d['M'] = 6;
    gt[6] = 1000000;
    d['T'] = 5;
    gt[5] = 100000;
    d['F'] = 4;
    gt[4] = 10000;
    d['P'] = 3;
    gt[3] = 1000;
    d['S'] = 2;
    gt[2] = 100;
    d['U'] = 1;
    gt[1] = 10;
    d['B'] = 0;
    gt[0] = 1;
    d[32] = 7;
}
/**/
void daochuoi()
{
    char temp;
    int dau , cuoi;
    dau = 0;
    cuoi = len-1;
    while(dau < cuoi)
    {
        temp = s[dau];
        s[dau] = s[cuoi];
        s[cuoi] = temp;
        dau++;
        cuoi--;
    }
}
/**/
bool kiemtra()
{
    int i;
    int bac,dem;
    
    for(i=1;i<len;i++)
        if(d[s[i]] > d[s[0]])
        {
            daochuoi();
            break;
        }
    dem = 0;
    bac = d[s[0]];
    for(i=1;i<len;i++)
    {
        if(d[s[i]] < bac)
        {
            bac = d[s[i]];
            dem = 0;
        }
        else if(d[s[i]] > bac)
            return true;
        else
            dem++;
        if(dem > 8)
            return true;
    }
            
    return false;
}
/**/
void solve()
{
    int i;
    long long val;
    int dem,bac;
    
    val = 0;
    bac = d[s[0]];
    dem = 0;
    s[len] = ' ';
    for(i=0;i<=len;i++)
        if(d[s[i]] != bac)
        {
            val += gt[bac] * dem;
            bac = d[s[i]];
            dem = 1;
        }
        else
            dem++;
    printf("%lld\n",val);
}
/**/
void input()
{
    int ntest;
    khoitao();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        len = strlen(s);
        if(kiemtra())
            printf("error\n");
        else
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

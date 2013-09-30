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

#define fi "10551.inp"
#define fo "10551.out"
/**/
using namespace std;
/**/
char s[1100],s1[100];
int base;
/**/
long long laybac(int bac)
{
    int i;
    long long val;
    val = 1;
    for(i=0;i<bac;i++)
        val *= base;
    return val;
}
/**/
long long chuyenhe(char str[],int len)
{
    int i;
    long long val;
    val = 0;
    for(i=0;i<len;i++)
        val += (str[i] - 48) * laybac(len-i-1);
    return val;
}
/**/
void daochuoi(char str[],int dau,int cuoi)
{
    char temp;
    while(dau < cuoi)
    {
        temp = str[dau];
        str[dau] = str[cuoi];
        str[cuoi] = temp;
        dau++;
        cuoi--;
    }
}
/**/
int backbase(char str[],long long val)
{
    int i;
    i = 0;
    while(val != 0)
    {
        str[i++] = (val % base) + 48;
        val /= base;
    }
    daochuoi(str,0,i-1);
    return i;
}
/**/
void solve()
{
    int i,l;
    long long val,m;
    char temp[1100];
    i = 0;
    l = 0;
    m = chuyenhe(s1,strlen(s1));
    while(s[i] != 0)
    {
        temp[l++] = s[i];
        val = chuyenhe(temp,l);
        if(val >= m)
        {
            val %= m;
            l = backbase(temp,val);
        }
        i++;
    }
    m = chuyenhe(temp,l);
    if(m == 0)
    {
        temp[0] = '0';
        l = 1;
    }
    temp[l] = 0;
    printf("%s\n",temp);
}
/**/
void input()
{
    while(scanf("%d",&base))
    {
        if(!base)
            break;
        scanf("%s %s",&s,&s1);
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

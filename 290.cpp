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

#define fi "290.inp"
#define fo "290.out"
/**/
using namespace std;
/**/
int base[100],arr[10000];
/**/
bool kiemtra(int leng)
{
    int i;
    i = 0;
    while(i < leng)
    {
        if(arr[i] != arr[leng])
            return false;
        i++;
        leng--;
    }
    return true;
}
/**/
void chuyen(char s[])
{
    int l;
    int i;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= '0' && s[i] <= '9')
            arr[i] = s[i] - 48;
        else
            arr[i] = s[i] - 55;
}
/**/
int add(int he,int leng)
{
    int i,j;
    int temp[10000];
    for(i=0;i<=leng+10;i++)
        temp[i] = 0;
    
    for(i=0;i<=leng;i++)
    {
        temp[i] += arr[i] + arr[leng-i];
        temp[i+1] += temp[i] / he;
        temp[i] = temp[i] % he;
    }
    
    for(i=leng+10;i>=0;i--)
    {
        if(temp[i] != 0)
        {
            for(j=0;j<=i;j++)
                arr[j] = temp[j];
            return i+1;
        }
    }
}
/**/
void solve(char s[])
{
    int i;
    int l,tg;
    int maxbase,dem;
    bool first;
    
    first = false;
    tg = strlen(s);
    
    maxbase = 2;
    for(i=0;i<tg;i++)
        if(base[s[i]] > maxbase)
            maxbase = base[s[i]];
    for(i=15;i>=maxbase;i--)
    {
        if(first)
            printf(" ");
        dem = 0;
        l = tg;
        chuyen(s);
        while(true)
        {
            if(kiemtra(l-1))
                break;
            l = add(i,l-1);
            dem++;
        }
        printf("%d",dem);
        first = true;
    }
    
    for(i=maxbase-1;i>=2;i--)
    {
        if(first)
            printf(" ");
        printf("?");
        first = true;
    }
    printf("\n");
}
/**/
void khoitao()
{
    int i,b;
    b = 1;
    for(i='0';i<='9';i++)
        base[i] = b++;
    for(i='A';i<='F';i++)
        base[i] = b++;
}
/**/
void input()
{
    char temp[1000];
    khoitao();
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        solve(temp);
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

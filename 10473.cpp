/*
                                                Hoang Linh
                                                
                                    Problem: SIMPLE BASE CONVERSION - 10473 (10473.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10473.inp"
#define fo "10473.out"
/**/
using namespace std;
/**/
int doihex(char kt)
{
    if(kt >= 'A' && kt <= 'F')
        return kt - 55;
    return kt - 48;
}
/**/
void hextodec(char s[])
{
    int i;
    int l;
    long long value;
    
    value = 0;
    l = strlen(s);
    for(i=2;i<l;i++)
    {
        value *= 16;
        value += doihex(s[i]);
    }
    printf("%lld\n",value);
}
/**/
void indec(int gt)
{
    if(gt < 10)
        printf("%d",gt);
    else
        printf("%c",gt+55);
}
/**/
void dectohex(char s[])
{
    int i;
    int a[1000];
    long long value;
    int dem;
    sscanf(s,"%lld",&value);
    dem = 0;
    
    while(value >= 16)
    {
        a[dem] = (int)value % 16;
        value /= 16;
        dem++;
    }
    a[dem] = (int)value;
    printf("0x");
    for(i=dem;i>=0;i--)
        indec(a[i]);
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        scanf("%s",&temp);
        if(temp[0] == '-')
            break;
        if(temp[0] == '0' && temp[1] == 'x')
            hextodec(temp);
        else
            dectohex(temp);
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

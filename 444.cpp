/*
                                                Hoang Linh
                                        
                                   Problem: ENCODER AND DECODER - 444 (444.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "444.inp"
#define fo "444.out"
/**/
using namespace std;
/**/
int a[1000];
/**/
bool kiemtra(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= '0' && s[i] <= '9')
            return true;
    return false;
}
/**/
void decode(char s[])
{
    int i,j;
    int l;
    int value;
    l = strlen(s)-1;
    for(i=l;i>=0;i--)
    {
        if(s[i] == '1')
        {
            value = 0;
            for(j=i;j>=i-2;j--)   
            {
                value *= 10 ;
                value += (s[j] - 48);
            }
            i = i - 2;
            printf("%c",value);
        }
        else
        {
            value = 0;
            for(j=i;j>=i-1;j--)   
            {
                value *= 10 ;
                value += (s[j] - 48);
            }
            printf("%c",value);
            i = i - 1;
        }
    }
    printf("\n");
}
/**/
void dao(int dau,int cuoi)
{
    int temp;
    while(dau < cuoi)
    {
        temp = a[dau];
        a[dau] = a[cuoi];
        a[cuoi] = temp;
        dau++;
        cuoi--;
    }
}
/**/
void encode(char s[])
{
    int i;
    int l,dem,dau;
    int value;
    l = strlen(s);
    dem = 0;
    for(i=0;i<l;i++)
    {
        value = s[i];
        dau = dem;
        while(value != 0)
        {
            a[dem] = value % 10;
            value = value / 10;
            dem++;
        }
        dao(dau,dem-1);
    }
    for(i=dem-1;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        gets(temp);
        if(feof(stdin))
            break;
        if(kiemtra(temp))
            decode(temp);
        else
            encode(temp);
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

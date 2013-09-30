/*
                                                            Hoang Linh
                                                    
                                            Problem: I LOVE BIG NUMBERS ! - 10220 (10220.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10220.inp"
#define fo "10220.out"
/**/
using namespace std;
/**/
int gt[1010];
int l1,l2;
/**/
int chuyen(int value,char s[])
{
    int dem;
    dem = 0;
    while(value != 0)
    {
        s[dem] = value % 10 + 48;
        value = value / 10;
        dem++;
    }
    s[dem] = 0;
    return dem;
}
/**/
void mul(int id,char s1[],char s2[])
{
    int arr[32000];
    int l;
    int i,j;
    
    l = l1 + l2;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] = arr[i+j] + (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] = arr[i+j+1] + arr[i+j] / 10;
                arr[i+j] = arr[i+j] % 10;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
            {
                gt[id] = gt[id] + arr[j];
                s1[j] = arr[j] + 48;
            }
            l1 = i+1;
            return;
        }
}
/**/
void precal()
{
    int i;
    char temp[32000],temp1[32000];
    
    gt[1] = 1;
    gt[2] = 2;
    gt[3] = 6;
    gt[4] = 24;
    
    temp[0] = '4';
    temp[1] = '2';
    temp[2] = 0;
    l1 = 2;
    for(i=5;i<=1000;i++)
    {
        gt[i] = 0;
        l2 = chuyen(i,temp1);
        mul(i,temp,temp1);
    }
}
/**/
void input()
{
    int n;
    precal();
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        printf("%d\n",gt[n]);
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

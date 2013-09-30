/*
                                        Hoang Linh
                                        
                                Problem: COUNTING - 10198 (10198.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10198.inp"
#define fo "10198.out"
/**/
using namespace std;
/**/
char a[1100][1000];
/**/
void khoitao()
{
    strcpy(a[1],"2");
    strcpy(a[2],"5");
    strcpy(a[3],"31");
}
/**/
void mul(char s[],char s1[])
{
    int i,j;
    int arr[1000];
    int l;
    l = strlen(s);
    for(i=0;i<=l+2;i++)
        arr[i] = 0;
    for(i=0;i<l;i++)
    {
        arr[i] = arr[i] + (s[i] - 48) * 2;
        if(arr[i] > 9)
        {
            arr[i+1] = arr[i] / 10;
            arr[i] = arr[i] % 10;
        }
    }
    for(i=l+2;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
            s1[i+1] = 0;
            break;
        }
}
/**/
void add(char s[],char s1[])
{
    int i,j;
    int l,l1,maxl;
    int arr[1000];
    
    l = strlen(s);
    l1 = strlen(s1);
    maxl = l1 + l;
    for(i=0;i<=maxl;i++)
        arr[i] = 0;
        
    for(i=0;i<l;i++)
    {
        if(i < l1)
        {
            arr[i] = arr[i] + (s[i] - 48) + (s1[i] - 48);
            if(arr[i] > 9)
            {
                arr[i] = arr[i] % 10;
                arr[i+1]++;
            }
        }
        else
        {
            arr[i] = arr[i] + (s[i] - 48);
            if(arr[i] > 9)
            {
                arr[i] = arr[i] % 10;
                arr[i+1]++;
            }
        }
    }
    
    for(i=maxl;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s[j] = arr[j] + 48;
            s[i+1] = 0;
            return;
        }
}
/**/
void precal()
{
    int i,j;
    
    khoitao();
    for(i=4;i<=1000;i++)
    {
        mul(a[i-1],a[i]);
        add(a[i],a[i-2]);
        add(a[i],a[i-3]);
    }
}
/**/
void input()
{
    int i;
    int n,l;
    precal();
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        l = strlen(a[n]);
        for(i=l-1;i>=0;i--)
            printf("%c",a[n][i]);
        printf("\n");
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

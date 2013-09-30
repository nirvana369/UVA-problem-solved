/*
                                            Hoang Linh
                                            
                                Problem: FIBONACCI NUMBERS - 10579 (10579.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10579.inp"
#define fo "10579.out"
/**/
using namespace std;
/**/
char f[5000][1100];
int len[5000];
/**/
void add(char s1[],int l1,char s2[],int l2,char s[],int id)
{
    int i,j;
    int maxl;
    int arr[10000];
    
    maxl = l1 + l2;
    for(i=maxl;i>=0;i--)
        arr[i] = 0;
    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] = arr[i] + (s1[i] - 48) + (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i] = arr[i] % 10;
                arr[i+1]++;
            }
        }
        else
        {
            arr[i] = arr[i] + (s1[i] - 48);
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
            len[id] = i + 1;
            return;
        }
}
/**/
void precal()
{
    int i;
    f[1][0] = '1';
    f[2][0] = '1';
    len[1] = 1;
    len[2] = 1;
    i = 3;
    while(true)
    {
        add(f[i-1],len[i-1],f[i-2],len[i-2],f[i],i);
        if(len[i] == 1001)
            break;
        i++;
    }
}
/**/
void input()
{
    int i;
    int n;
    precal();    
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=len[n]-1;i>=0;i--)
            printf("%c",f[n][i]);
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

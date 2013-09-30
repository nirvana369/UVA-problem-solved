/*
                                                Hoang Linh
                                                
                                    Problem: RAY THROUGH GLASSES - 10334 (10334.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10334.inp"
#define fo "10334.out"
/**/
using namespace std;
/**/
char f[1100][1000];
int len[1100];
/**/
void add(char s1[],int l1,char s2[],int l2,char s[],int id)
{
    int i,j;
    int arr[1000];
    int maxl;
    
    maxl = l1 + l2;
    for(i=maxl;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] += (s1[i] - 48) + (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i] = arr[i] % 10;
                arr[i+1]++;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
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
            len[id] = i+1;
            return;
        }
}
/**/
void precal()
{
    int i;
    f[0][0] = '1';
    f[1][0] = '2';
    f[2][0] = '3';
    f[3][0] = '5';
    f[4][0] = '8';
    
    for(i=0;i<5;i++)
        len[i] = 1;
    
    for(i=5;i<1001;i++)
        add(f[i-1],len[i-1],f[i-2],len[i-2],f[i],i);
}
/**/
void input()
{
    int n;
    int i;
    precal();
    while(scanf("%d",&n) == 1)
    {
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

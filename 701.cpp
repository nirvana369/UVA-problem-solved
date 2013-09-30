/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "701.inp"
#define fo "701.out"
/**/
using namespace std;
/**/
char pow2[40][100];
/**/
void _init()
{
    int i,j,k;
    char s[100];
    long long val,gt;
    
    val = 8;
    for(i=4;i<=31;i++)
    {
        val *= 2;
        gt = val;
        j = 0;
        
        while(gt)
        {
            s[j++] = gt % 10 + 48;
            gt /= 10;
        }
        
        for(k=0;k<j;k++)        
            pow2[i][k] = s[j-k-1];
        pow2[i][k] = 0;
    }
}
/**/
void solve(char s[])
{
    int i,j,k;
    int l1,l2;
    
    for(i=4;i<=31;i++)
    {
        j = 0;
        k = 0;
        while(s[j] && pow2[i][k])
        {
            if(s[j] != pow2[i][k])
                break;
            j++;
            k++;
        }
        
        l1 = j;
        l2 = k;
        
        while(s[l1])
            l1++;
        while(pow2[i][l2])
            l2++;
        
        if(!s[j] && (l2 / 2 + l2 % 2) > l1)
        {
            printf("%d\n",i);
            return;
        }
    }
    printf("no power of 2\n");
}
/**/
void input()
{
    char s[100];
    _init();
    
    while(scanf("%s",&s) == 1)
        solve(s);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

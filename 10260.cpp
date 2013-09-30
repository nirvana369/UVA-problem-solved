/*
                                                Hoang Linh
                                                
                                    Problem: SOUNDEX - 10260 (10260.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10260.inp"
#define fo "10260.out"
/**/
using namespace std;
/**/
int gt[100];
/**/
void khoitao()
{
    gt['B'] = 1;  gt['P'] = 1;  gt['F'] = 1;  gt['V'] = 1;
    gt['C'] = 2;  gt['G'] = 2;  gt['J'] = 2;  gt['K'] = 2;  gt['Q'] = 2;  gt['S'] = 2;  gt['X'] = 2;  gt['Z'] = 2;
    gt['D'] = 3;  gt['T'] = 3;
    gt['L'] = 4;
    gt['M'] = 5;  gt['N'] = 5;
    gt['R'] = 6;
    gt['A'] = 7;  gt['E'] = 7;  gt['I'] = 7;  gt['O'] = 7;  gt['U'] = 7;  gt['H'] = 7;  gt['W'] = 7;  gt['Y'] = 7;
}
/**/
void solve(char s[])
{
    int a[30];
    int i,j;
    int l,temp;
    l = strlen(s);
    for(i=0;i<l;i++)
        a[i] = gt[s[i]];
    
    for(i=0;i<l;i++)
        if(a[i] != 7)
        {
            temp = a[i];
            printf("%d",a[i]);
            for(j=i+1;j<l;j++)
                if(a[j] != temp)
                {
                    temp = a[j];
                    if(a[j] != 7)
                        printf("%d",a[j]);
                }
            break;
        }
    printf("\n");
}
/**/
void input()
{
    char temp[100];
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

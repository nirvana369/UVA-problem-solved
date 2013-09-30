/*
                                                    Hoang Linh
                                                
                                    Problem: FIND THE TELEPHONE - 10921 (10921.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10921.inp"
#define fo "10921.out"
/**/
using namespace std;
/**/
char p[100];
/**/
void khoitao()
{
    p['A'] = '2';   p['B'] = '2';   p['C'] = '2';
    p['D'] = '3';   p['E'] = '3';   p['F'] = '3';
    p['G'] = '4';   p['H'] = '4';   p['I'] = '4';
    p['J'] = '5';   p['K'] = '5';   p['L'] = '5';
    p['M'] = '6';   p['N'] = '6';   p['O'] = '6';
    p['P'] = '7';   p['Q'] = '7';   p['R'] = '7';     p['S'] = '7';
    p['T'] = '8';   p['U'] = '8';   p['V'] = '8';
    p['W'] = '9';   p['X'] = '9';   p['Y'] = '9'; p['Z'] = '9';
}
/**/
void solve(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            printf("%c",p[s[i]]);
        else
            printf("%c",s[i]);
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    khoitao();
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
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

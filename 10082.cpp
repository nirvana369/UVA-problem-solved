/*
                                                Hoang Linh

                                    Problem: WERTYU - 10082 (10082.*)                                  
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10082.inp"
#define fo "10082.out"
/**/
using namespace std;
/**/
char mh[200];
/**/
void khoitao()
{
    mh['/'] = '.';    mh['C'] = 'X';    mh['J'] = 'H';    mh['\\'] = ']';
    mh['.'] = ',';    mh['X'] = 'Z';    mh['H'] = 'G';    mh[']'] = '[';    
    mh[','] = 'M';    mh['Z'] = 'Z';   mh['G'] = 'F';    mh['['] = 'P';
    mh['M'] = 'N';    mh['\''] = ';';   mh['F'] = 'D';    mh['P'] = 'O';
    mh['N'] = 'B';    mh[';'] = 'L';    mh['D'] = 'S';    mh['O'] = 'I';
    mh['B'] = 'V';    mh['L'] = 'K';    mh['S'] = 'A';    mh['I'] = 'U';
    mh['V'] = 'C';    mh['K'] = 'J';    mh['A'] = 'A';    mh['U'] = 'Y';
    
    mh['Y'] = 'T';    mh['T'] = 'R';    mh['R'] = 'E';    mh['E'] = 'W';
    mh['W'] = 'Q';    mh['Q'] = 'Q';    mh['='] = '-';    mh['-'] = '0';
    mh['0'] = '9';    mh['9'] = '8';    mh['8'] = '7';    mh['7'] = '6';
    mh['6'] = '5';    mh['5'] = '4';    mh['4'] = '3';    mh['3'] = '2';
    mh['2'] = '1';    mh['1'] = '`';    mh['`'] = '`';
}
/**/
void solve(char s[])
{
    int i;
    int l;
    l = strlen(s);
    
    for(i=0;i<l;i++)
        if(s[i] != ' ')
            printf("%c",mh[s[i]]);
        else
            printf("%c",s[i]);
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
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

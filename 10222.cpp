/*
                                                        Hoang Linh
                                                    
                                        Problem: DECODE THE MAD MAN - 10222 (10222.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10222.inp"
#define fo "10222.out"
/**/
using namespace std;
/**/
char kt[500];
/**/
void khoitao()
{
    int i;
    int l;
    char temp[1000];
    strcpy(temp,"/.,mnbvcxz\\';lkjhgfdsa][poiuytrewq");
    
    l = strlen(temp);
    kt[32] = 32;
    for(i=0;i<l-2;i++)
        kt[temp[i]] = temp[i+2];
}
/**/
void solve(char s[])
{
    int i,l;
    
    l = strlen(s);
    
    for(i=0;i<l;i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
        printf("%c",kt[s[i]]);
    }
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

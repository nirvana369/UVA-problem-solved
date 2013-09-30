/*
                                                    Hoang Linh
                                                
                                    Problem: WHAT'S THE FREQUENCY, KENNETH? - 499 (499.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "499.inp"
#define fo "499.out"
/**/
using namespace std;
/**/
int d[200];
int maxf;
/**/
void khoitao()
{
    int i;
    for(i=65;i<130;i++)
        d[i] = 0;
    maxf = 0;
}
/**/
void xuly(char s[])
{
    char temp[1000];
    int i;
    int l,dem;
    
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            d[s[i]]++;
            if(d[s[i]] > maxf)
                maxf = d[s[i]];
        }
    dem = 0;
    for(i='A';i<='Z';i++)
        if(d[i] == maxf)
        {
            temp[dem] = i;
            dem++;
        }
    for(i='a';i<='z';i++)
        if(d[i] == maxf)
        {
            temp[dem] = i;
            dem++;
        }
    temp[dem] = 0;
    printf("%s %d\n",temp,maxf);
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        khoitao();
        xuly(temp);
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

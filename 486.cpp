/*
                                                                Hoang Linh            
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "486.inp"
#define fo "486.out"
/**/
using namespace std;
/**/
long getvalue(char s[])
{
    if(s[0] == 'z')
        return 0;
    if(s[0] == 'o')
        return 1;
    if(strcmp(s,"two") == 0)
        return 2;
    if(strcmp(s,"three") == 0)
        return 3;
    if(strcmp(s,"four") == 0)
        return 4;
    if(strcmp(s,"five") == 0)
        return 5;
    if(strcmp(s,"six") == 0)
        return 6;
    if(strcmp(s,"seven") == 0)
        return 7;
    if(strcmp(s,"eight") == 0)
        return 8;
    if(strcmp(s,"nine") == 0)
        return 9;
    if(strcmp(s,"ten") == 0)
        return 10;
    if(strcmp(s,"eleven") == 0)
        return 11;
    if(strcmp(s,"twelve") == 0)
        return 12;
    if(strcmp(s,"thirteen") == 0)    
        return 13;
    if(strcmp(s,"fourteen") == 0)
        return 14;
    if(strcmp(s,"fifteen") == 0)
        return 15;
    if(strcmp(s,"sixteen") == 0)
        return 16;
    if(strcmp(s,"seventeen") == 0)
        return 17;
    if(strcmp(s,"eighteen") == 0)
        return 18;
    if(strcmp(s,"nineteen") == 0)
        return 19;
    if(strcmp(s,"twenty") == 0)
        return 20;
    if(strcmp(s,"thirty") == 0)
        return 30;
    if(strcmp(s,"forty") == 0)
        return 40;
    if(strcmp(s,"fifty") == 0)
        return 50;
    if(strcmp(s,"sixty") == 0)
        return 60;
    if(strcmp(s,"seventy") == 0)
        return 70;
    if(strcmp(s,"eighty") == 0)
        return 80;
    if(strcmp(s,"ninety") == 0)
        return 90;
    return 1;
}
/**/
void solve(char s[])
{
    int i;
    int l,dem,flag;
    char temp[10000];
    long value,gt,t,h,m;
    
    t = h = m = 0;
    value = 0;
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    gt = 0;
    flag = 1;
    for(i=0;i<=l;i++)
        if(s[i] != ' ')
            temp[dem++] = s[i];
        else if(dem != 0)
        {
            temp[dem] = 0;
            if(strcmp(temp,"negative") == 0)
                flag = -1;
            else if(strcmp(temp,"thousand") == 0)
            {
                t += h + gt;
                t = t * 1000;
                h = 0; 
                gt = 0;
            }
            else if(strcmp(temp,"hundred") == 0)
            {
                h = gt * 100;
                gt = 0;
            }
            else if(strcmp(temp,"million") == 0)
            {
                m += h + t + gt;
                m *= 1000000;
                h = 0;
                t = 0;
                gt = 0;
            }   
            else
                gt += getvalue(temp);
            dem = 0;
        }
    
    value = m + h + t + gt;
    value *= flag;
    printf("%ld\n",value);
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

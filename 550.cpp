/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "550.inp"
#define fo "550.out"
/**/
using namespace std;
/**/
int num[200];
/**/
void _init()
{
    int i,j;
    j = 0;
    for(i='0';i<='9';i++)
        num[i] = j++;
    for(i='A';i<='Z';i++)
        num[i] = j++;
}
/**/
long cvt(char s[])
{
    int i;
    int val;
    val = 0;
    i = 0;
    while(s[i])
    {
        val *= 10;
        val += num[s[i]];
        i++;
    }
    return val;
}
/**/
void input()
{
    long last,val,tmp,gt;
    int step,b;
    char s1[100],s2[100];
    _init();
    while(scanf("%d %s %s",&b,&s1,&s2) == 3)
    {
        last = cvt(s1);
        val = cvt(s2);
        gt = step = 0;
        tmp = last;
        while(true)
        {
            step++;
            gt += tmp * val;
            if(gt == last)
                break;
            tmp = gt % b;
            gt = gt / b;
        }
        printf("%d\n",step);
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

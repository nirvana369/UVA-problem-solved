/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "12195.inp"
#define fo "12195.out"
/**/
using namespace std;
/**/
map <char, float> mmap;
/**/
void solve(char s[])
{
    int i;
    int l;
    float sum,bigsum;
    l = strlen(s);
    bigsum = sum = 0;
    for(i=0;i<l;i++)
        if(s[i] == '/')
        {
            if(sum == 1)
                bigsum += sum;
            sum = 0;
        }
        else
            sum += mmap[s[i]];
            
    printf("%ld\n",(long)bigsum);
}
/**/
void khoitao()
{
    mmap.clear();
    mmap['W'] = (float)1;
    mmap['H'] = (float)1/2;
    mmap['Q'] = (float)1/4;
    mmap['E'] = (float)1/8;
    mmap['S'] = (float)1/16;
    mmap['T'] = (float)1/32;
    mmap['X'] = (float)1/64;
}
/**/
void input()
{
    char temp[300];
    khoitao();
    while(true)
    {
        gets(temp);
        if(temp[0] == '*' && strlen(temp) == 1)
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

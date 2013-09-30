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
#include <vector>

#define fi "12543.inp"
#define fo "12543.out"
/**/
using namespace std;
/**/
char kq[110],temp[110],s[11000];
int len,dem;
bool quit;
/**/
void copstr()
{
    int i;
    i = 0;
    while(i < dem)
    {
        if(temp[i] >= 'A' && temp[i] <= 'Z')
            kq[i] = temp[i] + 32;
        else
            kq[i] = temp[i];
        i++;
    }
    kq[i] = 0;
}
/**/
void xuly()
{
    int i;
    
    i = 0;
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] == '-')
            temp[dem++] = s[i];
        else
        {
            temp[dem] = 0;
            if(strcmp(temp,"E-N-D") == 0)
            {
                quit = true;
                return;
            }
            if(dem > len)
            {
                copstr();
                len = dem;
            }
            dem = 0;
        }
        i++;
    }
        
    if(dem != 0 && temp[dem-1] != '-')
    {
        temp[dem] = 0;
        if(strcmp(temp,"E-N-D") == 0)
        {
            quit = true;
            return;
        }
        if(dem > len)
        {
            copstr();
            len = dem;
        }
        dem = 0;
    }
}
/**/
void input()
{
    dem = 0;
    len = 0;
    quit = false;
    kq[len] = 0;
    while(true)
    {
        gets(s);
        xuly();
        if(quit)
        {
            printf("%s\n",kq);
            break;
        }
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

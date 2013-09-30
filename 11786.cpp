/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "11786.inp"
#define fo "11786.out"
/**/
using namespace std;
/**/
int h[20100];
char s[10010];
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<=20010;i++)
        h[i] = 0;
}
/**/
void solve()
{
    int i,vt;
    long water;
    
    khoitao();
    
    i = 0;
    vt = 10005;
    water = 0;
    while(s[i])
    {
        if(s[i] == '\\')
        {
            h[vt] = i + 1;
            vt--;
        }
        else if(s[i] == '/')
        {
            vt++;
            if(h[vt])
            {
                water += (i - h[vt]) + 1;
                h[vt] = 0;
            }
        }
        i++;   
    }
    printf("%ld\n",water);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        solve();
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

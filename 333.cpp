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

#define fi "333.inp"
#define fo "333.out"
/**/
using namespace std;
/**/
int a[200];
char s[1000];
/**/
void solve()
{
    int i,j;
    int l,id,dem,st,kt;
    char kq[200];
    l = strlen(s);
    id = 0;
    st = kt = l;
    for(i=0;i<l;i++)
        if(s[i] != ' ')
        {
            st = i;
            break;
        }
        
    for(i=l-1;i>=0;i--)
        if(s[i] != ' ')
        {
            kt = i;
            break;
        }
        
    for(i=st,j=0;i<=kt;i++,j++)
    {
        kq[j] = s[i];
        if(s[i] >= '0' && s[i] <= '9' || s[i] == 'X')
        {
            if(s[i] == 'X' && id == 9)
                a[id++] = 10;
            else if(s[i] != 'X')
                a[id++] = s[i] - 48;
        }
    }
    kq[j] = 0;
    
    if(id == 10)
    {
        for(i=1;i<id;i++)
            a[i] += a[i-1];
            
        for(i=1;i<id;i++)
            a[i] += a[i-1];
            
        if(a[id-1] % 11 != 0)
            id = 0;
    }
     
    for(i=st;i<=kt;i++)
        if(!(s[i] >= '0' && s[i] <= '9' || s[i] == 'X' || s[i] == '-' || s[i] == ' '))    
        {
            id = 0;
            break;
        }
    
    if(id == 10)
        printf("%s is correct.\n",kq);
    else
        printf("%s is incorrect.\n",kq);
}
/**/
void input()
{
    while(gets(s))
        solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

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

#define fi "12542.inp"
#define fo "12542.out"
/**/
using namespace std;
/**/
int d[100010];
char s[300];
int len;
/**/
void precal()
{
    long i,j;
    
    for(i=0;i<=100000;i++)
        d[i] = 0;
        
    d[0] = d[1] = 0;
    for(i=2;i<=317;i++)
        if(!d[i])
            for(j=i*i;j<=100000;j+=i)
                d[j] = 1;
}
/**/
void solve()
{
    int i,j;
    long kq,val;
    
    kq = 0;
    for(i=0;i<len;i++)
    {
        val = 0;
        for(j=i;j<i+5 && j<len;j++)
        {
            val *= 10;
            val += (s[j] - 48);
            if(val < 100000)
            {
                if(!d[val])
                    kq = val > kq ? val : kq;                
            }
            else
                break;
        }
    }
    
    printf("%ld\n",kq);
}
/**/
void input()
{
    precal();
    while(true)
    {
        gets(s);
        len = strlen(s);
        if(s[0] == '0' && len == 1)
            break;
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

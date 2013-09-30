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

#define fi "11034.inp"
#define fo "11034.out"
/**/
using namespace std;
/**/
queue <long long> r;
queue <long long> l;
long long ferry;
int n;
/**/
void solve()
{
    int dc;
    long long temp,len;
    bool left;
    dc = 0;
    left = true;
    while(!l.empty() || !r.empty())
    {
        len = 0;
        if(left)
        {
            while(!l.empty())
            {
                temp = l.front();
                if(len + temp < ferry)
                {
                    len += temp;
                    l.pop();
                }
                else
                    break;
            }
            left = false;
        }
        else
        {
            while(!r.empty())
            {
                temp = r.front();
                if(len + temp < ferry)
                {
                    len += temp;
                    r.pop();
                }
                else
                    break;
            }
            left = true;
        }
        dc++;
    }
    printf("%d\n",dc);
}
/**/
void input()
{
    int i;
    int ntest;
    long long len;
    char s[10];
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lld %d",&ferry,&n);
        ferry *= 100;
        while(!l.empty())
            l.pop();
        while(!r.empty())
            r.pop();
        for(i=0;i<n;i++)
        {
            scanf("%lld %s",&len,&s);
            if(s[0] == 'r')
                r.push(len);
            else
                l.push(len);
        }
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

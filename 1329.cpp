/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1329.inp"
#define fo "1329.out"
/**/
using namespace std;
/**/
int n;
int pre[20100];
long d[20100];
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
    {
        d[i] = 0;
        pre[i] = i;
    }
}
/**/
int fpre(int x)
{
    int y;
    if(x == pre[x]) 
        return x;
    y = fpre(pre[x]);
    d[x] += d[pre[x]];
    pre[x] = y;
    
    return y;
}
/**/
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
void input()
{
    char s[100];
    int x,y;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        while(true)
        {
            scanf("%s",&s);
            if(s[0] == 'E')
            {
                scanf("%d",&x);
                fpre(x);
                printf("%ld\n",d[x]);
            }
            else if(s[0] == 'I')
            {
                scanf("%d %d",&x,&y);
                pre[x] = y;
                d[x] = _abs(x-y) % 1000;
            }
            else if(s[0] == 'O')
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

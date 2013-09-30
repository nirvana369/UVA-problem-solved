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

#define fi "12405.inp"
#define fo "12405.out"
/**/
using namespace std;
/**/
int len;
char s[110];
/**/
void solve()
{
    int i;
    int dem;
    dem = 0;
    for(i=0;i<len;i++)
        if(s[i] == '.')
        {
            s[i] = '#';
            s[i+1] = '#';
            s[i+2] = '#';
            dem++;
            i += 2;
        }
    printf("%d\n",dem);
}
/**/
void input()
{
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %s",&len,&s);
        printf("Case %d: ",id++);
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

/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11636.inp"
#define fo "11636.out"
/**/
using namespace std;
/**/
int n;
/**/
void solve()
{
    int paste,hello;
    
    paste = 0;
    hello = 1;
    while(hello < n)
    {
        hello *= 2;
        paste++;
    }
    printf("%d\n",paste);
}
/**/
void input()
{
    int id;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(n < 0)
            break;
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

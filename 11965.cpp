/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11965.inp"
#define fo "11965.out"
/**/
using namespace std;
/**/
char s[1000];
/**/
void solve()
{
    int i;
    bool sp;
    sp = true;
    i = 0;
    while(s[i])
    {
        if(s[i] == ' ')
        {
            if(sp)
            {
                printf("%c",s[i]);
                sp = false;
            }
        }
        else
        {
            sp = true;
            printf("%c",s[i]);
        }
        i++;
    }
    printf("\n");
}
/**/
void input()
{
    int ntest,n,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        gets(s);
        printf("Case %d:\n",id++);
        while(n--)
        {
            gets(s);
            solve();
        }
        if(ntest)
            printf("\n");
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

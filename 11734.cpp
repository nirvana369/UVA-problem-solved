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

#define fi "11734.inp"
#define fo "11734.out"
/**/
using namespace std;
/**/
char s1[1000],s2[1000];
/**/
void solve()
{
    int i;
    char temp1[1000],temp2[1000];
    int l1,l2,dem;
    l1 = strlen(s1);
    l2 = strlen(s2);
    dem = 0;
    for(i=0;i<l1;i++)
        if(s1[i] != ' ')
            temp1[dem++] = s1[i];
    temp1[dem] = 0;

    dem = 0;
    for(i=0;i<l2;i++)
        if(s2[i] != ' ')
            temp2[dem++] = s2[i];
    temp2[dem] = 0;

    if(strcmp(temp1,temp2) == 0)
        printf("Output Format Error\n");
    else
        printf("Wrong Answer\n");
}
/**/
void input()
{
    int ntest,id;
    scanf("%d",&ntest);
    gets(s1);
    id = 1;
    while(ntest--)
    {
        gets(s1);
        gets(s2);
        printf("Case %d: ",id++);
        if(strcmp(s1,s2) == 0)
            printf("Yes\n");
        else
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

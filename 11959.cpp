/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11959.inp"
#define fo "11959.out"
/**/
using namespace std;
/**/
char s[10],s1[10];
/**/
void xoayx()
{
    char tmp;
    tmp = s1[3];
    s1[3] = s1[2];
    s1[2] = s1[5];
    s1[5] = s1[4];
    s1[4] = tmp;
}
/**/
void xoayy()
{
    char tmp;
    tmp = s1[0];
    s1[0] = s1[2];
    s1[2] = s1[1];
    s1[1] = s1[4];
    s1[4] = tmp;
}
/**/
void xoayz()
{
    char tmp;
    tmp = s1[0];
    s1[0] = s1[3];
    s1[3] = s1[1];
    s1[1] = s1[5];
    s1[5] = tmp;
}
/**/
bool solve()
{
    int i,j,k;
    
    for(i=0;i<4;i++)
    {
        xoayx();
        for(j=0;j<4;j++)
        {
            xoayy();
            for(k=0;k<4;k++)
            {
                xoayz();
                if(strcmp(s,s1) == 0)
                    return true;
            }
        }
    }
    return false;
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s %s",&s,&s1);
        if(solve())
            printf("Equal\n");
        else
            printf("Not Equal\n");
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

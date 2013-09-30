/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10573.inp"
#define fo "10573.out"
/**/
using namespace std;
/**/
double r1,r2,r;
/**/
int xuly(char s[])
{
    int i;
    char temp[1000];
    int l,dem;
    int flag;
    flag = 0;
    dem = 0;
    l = strlen(s);
    s[l] = ' ';
    for(i=0;i<=l;i++)
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            if(flag == 0)
            {
                sscanf(temp,"%lf",&r1);
                flag = 1;
            }
            else
            {
                sscanf(temp,"%lf",&r2);
                flag = 0;
            }
            dem = 0;
        }
        else if(s[i] != ' ')
            temp[dem++] = s[i];
    return flag;
}
/**/
void input()
{
    char temp[10000];
    int ntest;
    double pi,s,s1,s2;
    pi = acos(-1);
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        if(!xuly(temp))
        {
            s1 = r1 * r1 * pi;
            s2 = r2 * r2 * pi;
            r = r1 + r2;
            s = r * r * pi;
            s = s- (s1 + s2);
            printf("%0.4lf\n",s);
        }
        else
        {
            r1 = r1 / 2;
            s = r1 * r1 * pi;
            r1 = r1 / 2;
            s1 = r1 * r1 * pi;
            s2 = s1;
            s = s - (s1 + s2);
            printf("%0.4lf\n",s);
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

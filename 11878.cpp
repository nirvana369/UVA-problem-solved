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

#define fi "11878.inp"
#define fo "11878.out"
/**/
using namespace std;
/**/
void input()
{
    int right;
    char s[100],kq[100];
    int a,b,c;
    char sign,eq;
    right = 0;
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(s[0] == 0)
            break;
        sscanf(s,"%d%c%d%c%s",&a,&sign,&b,&eq,&kq);
        if(kq[0] != '?')
        {
            sscanf(kq,"%d",&c);
            if(sign == '+')
            {
                if(a + b == c)
                    right++;
            }
            else
            {
                if(a - b == c)
                    right++;
            }
        }
    }
    printf("%d\n",right);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

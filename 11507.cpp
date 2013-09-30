/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11507.inp"
#define fo "11507.out"
/**/
using namespace std;
/**/
void input()
{
    long i;
    char huong;
    char s[3];
    bool chieu;
    long n;
    
    while(scanf("%d",&n) && n)
    {
        huong = 'x';
        chieu = true;
        for(i=1;i<n;i++)
        {
            scanf("%s",&s);
            if(s[0] != 'N')
            {
                if((huong == 'x' && s[0] == '-') || (huong == s[1] && huong != 'x' && s[0] == '+'))
                    chieu = !chieu;
                if(huong == 'x')
                    huong = s[1];
                else  if(huong == s[1])
                    huong = 'x';
            }
        }
        if(chieu)
            printf("+");
        else
            printf("-");
        printf("%c\n",huong);
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

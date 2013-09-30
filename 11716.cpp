/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11716.inp"
#define fo "11716.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    int i,j,d;
    int temp,l;
    char s[11000],kq[11000];
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
        l = strlen(s);
        temp = (int)sqrt(l);
        if(temp * temp != l)
            printf("INVALID\n");
        else
        {
            d = 0;
            for(i=0;i<temp;i++)
            {
                j = i;
                while(j < l)
                {
                    kq[d++] = s[j];
                    j += temp;
                }
            }
            kq[d] = 0;
            printf("%s\n",kq);
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

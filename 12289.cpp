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

#define fi "12289.inp"
#define fo "12289.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest,dem;
    char s[1000];
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        if(strlen(s) != 3)
            printf("3\n");
        else
        {
            dem = 0;
            if(s[0] == 'o')
                dem++;
            if(s[1] == 'n')
                dem++;
            if(s[2] == 'e')
                dem++;
            if(dem >= 2)
                printf("1\n");
            else
                printf("2\n");
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

/*                                                          Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "465.inp"
#define fo "465.out"
/**/
using namespace std;
/**/
void input()
{
    double big,n1,n2;
    char p[3],temp[1000];
    big = 2147483647;
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        sscanf(temp,"%lf %s %lf",&n1,&p,&n2);
        printf("%s\n",temp);
        if(n1 > big)
            printf("first number too big\n");
        if(n2 > big)
            printf("second number too big\n");
        if(p[0] == '+')
        {
            n1 += n2;
            if(n1 > big)
                printf("result too big\n");
        }
        else
        {
            n1 *= n2;
            if(n1 > big)
                printf("result too big\n");
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

/*
                                                                    Hoang Lin
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11121.inp"
#define fo "11121.out"
/**/
using namespace std;
/**/
void input()
{
    int i,id;
    int ntest;
    char bin[100];
    int dem;
    long n,value;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        dem = 0;
        if(n == 0)
            bin[dem++] = '0';
        while(n != 0)    
        {
            if(n < 0)
                value = n * -1;
            else
                value = n;
            if(n < 0 && value % 2 != 0)
                n--;
            if(value % 2 != 0)
                bin[dem++] = '1';
            else
                bin[dem++] = '0';
            n /= -2;
        }
        printf("Case #%d: ",id);
        for(i=dem-1;i>=0;i--)
            printf("%c",bin[i]);
        printf("\n");
        id++;
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

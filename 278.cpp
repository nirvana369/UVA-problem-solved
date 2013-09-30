/*
                                                        Hoang Linh
                                                        
                                                Problem: CHESS - 278 (278.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "278.inp"
#define fo "278.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    int n,m;
    char kt;
    char temp[1000];
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        sscanf(temp,"%c %d %d",&kt,&m,&n);
        if(kt == 'r' || kt == 'Q')
        {
            if(m > n)
                printf("%d\n",n);
            else
                printf("%d\n",m);
        }
        else if(kt == 'k')
            printf("%d\n",((n+1)/2) * ((m+1)/2) + (n/2) * (m/2));
        else
            printf("%d\n",(n+1)/2 * (m+1)/2);
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

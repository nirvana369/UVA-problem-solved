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

#define fi "10365.inp"
#define fo "10365.out"
/**/
using namespace std;
/**/
void input()
{
    int i,j,k;
    int ntest;
    int area,temp,n;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        area = 32000;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i * j <= n)
                    for(k=1;k<=n;k++)
                        if(i * j * k == n)
                        {
                            temp = (i * j + i * k + j * k) * 2;
                            if(temp < area)
                                area = temp;
                        }
        printf("%d\n",area);
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

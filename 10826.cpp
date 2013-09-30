#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10826.inp"
#define fo "10826.out"
/**/
using namespace std;
/**/
void input()
{
    int n,dem;
    int temp;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        dem = 0;
        temp = 2;
        while(1)
        {
            if(temp * 2 < n)
                temp *= 2;
            else
                break;
            dem++;
        }
        printf("%d guess(es) required.\n",dem*2);
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

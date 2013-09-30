/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "616.inp"
#define fo "616.out"
/**/
using namespace std;
/**/
int n;
/**/
bool solve(int loop)
{
    int dem;
    int tmp,val;
    
    val = n;
    dem = 0;
    
    while(dem < loop && val % loop == 1)
    {
        val -= val / loop +1;
        dem++;
    }
    if(dem == loop && val % loop == 0)
        return true;
    return false;
}
/**/
void input()
{
    int i;
    int tmp;
    while(scanf("%d",&n))
    {
        if(n < 0)
            break;
        tmp = 1 + (int)sqrt(n);
        for(i=tmp;i>1;i--)
            if(solve(i))
                break;
        if(i == 1)
            printf("%d coconuts, no solution\n",n);
        else
            printf("%d coconuts, %d people and 1 monkey\n",n,i);
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

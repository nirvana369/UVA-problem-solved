/*
                                                Hoang Linh
                                                
                                    Problem: PETER'S SMOKES - 10346 (10346.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10346.inp"
#define fo "10346.out"
/**/
using namespace std;
/**/
void input()
{
    int n,k,du,nguyen,smoke;
    while(scanf("%d %d",&n,&k) == 2)
    {
        smoke = 0;
        while(n != 0)
        {
            nguyen = n / k;
            du = n % k;
            smoke = smoke + n - du;
            n = nguyen + du;
            if(n < k)
            {
                smoke = smoke + n;
                break;
            }
        }
        printf("%d\n",smoke);
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

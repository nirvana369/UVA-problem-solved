/*
                                                Hoang Linh
                                                
                                Problem: THE COLLATZ SEQUENCE - 694 (694.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "694.inp"
#define fo "694.out"
/**/
using namespace std;
/**/
long long a,limit;
/**/
void solve(int id)
{
    long long atemp;
    int step;
    step = 1;
    atemp = a;
    while(a != 1)
    {
        if(a % 2 == 0)
            a = a / 2;
        else
            a = 3 * a + 1;
        if(a > limit)
            break;
        step++;
    }
    printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",id,atemp,limit,step);
}
/**/
void input()
{
    int id;
    id = 1;
    while(true)
    {
        scanf("%lld %lld",&a,&limit);
        if(a == -1 && limit == -1)
            break;
        solve(id);
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

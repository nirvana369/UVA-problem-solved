/*
                                                Hoang Linh
                                                
                               Problem: BRICK WALL PATTERNS - 900 (900.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "900.inp"
#define fo "900.out"
/**/
using namespace std;
/**/
int n;
long long f[52];
/**/
void solve()
{
    int i;   
    f[1] = 1;
    f[2] = 2;
    
    i = 3;
    
    while(i != 51)
    {
        f[i] = f[i-1] + f[i-2];
        i++;
    }
}
/**/
void input()
{
    solve();
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        printf("%lld\n",f[n]);
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

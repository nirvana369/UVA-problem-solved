/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11089.inp"
#define fo "11089.out"
#define maxint 1000000000l
/**/
using namespace std;
/**/
long f[115];
int maxf;
char kq[110];
long n;
/**/
void _init()
{
    int i;
    f[1] = 1;
    f[2] = 2;
    for(i=3;i<=110;i++)
    {
        f[i] = f[i-1] + f[i-2];
        if(f[i] > maxint)
            break;
    }
    maxf = i;
}
/**/
void solve()
{
    int i,j,k;
    
    if(!n)    
    {
        printf("0\n");    
        return;
    }
    k = 0;
    kq[k++] = '0';
    for(i=maxf-1;i>=1;i--)
        if(n >= f[i])
        {
            for(j=i;j>=1;j--)
                if(n >= f[j] && kq[k-1] != '1')
                {
                    n -= f[j];
                    printf("1");
                    kq[k++] = '1';
                }
                else
                {
                    printf("0");
                    kq[k++] = '0';
                }
            break;
        }
    printf("\n");
}
/**/
void input()
{
    int id;
    int ntest;
            
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        solve();
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

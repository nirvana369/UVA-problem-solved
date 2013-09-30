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

#define fi "11824.inp"
#define fo "11824.out"
#define maxgt 5000000
/**/
using namespace std;
/**/
int a[50];
int da;
/**/
void sapxep()
{
    int i,j;
    int temp;
    for(i=0;i<da-1;i++)
        for(j=i+1;j<da;j++)
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void solve()
{
    int i;
    long long val;
    
    sapxep();
    val = 0;
    
    for(i=0;i<da;i++)
    {
        val += 2 * (long)pow(a[i],i+1);
        if(val > maxgt)
        {
            printf("Too expensive\n");
            return;
        }        
    }
    printf("%lld\n",val);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        da = 0;
        while(true)
        {
            scanf("%d",&a[da]);
            if(!a[da])
                break;
            da++;
        }
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

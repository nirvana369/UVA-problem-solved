/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "12571.inp"
#define fo "12571.out"
/**/
using namespace std;
/**/
int b[10];
bool d[231];
long n;
int q;
/**/
void _init()
{
    int i;
    
    b[0] = 1;
    for(i=1;i<8;i++)
        b[i] = b[i-1] * 2;
}
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<230;i++)
        d[i] = false;
}
/**/
void proc(long val) // process 32-bit integer to 8-bit integer
{
    int i,j;
    int a[10];
    
    i = 0;
    while(i < 8 && val) // dec to bin 8 bit
    {
        a[i++] = val % 2;
        val /= 2;
    }
    
    val = 0;
    for(j=i-1;j>=0;j--)
        val += b[j] * a[j]; // bin to dec
    d[val] = true;          // ton tai gia tri
}
/**/
void solve(long val)
{
    int i,j;
    long gt,ans;
    
    ans = 0;
    for(j=0;j<230;j++)
    {
        if(d[j])
        {
            gt = val & j;
            ans = max(ans,gt);
        }
    }
    
    printf("%ld\n",ans);
}
/**/
void input()
{
    long val;
    int ntest;
    _init();
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %d",&n,&q);
        khoitao();
        while(n--)
        {
            scanf("%ld",&val);
            proc(val);
        }
        while(q--)
        {
            scanf("%ld",&val); //  because q value < 230 -> problem simple solve with 8-bit integer >:) hie hie
            solve(val);
        }
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

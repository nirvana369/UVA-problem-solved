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

#define fi "10976.inp"
#define fo "10976.out"
/**/
using namespace std;
/**/
int n;
long num1[10000],num2[10000];
long ucln(long a,long b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;    
    }
    return a;
}
void input()
{
    int i;
    int dem;
    long val,temp;
    while(scanf("%d",&n) == 1)
    {
        dem = 0;
        i = n + 1;
        while(true)
        {
            val = i * n;
            temp = ucln(i-n,val);
            val /= temp;
            if(val < i)
                break;
            if((i-n)/temp == 1)
            {
                num1[dem] = val;
                num2[dem] = i;
                dem++;
            }
            if(val == i)
                break;
            i++;
        }
        printf("%d\n",dem);
        for(i=0;i<dem;i++)
            printf("1/%d = 1/%ld + 1/%ld\n",n,num1[i],num2[i]);
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

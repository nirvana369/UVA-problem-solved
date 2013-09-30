/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "927.inp"
#define fo "927.out"
/**/
using namespace std;
/**/
void input()
{
    long i,j;
    int ntest;  
    int n;
    long d,k,vt,tmp;
    long long val;
    int c[25];
    
    scanf("%d",&ntest);  
    while(ntest--)  
    {  
        scanf("%d",&n);  

        for(i=0;i<=n;i++)  
            scanf("%d",&c[i]);

        scanf("%ld %ld",&d,&k);  
        vt = 0;
        i = 1;
        while(true)
        {  
            val = 0;
            for (int j=0;j<=n;++j)  
                val += c[j] * (long)pow(i,j);
            
            tmp = d * i;
            vt += tmp;  
            if(vt >= k)
            {
                printf("%lld\n",val);  
                break;  
            }  
            i++;
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12060.inp"
#define fo "12060.out"
/**/
using namespace std;
/**/
int n,neg;
long val;
/**/
int ucln(int a,int b)
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
/**/
void xuly()
{
    int i,j,k;
    int nguyen,tu;
    int tmp,space;
    
    nguyen = val / n;
    tu = val % n;
    
    tmp = ucln(n,tu);
    n /= tmp;
    tu /= tmp;
    
    space = 0;
    
    if(neg < 0)
        space+=2;
    if(nguyen)
    {
        tmp = nguyen;
        i = 0;
        while(tmp != 0)
        {
            tmp /= 10;
            i++;
        }
        space += i;
    }
    
    tmp = tu;
    i = 0;
    while(tmp != 0)
    {
        tmp /= 10;
        i++;
    }
    
    tmp = n;
    j = 0;
    while(tmp != 0)
    {
        tmp /= 10;
        j++;
    }
    
    for(k=0;k<space+(j-i);k++)
        printf(" ");
    printf("%d\n",tu);
    if(neg < 0)
        printf("- ");
    if(nguyen)
        printf("%d",nguyen);
        
    for(k=0;k<j;k++)
        printf("-");
    printf("\n");
    for(k=0;k<space;k++)
        printf(" ");
    printf("%d\n",n);
}
/**/
void input()
{
    int i,id;
    int tmp;
    
    id = 1;
    while(scanf("%d",&n) && n)
    {
        val = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            val += tmp;
        }
        printf("Case %d:\n",id++);
        if(val < 0)
        {
            neg = -1;
            val = val * neg;
        }
        else
            neg = 1;
            
        if(val % n == 0)
        {
            if(neg < 0)
                printf("- ");
            printf("%ld\n",val/n);
        }
        else
            xuly();
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

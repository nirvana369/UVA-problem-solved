/*
                                            Hoang Linh
                                        
                                    Problem: PRIME RING PROBLEM - 524
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "524.inp"
#define fo "524.out"
/**/
using namespace std;
/**/
int n;
int d[20],a[20],nt[40];
/**/
bool ktnt(int value)
{
    int k;
    int temp;

    if(value == 2 || value == 3)
        return true;
    temp = (int)sqrt(value);
    
    for(k=2;k<=temp;k++)
        if(value % k == 0)
            return false;
    return true;
}
/**/
void khoitao_nguyento()
{
    int i;
    
    for(i=2;i<32;i++)
    {
        nt[i] = 0 ;
        if(ktnt(i))
            nt[i] = 1 ;
    }
}
/**/
void dequy(int i)
{
    int j;
    
    if(i == n)
    {
        if(nt[a[i-1] + a[0]] == 1)
        {
            for(j=0;j<n;j++)
                if(j == 0)
                    printf("%d",a[j]);
                else
                    printf(" %d",a[j]);
            printf("\n");
        }
    }
    
    for(j=1;j<=n;j++)
        if(d[j] == 0 && nt[a[i-1] + j] == 1)
        {
            a[i] = j;
            d[j] = 1;
            
            dequy(i+1);
            
            d[j] = 0;
        }
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
        d[i] = 0;
    d[1] = 1;
}
/**/
void input()
{
    int in;
    int id;
    khoitao_nguyento();
    id = 1;
    scanf("%d",&n);
    while(n != 0)    
    {
        khoitao();
        a[0] = 1;
        printf("Case %d:\n",id);
        dequy(1);
        n = 0;
        id++;
        scanf("%d",&n);
        if(n != 0)
            printf("\n");
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

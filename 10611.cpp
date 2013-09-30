/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10611.inp"
#define fo "10611.out"
/**/
using namespace std;
/**/
long n;
long a[60000];
/**/
void doi(long id,long id1)
{
    long tg;
    tg = a[id];
    a[id] = a[id1];
    a[id1] = tg;
}
/**/
void capnhap(long id)
{
    if(id == 1)
        return;
    if(a[id] >= a[id/2])
    {
        doi(id,id/2);
        capnhap(id/2);
    }
}
/**/
void updatea(long id)
{
    if(id * 2 + 1 <= n)
    {
        if(a[id*2+1] > a[id*2])
        {
            if(a[id*2+1] > a[id])
            {
                doi(id*2+1,id);
                updatea(id*2+1);
            }
            else if(a[id*2] > a[id])
            {
                doi(id*2,id);
                updatea(id*2);
            }
        }
        else if(a[id*2] > a[id])
        {
            doi(id*2,id);
            updatea(id*2);
        }
    }
    else if(id * 2 <= n && a[id*2] > a[id])
    {
        doi(id*2,id);
        updatea(id*2);
    }
}
/**/
void sapxep()
{
    long temp;
    temp = n;
    while(n != 0)
    {
        doi(1,n);
        n--;
        updatea(1);
    }
    n = temp;
}
/**/
void input()
{
    long dau,cuoi,temp,nq;
    long i,j;
    
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&a[i]);
        capnhap(i);
    }
    sapxep();
    
    scanf("%ld",&nq);

    for(i=0;i<nq;i++)
    {
        dau = cuoi = -1;
        scanf("%ld",&temp);
        for(j=1;j<=n;j++)
        {
            if(a[j] < temp)
                dau = j;
            if(a[j] > temp)
            {
                cuoi = j;
                break;
            }
        }
        if(dau == -1)
            printf("X ");
        else
            printf("%ld ",a[dau]);
        if(cuoi == -1)
            printf("X\n");
        else
            printf("%ld\n",a[cuoi]);
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

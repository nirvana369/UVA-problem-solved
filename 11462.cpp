/*
                                                        Hoang Linh
                                                        
                                                Problem: AGE SORT - 11462 (11462.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11462.inp"
#define fo "11462.out"
/**/
using namespace std;
/**/
int a[2000010];
long n;
/**/
void swapa(long id1,long id2)
{
    int temp;
    temp = a[id1];
    a[id1] = a[id2];
    a[id2] = temp;
}
/**/
void updatea(long id)
{
    if(id == 1)
        return;
    if(a[id] >= a[id/2])
    {
        swapa(id,id/2);
        updatea(id/2);
    }
}
/**/
void hsort(long id)
{
    if(id > n)
        return;
    if(id * 2 + 1 <= n)
    {
        if(a[id*2+1] > a[id*2])
        {
            if(a[id*2+1] >= a[id])
            {
                swapa(id*2+1,id);
                hsort(id*2+1);
            }
        }
        else if(a[id*2] >= a[id])
        {
            swapa(id*2,id);
            hsort(id*2);
        }
    }
    else if(id * 2 <= n)
        if(a[id*2] >= a[id])
        {
            swapa(id*2,id);
            hsort(id*2);
        }
}
/**/
void solve()
{
    long i;
    long temp;
    temp = n;
    while(n != 0)
    {
        swapa(1,n);
        n--;
        hsort(1);
    }
    for(i=1;i<=temp;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
/**/
void input()
{
    long i;
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            updatea(i);
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

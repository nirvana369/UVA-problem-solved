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
#include <vector>

#define fi "12100.inp"
#define fo "12100.out"
/**/
using namespace std;
/**/
struct prt{
            int val;
            int vt;
            };
prt q[110];
int a[110];
int n,pos;
/**/
void sapxep()
{
    int i,j;
    int temp;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void donmang()
{
    int i;
    prt temp;
    
    temp = q[0];
    for(i=0;i<n-1;i++)
        q[i] = q[i+1];
    q[n-1] = temp;
}
/**/
void solve()
{
    int m;
    int dem;
        
    sapxep();
    m = n-1;
    
    dem = 0;
    while(true)
    {
        while(q[0].val != a[m])
            donmang();
        m--;
        dem++;
        
        if(q[0].vt == pos)
            break;
        donmang();
        n--;
    }
    printf("%d\n",dem);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&pos);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            q[i].val = a[i];
            q[i].vt = i;
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

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

#define fi "10771.inp"
#define fo "10771.out"
/**/
using namespace std;
/**/
int n,m,k,len;
bool a[2100];
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<=n;i++)
        a[i] = true;
        
    for(i=n+1;i<=n+m;i++)
        a[i] = false;
}
/**/
int donmang(int x)
{
    int i;
    
    for(i=x;i<len;i++)
        a[i] = a[i+1];
    if(x == len)
        return 0;
    return x-1;
}
/**/
void solve()
{
    int p,vt;
    bool name,x1,x2;
    
    p = 0;
    len = n+m;
    
    while(len > 1)
    {/*
        for(int i=1;i<=len;i++)
            if(a[i])
                printf("G ");
            else
                printf("K ");
        printf("\n");
        if(len == 3)
        {
            len = 3;
        }*/
        vt = (p + k) % len;
        if(!vt)
            vt = len;
        x1 = a[vt];
        
        vt = donmang(vt);
        
        vt = ((vt + k) % (len-1));
        if(!vt)
            vt = len - 1;
            
        x2 = a[vt];
        
        if(!x1 && !x2 || x1 && x2)
            name = true;
        else
            name = false;
        p = vt;
        
        a[p] = name;
        len--;
    }
    if(a[1])
        printf("Gared\n");
    else
        printf("Keka\n");
}
/**/
void input()
{
    while(scanf("%d %d %d",&n,&m,&k))
    {
        if(!n && !m && !k)
            break;
        khoitao();
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

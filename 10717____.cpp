#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10717.inp"
#define fo "10717.out"
/**/
using namespace std;
/**/
int leg[60];
int n,q;
/**/
bool kiemtra(long value)
{
    int i;  
    int dem;
    dem = 0;
    for(i=0;i<n;i++)
        if(value % leg[i] == 0)
        {
            dem++;
            if(dem == 4)
                return true;
        }
    return false;
}
/**/
int ucln(int a,int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
void solve()
{
    int i;
    long minleg,maxleg,temp;
    int uc;
    scanf("%d",&temp);
    maxleg = temp;
    minleg = temp;
    if(!kiemtra(temp))
    {
        for(i=0;i<n;i++)
            if(temp - temp % leg[i] < minleg && kiemtra(temp - temp % leg[i]))
                minleg = temp - temp % leg[i];
        for(i=0;i<n;i++)
            if(temp + temp % leg[i] > maxleg && kiemtra(temp + temp % leg[i]))
                maxleg = temp + temp % leg[i];
        if(minleg == temp)
            minleg = 0;
        if(maxleg == temp)
        {
            uc = ucln(leg[0],leg[1]);
            for(i=2;i<n;i++)
                uc = ucln(uc,leg[i]);
            maxleg = 1;
            for(i=0;i<n;i++)
                maxleg *= leg[i];
            maxleg /= uc;
        }
    }
    printf("%d %d\n",minleg,maxleg);
}
/**/
void input()
{
    int i;
    while(scanf("%d %d",&n,&q) == 2)
    {
        if(!n && !q)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&leg[i]);
        for(i=0;i<q;i++)
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

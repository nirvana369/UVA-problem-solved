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

#define fi "10780.inp"
#define fo "10780.out"
/**/
using namespace std;
/**/
int n,m;
int a[10010],nt[10000],b[10000],d[10000],d1[10000];
int db,dnt;
/**/
int triettieu()
{
    int i;
    int dem;
    long val;
    val = 99999;
    for(i=0;i<db;i++)
    {
        if(d1[b[i]] < d[b[i]])
            return 0;
        else
        {
            dem = 0;
            while(d[b[i]] <= d1[b[i]])
            {
                d1[b[i]] -= d[b[i]];
                dem++;
            }
            if(dem < val)
                val = dem;
        }
    }
    if(val == 99999)
        return 0;
    return val;
}
/**/
void solve()
{
    int i,j;
    long long val;
    long dem,temp;
    
    dem = 0;
    val = 1;
        
    for(i=1;i<=n;i++)
    {
        a[i] = i;
        while(a[i] % m == 0)
        {
            a[i] /= m;
            dem++;
        }
        if(a[i] != 1)        
        {
            j = 0;
            while(j < dnt)
            {
                while(a[i] % nt[j] == 0)
                {
                    a[i] /= nt[j];
                    d1[nt[j]]++;
                }
                if(a[i] == 1)
                    break;
                j++;
            }
            if(a[i] != 1)
                d1[a[i]]++;
        }
    }
    dem += triettieu();
    if(!dem)
        printf("Impossible to divide\n");
    else
        printf("%ld\n",dem);
}
/**/
bool isnt(int val)
{
    int temp,add;
    int i;
    
    if(val == 2 || val == 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0 || val == 1)
        return false;
    add = 2;
    temp = (int)sqrt(val);
    for(i=5;i<=temp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;    
}
/**/
void precal()
{
    int i;
    dnt = 0;
    for(i=1;i<=5000;i++)
        if(isnt(i))
            nt[dnt++] = i;    
}
/**/
void xuly()
{
    int i;
    int temp;    

    for(i=0;i<dnt;i++)
    {
        d[nt[i]] = 0;
        d1[nt[i]] = 0;
    }
    
    db = 0;    
    i = 0;
    temp = m;
    while(i < dnt)
    {
        if(temp % nt[i] == 0)
            b[db++] = nt[i];    
        while(temp % nt[i] == 0)
        {
            temp /= nt[i];
            d[nt[i]]++;
        }
        if(temp == 1)
            break;
        i++;    
    }
    
    if(temp != 1)
        d[temp]++;
}
/**/
void input()
{
    int ntest,id;
    precal();
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&m,&n);
        printf("Case %d:\n",id++);
        xuly();
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

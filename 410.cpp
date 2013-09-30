/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "410.inp"
#define fo "410.out"
/**/
using namespace std;
/**/
vector<int > v[6];
int a[12];
int n,m;
double dbl;
/**/
void sapxep()
{
    int i,j;
    int tmp;
    
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    
}
/**/
void solve()
{
    int i,j,k;
    double dif;
    long tong;
    
    for(i=0;i<=5;i++)
        v[i].clear();    
    dif = 0;
    dbl /= n;
    
    if(n == 1)
        for(i=0;i<m;i++)
            v[0].push_back(a[i]);
    else
    {
        i = 0;
        j = m-1;
        while(i < n && j >= 0)
            v[i++].push_back(a[j--]);
            
        if(j >= 0)
        {
            for(k=j,i=n-1;k>=0;k--,i--)
                v[i].push_back(a[k]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("%2d:",i);
        if(v[i].size())        
        {
            tong = 0;
            for(j=0;j<v[i].size();j++)
            {
                cout << " " << v[i][j];
                tong += v[i][j];
            }
            dif += fabs(dbl-tong);
        }
        else
            dif += dbl;
        printf("\n");
    }
    printf("IMBALANCE = %0.5f\n\n",dif);
}
/**/
void input()
{
    int i;
    int id;
    id = 1;
    while(scanf("%d %d",&n,&m) == 2)
    {
        dbl = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            dbl += a[i];
        }
        sapxep();
        printf("Set #%d\n",id++);
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

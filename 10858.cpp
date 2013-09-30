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

#define fi "10858.inp"
#define fo "10858.out"
/**/
using namespace std;
/**/
long n,idv;
long luu[100];
vector<long> a[500000];
int sizea[500000];
/**/
void sapxep()
{
    int i,j;
    long temp;
    
    for(i=0;i<sizea[idv];i++)
        for(j=i+1;j<sizea[idv];j++)
            if(a[idv][i] > a[idv][j])
            {
                temp = a[idv][i];
                a[idv][i] = a[idv][j];
                a[idv][j] = temp;
            }
}
/**/
bool kiemtra()
{
    long i;
    int j;
    for(i=idv-1;i>=0;i--)
        if(a[idv][0] > a[i][0])
            return true;
        else if(a[idv][0] == a[i][0] && sizea[idv] == sizea[i])
        {
            for(j=0;j<sizea[idv];j++)
                if(a[idv][j] != a[i][j])
                    break;
                    
            if(j == sizea[idv])
                return false;
        }
    return true;
}
/**/
void dq(int id,long val)
{
    long i,temp;
    temp = (int)sqrt(val);
    for(i=2;i<=temp;i++)
        if(val % i == 0)
        {
            luu[id] = i;
            dq(id+1,val/i);
        }
        
    luu[id] = val;
    
    if(val != n)
    {
        a[idv].clear();
        for(i=0;i<=id;i++)
            a[idv].push_back(luu[i]);
        sizea[idv] = a[idv].size();
        sapxep();
        if(kiemtra())
            idv++;
    }
}
/**/
void output()
{
    long i,j;
    if(!idv)
        printf("0\n");
    else
    {
        printf("%ld\n",idv);
        for(i=0;i<idv;i++)
        {
            for(j=0;j<sizea[i];j++)
            {
                if(j)
                    printf(" ");
                printf("%ld",a[i][j]);
            }
            printf("\n");
        }
    }
}
/**/
void input()
{
    while(scanf("%ld",&n))
    {
        if(!n)
            break;
        idv = 0;
        dq(0,n);
        output();
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

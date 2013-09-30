/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
//#include <map>

#define fi "1137.inp"
#define fo "1137.out"
#define m 2147483648ll
/**/
using namespace std;
/**/
priority_queue<long, vector<long > , greater<long > > pq;
long a[1000];
int nt[1000];
int b[1000];
int dnt,da;
long l,u;
/**/
bool ispr(int val)
{
    int i;
    int tmp,add;
    
    if(val == 2 || val == 3)
        return true;
    
    if(!(val % 2) || !(val % 3))
        return false;
    
    tmp = (int)sqrt(val);
    add = 2;
    
    for(i=5;i<=tmp;i+=add,add=6-add)
        if(!(val % i))
            return false;
    return true;
}
/**/
void _init()
{
    int i;
    
    dnt = 0;
    
    for(i=2;i<1290;i++)
        if(ispr(i))
            nt[dnt++] = i;
}
/**/
bool chk(long val,int id)
{
    int i;
    for(i=0;i<id;i++)
        if(val % b[i])
            return false;
    return true;
}
/**/
void gene(int id,long long val,int s)
{
    int i;
    
    if(id > 2)
    {
        if(chk(val-1,id))
            pq.push(val);
    }
    for(i=s;i<dnt;i++)
    {
        if(val * nt[i] < m)
        {
            b[id] = nt[i] - 1;
            gene(id+1,val*nt[i],i+1);
        }
        else
            return;
    }
}
/**/
void precal()
{
    int i,j,k;
    
    gene(0,1,0);
    
    da = 1;
    while(!pq.empty())
    {
        a[da++] = pq.top();
        //printf("%ld\n",a[da-1]);
        pq.pop();
    }
}
/**/
void solve()
{
    int i;
    int xp,kt;
    
    if(l > u)
    {
        l ^= u;
        u ^= l;
        l ^= u;
    }
    
    xp = da;
    
    for(i=0;i<da;i++)
        if(a[i] >= l)
        {
            xp = i;
            break;
        }
    
    kt = 0;    
    for(i=da-1;i>=0;i--)
        if(a[i] <= u)
        {
            kt = i;
            break;
        }
    
    if(xp > kt)
        printf("none\n");
    
    for(i=xp;i<=kt;i++)
        printf("%ld\n",a[i]);
}
/**/
void input()
{
    int id;
    char str[1000];
    
    _init();
    precal();
    
    id = 0;
    while(1)
    {
        str[0] = 0;
        gets(str);
        l = -1;
        sscanf(str,"%ld %ld",&l,&u);
        gets(str);
        
        if(l == -1)
            break;
        
        if(id++)
            printf("\n");
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

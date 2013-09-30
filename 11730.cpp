/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "11730.inp"
#define fo "11730.out"
/**/
using namespace std;
/**/
int q[1100],kc[1100],nt[1100];
bool d[1100];
vector<int > uoc[1100];
int x,y,dnt;
/**/
void dem_uoc(int val)
{
    int i;
    int id;
    id = val;
    i = 0;
    while(i < dnt)
    {
        if(val % nt[i] == 0)
            uoc[id].push_back(nt[i]);
            
        while(val % nt[i] == 0)
            val /= nt[i];
        
        if(d[val])
        {
            uoc[id].push_back(val);
            return;
        }
        
        if(val == 1)
            break;
        i++;
        
        if(nt[i] * nt[i] > val)
            break;
    }
}
/**/
void _init()
{
    int i,j;
    
    for(i=1;i<=1000;i++)
    {
        d[i] = true;
        uoc[i].clear();
    }
    d[1] = false;
    dnt = 0;
    for(i=2;i<=1000;i++)
        if(d[i])
        {
            j = 2;
            nt[dnt++] = i;
            while(i*j <= 1000)
            {
                d[j*i] = false;
                j++;
            }
        }
        else
            dem_uoc(i);
}
/**/
void khoitao()
{
    int i;
    for(i=x;i<=y;i++)
        d[i] = true;
}
/**/
int loang()
{
    int i;
    int dau,cuoi;
    
    if(x == y)
        return (x-y);
        
    khoitao();
    dau = -1;
    cuoi = 0;
    q[0] = x;
    d[x] = false;
    kc[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        x = q[dau];
        for(i=uoc[x].size()-1;i>=0;i--)    
            if(x+uoc[x][i] <= 1000)
                if(d[x+uoc[x][i]])
                {
                    cuoi++;
                    q[cuoi] = x + uoc[x][i];
                    kc[cuoi] = kc[dau] + 1;
                    d[x+uoc[x][i]] = false;
                    if(q[cuoi] == y)
                        return kc[cuoi];
                }
    }
    return -1;
}
/**/
void input()
{
    int kq,id;
    _init();
    id = 1;
    while(scanf("%d %d",&x,&y))
    {
        if(!x && !y)
            break;
        printf("Case %d: ",id++);
        if(x > y)
            printf("-1\n");
        else
        {
            kq = loang();
            printf("%d\n",kq);
        }
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

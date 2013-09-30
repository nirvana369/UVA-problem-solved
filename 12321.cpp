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

#define fi "12321.inp"
#define fo "12321.out"
/**/
using namespace std;
/**/
struct pgas{
                long dau,cuoi;
            };
class sosanh{
public:
    bool operator()(pgas a,pgas b){
            if(a.dau > b.dau)
                return true;
            else if(a.dau == b.dau)
                if(a.cuoi < b.cuoi)
                    return true;
            return false;
        }
};
priority_queue <pgas, vector <pgas>, sosanh > pq;
pgas pos[10500];
long l;
int g;
/**/
void solve()
{
    int i;
    long s,e,temps,tempe;
    int dem;
    bool tontai;
    dem = 1;
    for(i=0;i<g;i++)
    {
        pos[i] = pq.top();
        pq.pop();
    }
    s = pos[0].dau;
    e = pos[0].cuoi;
    temps = s;
    tempe = e;
    if(s != 0)
        tempe = l-1;
    else
        for(i=1;i<g;i++)
        {
            if(pos[i].dau >= s && pos[i].dau <= e && pos[i].cuoi > e)
            {
                if(pos[i].cuoi > tempe)
                {
                    tontai = true;
                    temps = pos[i].dau;
                    tempe = pos[i].cuoi;
                    if(tempe == l)
                    {
                        dem++;
                        break;
                    }
                }
            }
            else if(pos[i].dau > e)
            {
                if(tontai)
                {
                    dem++;
                    s = temps;
                    e = tempe;
                    tontai = false;
                    i--;
                }
            }
        }
        
    if(tempe == l)
        printf("%d\n",g-dem);
    else
        printf("-1\n");
}
/**/
void input()
{
    int i;
    long p,r;
    pgas t;
    while(scanf("%ld %d",&l,&g) == 2)
    {
        if(!l && !g)
            break;
        while(!pq.empty())
            pq.pop();
        for(i=0;i<g;i++)
        {
            scanf("%ld %ld",&p,&r);
            t.dau = p - r;
            t.cuoi = p + r;
            if(t.dau < 0)
                t.dau = 0;
            if(t.cuoi > l)
                t.cuoi = l;
            pq.push(t);
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

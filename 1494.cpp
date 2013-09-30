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

#define fi "1494.inp"
#define fo "1494.out"
/**/
using namespace std;
/**/
struct road{
                int x,y;
                double val;
            };
            
struct toado{
                int x,y;
                long pop;
            };
class sosanh{
public:
    bool operator()(road t1,road t2)
    {
        if(t1.val > t2.val)
            return true;
        return false;
    }
};
priority_queue <road, vector<road>, sosanh > pq;
toado p[1010];
road luu[1010];
int d[1010],lk[1010][1010],q[1010],pre[1010];
int n;
vector<int> u[1010];
/**/
double kc(toado i,toado j)
{
    return sqrt((i.x-j.x) * (i.x-j.x) + (i.y-j.y) * (i.y-j.y));
}
/**/
void resetd()
{
    int i;
    for(i=0;i<n;i++)
        d[i] = 0;
}
/**/
long loang(int xp)  // loang tim max population cua 1 vung
{
    int i;
    int dau,cuoi;
    long maxpop;
    
    dau = -1;
    cuoi = 0;
    d[xp] = 1;
    maxpop = p[xp].pop;
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<u[q[dau]].size();i++)
        {
            if(lk[q[dau]][u[q[dau]][i]] && !d[u[q[dau]][i]])
            {
                cuoi++;
                q[cuoi] = u[q[dau]][i];
                d[u[q[dau]][i]] = 1;
                if(p[u[q[dau]][i]].pop > maxpop)
                    maxpop = p[u[q[dau]][i]].pop;
            }
        }
    }

    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
        
    return maxpop;
}
/**/
int fpre(int u)
{
    while(u != pre[u])
        u = pre[u];
    return u;
}
/**/
void solve()
{
    int i;
    road t;
    int dinh,v1,v2;
    long pop1,pop2;
    double leng,temp,kq;
    
        
    leng = 0;
    dinh = 0;
    
    while(!pq.empty())
    {
        t = pq.top();
        pq.pop();
        v1 = fpre(t.x);
        v2 = fpre(t.y);
        
        if(v1 != v2)
        {
            pre[t.x] = v1;
            pre[t.y] = v1;
            pre[v2] = v1;

            u[t.x].push_back(t.y); //   luu duong
            u[t.y].push_back(t.x); //

            lk[t.x][t.y] = lk[t.y][t.x] = 1;  // tao lien ket 2 dinh vua luu

            luu[dinh] = t;   // 
            leng += t.val;
            dinh++;
        }
        if(dinh == n)
            break;
    }

    //////////////////
    kq = -1;
    resetd();
    
    for(i=0;i<dinh;i++)         // cat tung duong noi
    {
        lk[luu[i].x][luu[i].y] = 0; // disconnect
        lk[luu[i].y][luu[i].x] = 0;
    
        pop1 = loang(luu[i].x);     // find max population land 1
        pop2 = loang(luu[i].y); //     find max pop land 2
        
        temp = (double)(pop1 + pop2) / (leng - luu[i].val);
        if(temp > kq)        // update if > kq
            kq = temp;
    
        lk[luu[i].x][luu[i].y] = 1;  // re-connect
        lk[luu[i].y][luu[i].x] = 1;
    }
    printf("%0.2lf\n",kq);
}
/**/
void input()
{
    int i,j;
    int ntest;
    road t;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        while(!pq.empty())
            pq.pop();
        for(i=0;i<n;i++)
        {
            pre[i] = i;
            u[i].clear();
            scanf("%d %d %ld",&p[i].x,&p[i].y,&p[i].pop);
            for(j=0;j<i;j++)
            {
                t.x = i;
                t.y = j;
                t.val = kc(p[i],p[j]);
                pq.push(t);
            }
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

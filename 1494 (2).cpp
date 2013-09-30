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
int d[1010],lk[1010][1010],q[1010];
int n;
double a[1010][1010];
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
    return maxpop;
}
/**/
void solve()
{
    int i;
    road t;
    int dinh;
    long pop1,pop2;
    double leng,temp,kq;
    
    while(!pq.empty())
        pq.pop();
    
    d[0] = 1;
    t.x = 0;
    
    for(i=0;i<n;i++)
        if(i != t.x && !d[i])
        {
            t.y = i;
            t.val = a[t.x][t.y];
            pq.push(t);
        }
        
    leng = 0;
    dinh = 1;
    while(dinh != n)                        // MST tim cay khung
    {
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();
            if(!d[t.y])
            {
                u[t.x].push_back(t.y); //   luu duong
                u[t.y].push_back(t.x); //
                lk[t.x][t.y] = lk[t.y][t.x] = 1;  // tao lien ket 2 dinh vua luu
                luu[dinh] = t;   // 
                ///////////////
                d[t.y] = 1;
                leng += t.val;
                dinh++;
                break;
            }
        }
        
        if(dinh == n)
            break;
            
        t.x = t.y;
        for(i=0;i<n;i++)
            if(i != t.x && !d[i])
            {
                t.y = i;
                t.val = a[t.x][t.y];
                pq.push(t);
            }
    }
    //////////////////
    kq = -1;
    for(i=1;i<dinh;i++)         // cat tung duong noi
    {
        lk[luu[i].x][luu[i].y] = 0; // disconnect
        lk[luu[i].y][luu[i].x] = 0;
        
        resetd();
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
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            u[i].clear();
            scanf("%d %d %ld",&p[i].x,&p[i].y,&p[i].pop);
            for(j=0;j<i;j++)
                a[i][j] = a[j][i] = kc(p[i],p[j]);
            d[i] = 0;
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

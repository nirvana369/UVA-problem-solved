/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

#define fi "1174.inp"
#define fo "1174.out"
/**/
using namespace std;
/**/
struct g{
            int dau,cuoi;
            int l;
        };
class sosanh{
public:
    bool operator()(g t1,g t2)
    {
        if(t1.l > t2.l)
            return true;
        return false;
    }    
};
bool d[2010];
vector<int > a[2010];
priority_queue<g, vector<g>, sosanh > pq;
map<string, int > mmap;
int gt[2010][2010];
int n;
long m;
/**/
void solve()
{
    int i;
    long val;
    int dem;
    g nut;
    
    while(!pq.empty())
        pq.pop();
    
    val = 0;
    nut.dau = 1;
    d[1] = false;
    
    for(i=0;i<a[nut.dau].size();i++)
        if(d[a[nut.dau][i]])
        {
            nut.cuoi = a[nut.dau][i];
            nut.l = gt[nut.dau][nut.cuoi];
            pq.push(nut);
        }
    dem = 1;
    while(dem != n)
    {
        while(!pq.empty())
        {
            nut = pq.top();
            pq.pop();
            if(d[nut.cuoi])
            {
                val += nut.l;
                d[nut.cuoi] = false;
                dem++;
                break;
            }
        }
        if(dem == n)
            break;
        nut.dau = nut.cuoi;
        for(i=0;i<a[nut.dau].size();i++)
            if(d[a[nut.dau][i]])
            {
                nut.cuoi = a[nut.dau][i];
                nut.l = gt[nut.dau][nut.cuoi];
                pq.push(nut);
            }
    }
    printf("%ld\n",val);
}
/**/
void input()
{
    char s[15];
    int tmp,x,y,val;
    long i;
    int ntest,id;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld",&n,&m);
        mmap.clear();
        id = 1;
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);            
            tmp = mmap[s];
            if(!tmp)
            {
                mmap[s] = id;
                x = id;
                d[x] = true;
                a[x].clear();
                id++;
            }
            else
                x = tmp;
                
            scanf("%s",&s);            
            tmp = mmap[s];
            if(!tmp)
            {
                mmap[s] = id;
                y = id;
                a[y].clear();
                d[y] = true;
                id++;
            }
            else
                y = tmp;
                
            scanf("%d",&val);
            
            gt[x][y] = gt[y][x] = val;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        solve();
        if(ntest)
            printf("\n");
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

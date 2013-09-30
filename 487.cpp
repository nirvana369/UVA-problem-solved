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

#define fi "487.inp"
#define fo "487.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
class sosanh{
public:
    bool operator()(string s1,string s2){
        int l1,l2;
        int i;
        l1 = s1.size();
        l2 = s2.size();
        if(l1 > l2)
            return true;
        if(l1 == l2)
            if(s1.compare(s2) > 0)
                return true;
        return false;
    }    
};
priority_queue <string, vector <string>, sosanh > pq;
map <string, string> mmap;
char a[30][30],luu[500];
int d[30][30];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j] = 0;
}
/**/
void dq(int hang,int cot,int val,int id)
{
    int i;
    int px,py;
    if(id > 2)
    {
        luu[id] = 0;
        if(mmap[luu] == "")
        {
            mmap[luu] = luu;
            pq.push(luu);
        }
    }
    for(i=0;i<8;i++)
    {
        px = hang + h[i].x;
        py = cot + h[i].y;
        if(px >= 0 && px < n && py >= 0 && py < n)
            if(d[px][py] == 0 && a[px][py] > val)
            {
                d[px][py] = 1;
                luu[id] = a[px][py];
                dq(px,py,luu[id],id+1);
                d[px][py] = 0;
            }
    }
}
/**/
void solve()
{
    int i,j;
    map <string, string>::iterator k;
    khoitao();
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            d[i][j] = 1;
            luu[0] = a[i][j];
            dq(i,j,a[i][j],1);
            d[i][j] = 0;    
        }
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
/**/
void input()
{
    int ntest;
    int i;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        mmap.clear();
        while(!pq.empty())
            pq.pop();
        gets(a[0]);
        for(i=0;i<n;i++)
            gets(a[i]);
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

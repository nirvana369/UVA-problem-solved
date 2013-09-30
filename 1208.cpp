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

#define fi "1208.inp"
#define fo "1208.out"
/**/
using namespace std;
/**/
struct oreon{
                int dau,cuoi;
                int val;
            };
            
class sosanh{
public:
    bool operator()(oreon t1,oreon t2)
    {
        if(t1.val > t2.val)
            return true;
        else if(t1.val == t2.val)
        {
            if(t1.dau > t2.dau)
                return true;
            else if(t1.dau == t2.dau)
                if(t1.cuoi > t2.cuoi)
                    return true;
        }
        return false;
    }    
};
priority_queue <oreon, vector <oreon>, sosanh > pq,kq;
int a[30][30],d[30],tree[30];
int n;
/**/
void khoitao()
{
    int i;
    for(i=0;i<n;i++)
        d[i] = 0;
    while(!pq.empty())
        pq.pop();
}
/**/
void solve()
{
    oreon temp;
    int i;
    int tg;
    int dem;
    khoitao();    
    
    dem = 0;
    tree[dem++] = 0;
    d[0] = 1;
    for(i=0;i<n;i++)
        if(!d[i] && a[0][i])
        {
            temp.dau = 0;
            temp.cuoi = i;
            temp.val = a[0][i];
            pq.push(temp);
        }
    while(dem != n)
    {
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            if(!d[temp.cuoi])
            {
                tree[dem++] = temp.cuoi;
                d[temp.cuoi] = 1;
                break;
            }
        }
        if(temp.dau > temp.cuoi)
        {
            tg = temp.dau;
            temp.dau = temp.cuoi;
            temp.cuoi = tg;
        }
        kq.push(temp);
        for(i=0;i<n;i++)
            if(!d[i] && a[tree[dem-1]][i])
            {
                temp.dau = tree[dem-1];
                temp.cuoi = i;
                temp.val = a[tree[dem-1]][i];
                pq.push(temp);
            }
    }
    while(!kq.empty())
    {
        temp = kq.top();
        kq.pop();
        printf("%c-%c %d\n",temp.dau+65,temp.cuoi+65,a[temp.dau][temp.cuoi]);
    }
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    int gt;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(!j)
                    scanf("%d",&gt);
                else
                    scanf(",%d",&gt);
                a[i][j] = gt;
            }
        }
        printf("Case %d:\n",id++);
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "1235.inp"
#define fo "1235.out"
/**/
using namespace std;
/**/
struct lock{
                int x,y;
                int len;
            };
            
class sosanh{
public:
    bool operator()(lock u,lock v)
    {
        if(u.len > v.len)
            return true;
        return false;
    }
};
bool d[510];
int a[510][510];
priority_queue<lock, vector<lock>, sosanh > pq;
char key[510][6];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            a[i][j] = 32000;
        d[i] = true;
    }
}
/**/
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
int rotation(char s1[],char s2[])
{
    int i;
    int len,tmp;
    len = 0;
    i = 0;
    while(s1[i])
    {
        tmp = _abs((s1[i] - 48) - (s2[i] - 48));
        len += min(tmp,10-tmp);
        i++;
    }
    return len;
}
/**/
void solve()
{
    int i;
    int dem;
    lock m;
    int mr;
        
    while(!pq.empty())
        pq.pop();
        
    mr = rotation(key[1],key[0]);
    m.x = 1;
    d[1] = false;
    for(i=1;i<=n;i++)
        if(d[i])
        {
            mr = min(rotation(key[i],key[0]),mr);
            m.y = i;
            m.len = a[m.x][m.y];
            pq.push(m);
        }
    
    dem = 1;
    while(dem != n)
    {
        while(!pq.empty())
        {
            m = pq.top();
            pq.pop();
            if(d[m.y])
            {
                d[m.y] = false;
                mr += m.len;
                m.x = m.y;
                dem++;
                break;
            }
        }
        if(dem == n)
            break;
            
        for(i=1;i<=n;i++)
            if(d[i])
            {
                m.y = i;
                m.len = a[m.x][m.y];
                pq.push(m);
            }
    }
    printf("%d\n",mr);
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    strcpy(key[0],"0000");
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        for(i=1;i<=n;i++)
        {
            scanf("%s",&key[i]);
            for(j=i-1;j>=1;j--)
                a[i][j] = a[j][i] = rotation(key[i],key[j]);
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

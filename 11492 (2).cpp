#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "11492.inp"
#define fo "11492.out"
/**/
using namespace std;
/**/
struct data{
                int x,y,gt;
            };
struct babel{
                int id;
                long val;
            };
            
class sosanh{
public:
    bool operator()(babel i,babel j){
        if(i.id == j.id)
        {
            if(i.val > j.val)
                i.val = j.val;
            else
                j.val = i.val;
            return false;
        }
        if(i.val > j.val)
            return true;
        return false;
    }
};
priority_queue <babel, vector <babel>, sosanh> pq;
map <string, int> mmap;
long a[20010][20010],d[20010];
char dau[100],cuoi[100];
data noi[20010];
long nhan[20010];
int n,duong;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            a[i][j] = 2000000000;
            a[j][i] = 2000000000;
        }
        a[i][i] = 2000000000;
        d[i] = 0;
        nhan[i] = 2000000000;
    }
    
    for(i=0;i<duong;i++)
        if(!((noi[i].x == mmap[dau] && noi[i].y == mmap[cuoi]) || (noi[i].x == mmap[cuoi] && noi[i].y == mmap[dau])))
        {
            if(a[noi[i].x][noi[i].y] == 2000000000)
            {
                a[noi[i].x][noi[i].y] = noi[i].gt;
                a[noi[i].y][noi[i].x] = noi[i].gt;
            }
        }
        else
            a[noi[i].x][noi[i].y] = noi[i].gt;
}
/**/
babel timnhan()
{
    babel temp;
    temp.id = -1;
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        if(d[temp.id] == 0)
            break;
        else
            temp.id = -1;
    }
    return temp;
}
/**/
/**/
void gannhan(int xp)
{
    int i;
    babel j;
    for(i=1;i<n;i++)
        if(nhan[xp] + a[xp][i] < nhan[i])
        {
            nhan[i] = nhan[xp] + a[xp][i];
            if(d[i] == 0)
            {
                j.id = i;
                j.val = nhan[i];
                pq.push(j);
            }
        }
}
/**/
void reset2()
{
    int i;
    for(i=0;i<n;i++)
    {
        d[i] = 0;
        nhan[i] = 2000000000;
    }
    while(!pq.empty())
        pq.pop();
}
/**/
void solve()
{
    babel io;
    long value;
    int s,e;
    s = mmap[dau];
    e = mmap[cuoi];
    nhan[s] = 0;
    io.id = s;
    io.val = 0;
    pq.push(io);
    
    do
    {
        io = timnhan();
        if(io.id == -1 || io.id == e)
            break;
        d[io.id] = 1;
        gannhan(io.id);
    }while(true);
    
    value = nhan[e];
    reset2();
    
    s = mmap[cuoi];
    e = mmap[dau];
    nhan[s] = 0;
    io.id = s;
    io.val = 0;
    pq.push(io);
    
    do
    {
        io = timnhan();
        if(io.id == -1 || io.id == e)
            break;
        d[io.id] = 1;
        gannhan(io.id);
    }while(true);
    
    if(nhan[e] < value)
        value = nhan[e];
        
    if(value != 2000000000)
        printf("%ld\n",value);
    else
        printf("impossivel\n");
}
/**/
void input()
{
    int i;
    int id;
    char s[100];
    while(true)
    {
        scanf("%d",&duong);
        if(!duong)
            break;
        mmap.clear();
        scanf("%s %s",&dau,&cuoi);
        id = 1;
        if(mmap[dau] == 0)
            mmap[dau] = id++;
        if(mmap[cuoi] == 0)
            mmap[cuoi] = id++;
            
        for(i=0;i<duong;i++)
        {
            scanf("%s",&s);
            if(mmap[s] == 0)
            {
                mmap[s] = id;
                noi[i].x = id;
                id++;
            }
            else
                noi[i].x = mmap[s];
            
            scanf("%s",&s);
            if(mmap[s] == 0)
            {
                mmap[s] = id;
                noi[i].y = id;
                id++;
            }
            else
                noi[i].y = mmap[s];
            scanf("%s",&s);
            noi[i].gt = strlen(s);
        }
        n = id;
        khoitao();
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

#define fi "10986.inp"
#define fo "10986.out"

#define maxx 20000
#define maxx_val 200000000ll

/**/

struct emails{
                long value;
                int id;
            };
            
class sosanh
{
public:
    bool operator()(emails &t1, emails &t2)
    {
        if(t1.id == t2.id)
        {
            if(t1.value > t2.value)
                t1.value = t2.value;
            else
                t2.value = t1.value;
            return false;
        }
        if(t1.value > t2.value)
            return true;
        return false;
    }
};

priority_queue <emails, vector <emails>, sosanh> pq;
vector <pair<int, int> > a[maxx+10];

int itest, ntest;
int nser, begin, end;
long nway;

int d[maxx+10];
long kc[maxx+10];

///////
void init()
{
    int i, j;
    
    for (i=0; i<nser; i++)
    {
        a[i].clear();
        d[i] = 0;
        kc[i] = maxx_val + 10;    
    }  
    while(!pq.empty())
        pq.pop();
}
emails timmin()
{
    emails temp;
    temp.id = -1;
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        if(d[temp.id] == 1)
            temp.id = -1;
        else
            break;
    }
    return temp;
}
void suanhan(int xp)
{
    int i;
    emails temp;
    for (i=0; i<a[xp].size(); i++)
        if (kc[xp] + a[xp][i].second < kc[a[xp][i].first])
        {
            kc[a[xp][i].first] = kc[xp] + a[xp][i].second;
            if(d[a[xp][i].first] == 0)
            {
                temp.id = a[xp][i].first;
                temp.value = kc[a[xp][i].first];
                pq.push(temp);
            }
        }
}
void solve()
{
    emails io;
    
    io.id = begin;
    io.value = 0;
    pq.push(io);    
    kc[begin] = 0;
    do
    {
        io = timmin();
        
        if (io.id == -1 || io.id == end)
            break;
            
        d[io.id] = 1;
            
        suanhan(io.id);
        
    } while (true);
    
    printf("Case #%d: ", itest);
    
    if (kc[end] != maxx_val + 10 && io.id != -1)
        printf("%ld\n", kc[end]);
    else
        printf("unreachable\n");
}
void input()
{
    int x, y, gt;
    long i;
    
    scanf("%d", &ntest);
    
    for (itest=1; itest<=ntest; itest++)
    {
        scanf("%d %ld %d %d", &nser, &nway, &begin, &end);
        
        init();
        
        for (i=0; i<nway; i++)
        {
            scanf("%d %d %d", &x, &y, &gt);
            
            a[x].push_back(make_pair(y,gt));
            a[y].push_back(make_pair(x,gt));

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

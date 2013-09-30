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

#define fi "1203.inp"
#define fo "1203.out"
/**/
using namespace std;
/**/
struct argus{
                int id;
                long val;
            };
            
class sosanh{
public:
    bool operator()(argus a,argus b){
        if(a.val > b.val)
            return true;
        else if(a.val == b.val)
            if(a.id > b.id)
                return true;
        return false;
    }
};

map <int, long> mmap;
priority_queue <argus, vector <argus>, sosanh> pq;
int n;
/**/
void solve()
{
    argus temp,tg;
    int dem;
    dem = 0;
    while(dem < n)
    {
        if(!pq.empty())
        {
            temp = pq.top();
            printf("%d\n",temp.id);
            dem++;
            pq.pop();
            tg = pq.top();
            temp.val += mmap[temp.id];
            while(temp.val < tg.val && dem < n)
            {
                printf("%d\n",temp.id);
                temp.val += mmap[temp.id];
                dem++;
            }
            pq.push(temp);
        }
    }
}
/**/
void input()
{
    argus q;
    char temp[1000],name[100];
    while(true)
    {
        gets(temp);
        if(temp[0] == '#')
            break;
        sscanf(temp,"%s %d %ld",&name,&q.id,&q.val);
        mmap[q.id] = q.val;
        pq.push(q);
    }
    scanf("%d",&n);
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

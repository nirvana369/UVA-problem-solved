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

#define fi "10901.inp"
#define fo "10901.out"
/**/
using namespace std;
/**/
struct data{
                long long gt,vt;
            };
queue <data> l;
queue <data> r;
int n,t,m;
long long arr[11000];
/**/
void solve()
{
    data temp;
    long long start;
    int dem;
    int i,id;
    bool left;
    left = true;
    start = 0;
    dem = 0;
    id = 0;
    while(!l.empty() || !r.empty())
    {
        if(left)
        {
            while(!l.empty())
            {
                temp = l.front();
                if(temp.gt <= start)
                {
                    arr[temp.vt] = start + t;
                    dem++;
                    l.pop();
                }
                else
                    break;
                if(dem == n)
                    break;
            }
                
            if(!r.empty())
                temp = r.front();
            else
                temp.gt = start+t;
            if(dem != 0 || start >= temp.gt)
            {
                left = false;
                start += t;
            }
            else
                start++;
        }
        else
        {
            while(!r.empty())
            {
                temp = r.front();
                if(temp.gt <= start)
                {
                    arr[temp.vt] = start + t;
                    dem++;
                    r.pop();
                }
                else
                    break;
                if(dem == n)
                    break;
            }
                
            if(!l.empty())
                temp = l.front();
            else
                temp.gt = start + t;
            if(dem != 0 || start >= temp.gt)
            {
                left = true;
                start += t;
            }
            else
                start++;
        }
        dem = 0;
    }
    for(i=0;i<m;i++)
        printf("%lld\n",arr[i]);
}
/**/
void input()
{
    int i;
    char s[10];
    data min;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&n,&t,&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld %s",&min.gt,&s);
            min.vt = i;
            if(s[0] == 'r')
                r.push(min);
            else
                l.push(min);
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

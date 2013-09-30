/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "540.inp"
#define fo "540.out"
/**/
using namespace std;
/**/
struct tq{
            long gt,lv,t;
        };
        
class sosanh{
public:
    bool operator()(tq t1, tq t2)
    {
        if(t1.lv > t2.lv)
            return true;
        if(t1.lv == t2.lv)
            if(t1.t > t2.t)
                return true;
        return false;
    }    
};
int d[1100],vt[1000100];
priority_queue<tq, vector<tq>, sosanh > pq;
/**/
void khoitao()
{
    long i;
    for(i=0;i<1000000;i++)
        vt[i] = 0;
    while(!pq.empty())
        pq.pop();
}
/**/
void input()
{
    tq q,tmp;
    int i,j,k;
    long val,tt,id;
    int ele,n;
    char s[100];
    k = 1;
    while(scanf("%d",&n) && n)
    {
        printf("Scenario #%d\n",k++);
        khoitao();
        id = tt = 1;
        for(i=1;i<=n;i++)
        {
            d[i] = 200000;
            scanf("%d",&ele);
            for(j=0;j<ele;j++)
            {
                scanf("%ld",&val);
                vt[val] = i;
            }
        }
        while(true)
        {
            scanf("%s",&s);
            if(s[0] == 'S')
                break;
            if(s[0] == 'E')
            {
                scanf("%ld",&val);
                if(vt[val])
                {
                    if(d[vt[val]] == 200000)
                        d[vt[val]] = id++;
                    q.gt = val;
                    q.t = tt++;
                    q.lv = d[vt[val]];
                    pq.push(q);
                }
            }
            else
            {
                if(!pq.empty())
                {
                    q = pq.top();
                    pq.pop();
                    printf("%ld\n",q.gt);
                    
                    if(!pq.empty())
                        tmp = pq.top();
                    if(pq.empty() || q.t != tmp.t)
                        d[vt[q.gt]] = 200000;
                }
                else
                    printf("\n");
            }
        }
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

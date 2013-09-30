/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
//#include <map>

#define fi "10871.inp"
#define fo "10871.out"
/**/
using namespace std;
/**/
struct data{
                long long val;
                int vt;
            };
int a[10100];
int n;
/**/
bool chk(long long val)
{
    int i;
    int tmp,add;
    
    if(val == 2 || val == 3)
        return true;
    if(val < 2 || !(val % 2) || !(val % 3))
        return false;
    
    tmp = (int)sqrt(val);
    add = 2;
    for(i=5;i<=tmp;i+=add,add=6-add)
        if(!(val % i))
            return false;
    return true;
}
/**/
void input()
{
    int i,j;
    int ntest;
    int xp,kt;
    vector<data > p;
    queue<data > q;
    data t,tmp,f;
    int len;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        len = 11000;
        while(!q.empty())
            q.pop();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            p.clear();
            while(!q.empty() && len > 1)
            {
                t = q.front();
                //printf("val = %lld  pos = %d\n",t.val,t.vt);
                q.pop();
                tmp.val = a[i] + t.val;
                tmp.vt = t.vt;
                
                if(tmp.val >= 2 && chk(tmp.val))
                {
                    if(i - t.vt < len)
                    {
                        len = i - t.vt;
                        xp = t.vt;
                        kt = i;
                    }
                }
                p.push_back(tmp);
            }
            t.val = a[i];
            t.vt = i;
            q.push(t);
            for(j=0;j<p.size();j++)
                q.push(p[j]);
        }
        if(len == 11000)
            printf("This sequence is anti-primed.\n");
        else
        {
            printf("Shortest primed subsequence is length %d:",len+1);
            for(i=xp;i<=kt;i++)
                printf(" %d",a[i]);
            printf("\n");
        }
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

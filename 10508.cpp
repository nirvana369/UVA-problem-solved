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

#define fi "10508.inp"
#define fo "10508.out"
/**/
using namespace std;
/**/
struct morphing{
                    char w[10000];
                    int val;
                };
class sosanh{
public:
    bool operator()(morphing &a,morphing &b)
    {
        if(a.val > b.val)
            return true;
        return false;
    }
};
priority_queue <morphing, vector <morphing>, sosanh> pq;
/**/
void input()
{
    morphing s,s1;
    int d[10000];
    int n,len;
    int i,j;
    
    while(!pq.empty())
        pq.pop();
    while(true)
    {
        n = 0;
        scanf("%d %d",&n,&len);
        if(!n)
            break;
        scanf("%s",&s.w);
        s.val = 0;
        pq.push(s);
        for(i=1;i<n;i++)
        {
            scanf("%s",&s1.w);
            for(j=0;j<len;j++)
                d[j] = 0;
            s1.val = 0;
            for(j=0;j<len;j++)
                if(s1.w[j] != s.w[j])
                    s1.val++;
            pq.push(s1);
        }
        while(!pq.empty())
        {
            s = pq.top();
            cout << s.w << endl;
            pq.pop();
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

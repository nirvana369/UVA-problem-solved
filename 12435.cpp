/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "12435.inp"
#define fo "12435.out"
/**/
using namespace std;
/**/
struct toado{
                long x,y;
            };
toado p[1010];
long ss[1000010];
//priority_queue<long, vector<long > , greater<long > > pq;  //<-- tle 
long c;
int n;
/**/
void solve(int id)
{
    long hear;
    long i;
    
    sort(ss,ss+c);
    
    hear = 2;
    for(i=1;i<c;i++)
        if(ss[i] != ss[i-1])
            hear++;
    printf("Case %d: %ld\n",id,hear);
}
/**/
long dist(long a,long b)
{
    return (a*a + b*b);
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        
        c = 0;
            
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld",&p[i].x,&p[i].y);
            for(j=i-1;j>=0;j--)
                ss[c++] = dist(p[i].x - p[j].x , p[i].y - p[j].y);
        }

        solve(id++);
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

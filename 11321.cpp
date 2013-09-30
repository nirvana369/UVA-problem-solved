/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "11321.inp"
#define fo "11321.out"
/**/
using namespace std;
/**/
int n,m;
class sosanh{
public:
    bool operator()(long a,long b)
    {
        long tmpa,tmpb;
        
        if(a < 0)
            tmpa = -a;
        else
            tmpa = a;
            
        if(b < 0)
            tmpb = -b;
        else
            tmpb = b;
        
        if(a % m > b % m)
            return true;
        else if(a % m == b % m)
        {
            if(!(tmpa % 2) && (tmpb % 2))
                return true;
            else if((tmpa % 2) && (tmpb % 2))
            {
                if(a < b)
                    return true;
            }
            else if(!(tmpa % 2) && !(tmpb % 2))
            {
                if(a > b)
                    return true;
            }
        }
        return false;
    }
};
priority_queue<long, vector <long >, sosanh > pq;
/**/
void input()
{
    int i;
    long val;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
            
        while(!pq.empty())
            pq.pop();
            
        for(i=0;i<n;i++)
        {
            scanf("%ld",&val);
            pq.push(val);
        }
        printf("%d %d\n",n,m);
        while(!pq.empty())
        {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    printf("0 0\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

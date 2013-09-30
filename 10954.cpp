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

#define fi "10954.inp"
#define fo "10954.out"
/**/
using namespace std;
/**/
void input()
{
    int i,n;
    long temp;
    long long tong;
    
    priority_queue <long, vector <long>, greater <long> > pq; 
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&temp);
            pq.push(temp);
        }
        tong = 0;
        while(true)
        {
            temp = pq.top();
            pq.pop();
            temp += pq.top();
            tong += temp;
            pq.pop();
            pq.push(temp);
            if(pq.size() == 1)
                break;
        }
        printf("%lld\n",tong);
        while(!pq.empty())
            pq.pop();
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

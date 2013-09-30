/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "11242.inp"
#define fo "11242.out"
/**/
using namespace std;
/**/
priority_queue<double, vector<double> , greater<double> > pq;
int f[11],r[11];
int fr,re;
/**/
void input()
{
    int i,j;
    double tmp,tmp1,msp;
    
    while(scanf("%d %d",&fr,&re) && fr)
    {
        for(i=0;i<fr;i++)
            scanf("%d",&f[i]);
        for(i=0;i<re;i++)
            scanf("%d",&r[i]);
        for(i=0;i<fr;i++)
            for(j=0;j<re;j++)
            {
                tmp = (double)r[j] / f[i];
                pq.push(tmp);
            }
        msp = 0;
        while(!pq.empty())
        {
            tmp = pq.top();
            pq.pop();
            tmp1 = pq.top();
            msp = (tmp1/tmp) > msp ? (tmp1/tmp) : msp;
        }
        printf("%0.2lf\n",msp);
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

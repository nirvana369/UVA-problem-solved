/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <iostream>

#define fi "11995.inp"
#define fo "11995.out"
/**/
using namespace std;
/**/
map <int, int> mmap;
priority_queue <int, vector <int>, less <int> > pq;
queue <int> myqueue;
stack <int> mystack;
int isq,iss,ispq;
/**/
void output()
{
    int temp;
    temp = isq + iss + ispq;
    if(temp == 0)
        printf("impossible");
    if(temp > 1)
        printf("not sure");
    else if(isq)
        printf("queue");
    else if(iss)
        printf("stack");
    else if(ispq)
        printf("priority queue");
    printf("\n");
}
/**/
void input()
{
    int i;
    int n,lenh,gt;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        while(!pq.empty())
            pq.pop();
        while(!mystack.empty())
            mystack.pop();
        while(!myqueue.empty())
            myqueue.pop();
        isq = 1;
        iss = 1;
        ispq = 1;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&lenh,&gt);
            if(lenh == 1)
            {
                mystack.push(gt);
                myqueue.push(gt);
                pq.push(gt);
            }
            else
            {
                if(!myqueue.empty() && myqueue.front() == gt)
                    myqueue.pop();
                else
                    isq = 0;
                    
                if(!mystack.empty() && mystack.top() == gt)
                    mystack.pop();
                else
                    iss = 0;
                    
                if(!pq.empty() && pq.top() == gt)
                    pq.pop();
                else
                    ispq = 0;
            }
        }
        output();
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

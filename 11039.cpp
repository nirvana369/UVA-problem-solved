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

#define fi "11039.inp"
#define fo "11039.out"
/**/
using namespace std;
/**/
priority_queue <long, vector <long>, greater <long> > red;
priority_queue <long, vector <long>, less <long> > blue;
/**/
void solve()
{
    long kq;
    int flag;
    bool lonhon;
    long b,r,temp;
    kq = 0;
    if(blue.empty() && red.empty())
        kq = 0;
    else if(blue.empty() || red.empty())
        kq = 1;
    else
    {
        if(!blue.empty()) 
            b = blue.top();
        if(!red.empty())  
            r = red.top();
        if(b * -1 <= r)
        {
            flag = -1;
            blue.pop();
            red.pop();
            temp = r;
        }
        else
        {
            flag = 1;
            blue.pop();
            red.pop();     
            temp = b * -1;
        }
        kq = 2;
        while(true)
        {
            if(flag < 0)
            {
                lonhon = false;
                flag = 1;
                while(!blue.empty())
                {
                    b = blue.top();
                    blue.pop();
                    if(b*-1 >= temp)
                    {
                        temp = b*-1;
                        kq++;
                        lonhon = true;
                        break;
                    }
                    
                }
                if(!lonhon)
                    break;
            }
            else
            {
                flag = -1;
                lonhon = false;
                while(!red.empty())
                {
                    r = red.top();
                    red.pop();
                    if(r >= temp)
                    {
                        temp = r;
                        kq++;
                        lonhon = true;
                        break;
                    }
                }
                if(!lonhon)
                    break;
            }
        }
    }
    printf("%ld\n",kq);
}
/**/
void input()
{
    long i;
    long val,nfloor;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&nfloor);
        while(!blue.empty())
            blue.pop();
        while(!red.empty())
            red.pop();
        for(i=0;i<nfloor;i++)
        {
            scanf("%ld",&val);
            if(val < 0)
                blue.push(val);
            else
                red.push(val);
        }
        solve();
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

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
#include <vector>

#define fi "12541.inp"
#define fo "12541.out"
/**/
using namespace std;
/**/
struct birth{
                char name[100];
                int month,date,year;
            };
birth t,y,o;
/**/
void input()
{
    int i;
    int n;
    while(scanf("%d",&n) == 1)
    {
        y.year = 0;
        o.year = 10000;
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d %d",&t.name,&t.date,&t.month,&t.year);
            if(t.year >= y.year)
            {
                if(y.year == t.year)
                {
                    if(y.month == t.month)
                    {
                        if(t.date > y.date)    
                            y = t;
                    }
                    else if(t.month > y.month)
                        y = t;
                }
                else
                    y = t;
            }
            
            if(t.year <= o.year)
            {
                if(t.year == o.year)
                {
                    if(t.month == o.month)
                    {
                        if(t.date < o.date)
                            o = t;
                    }
                    else if(t.month < o.month)
                        o = t;
                }
                else
                    o = t;
            }
        }
        printf("%s\n%s\n",y.name,o.name);
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

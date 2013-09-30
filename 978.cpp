/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "978.inp"
#define fo "978.out"
/**/
using namespace std;
/**/
priority_queue<int ,vector<int>, less<int> > b,g;
int bhurt[100100],ghurt[100100];
long green,blue,ngame;
/**/
void input()
{
    long i;
    int hurt;
    int id;
    int ntest;
    
    scanf("%d",&ntest);
    id = 0;
    while(ntest--)
    {
        scanf("%ld %ld %ld",&ngame,&blue,&green);
        while(!b.empty())
            b.pop();
        while(!g.empty())
            g.pop();    
        for(i=0;i<blue;i++)
        {
            scanf("%d",&hurt);
            b.push(hurt);
        }
        for(i=0;i<green;i++)
        {
            scanf("%d",&hurt);
            g.push(hurt);
        }
        while(!b.empty() && !g.empty())
        {
            blue = 0;
            green = 0;
            i = 0;
            while(i < ngame && !b.empty() && !g.empty())
            {
                hurt = b.top() - g.top();
                b.pop();
                g.pop();
                if(hurt > 0)
                    bhurt[blue++] = hurt;
                if(hurt < 0)
                    ghurt[green++] = -hurt;
                i++;
            }
            for(i=0;i<blue;i++)
                b.push(bhurt[i]);
            for(i=0;i<green;i++)
                g.push(ghurt[i]);
        }
        if(id)
            printf("\n");
        if(b.empty() && g.empty())
            printf("green and blue died\n");
        else if(b.empty())
        {
            printf("blue wins\n");
            while(!g.empty())
            {
                cout << g.top() << endl;
                g.pop();
            }
        }
        else
        {
            printf("green wins\n");
            while(!b.empty())
            {
                cout << b.top() << endl;
                b.pop();
            }
        }
        id++;
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10730.inp"
#define fo "10730.out"
/**/
using namespace std;
/**/
int n;
int d[31020],d1[31020],d2[31020],d3[31020];
bool not_arith;
/**/
void _reset()
{
    int i;
    for(i=0;i<=n*3+3;i++)
        d[i] = d1[i] = d2[i] = d3[i] = 0;
    not_arith = true;
}
void input()
{
    int i;
    char colon[3];
    int val;
    while(scanf("%d",&n) && n)
    {
        scanf("%s",&colon);
        _reset();
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            val += n*2;

            if(not_arith)
            {
                if(d[val-1])
                {
                    d[val] = d[val-1] + 1;
                    if(d[val] == 3)
                        not_arith = false;
                }
                else
                    d[val] = 1;
                    
                if(d1[val-2])
                {
                    d1[val] = d1[val-2] + 1;
                    if(d1[val] == 3)
                        not_arith = false;
                }
                else
                    d1[val] = 1;
                    
                if(d2[val+1])
                {
                    d2[val] = d2[val+1] + 1;
                    if(d2[val] == 3)
                        not_arith = false;
                }
                else
                    d2[val] = 1;
                    
                if(d3[val+2])
                {
                    d3[val] = d3[val+2] + 1;
                    if(d3[val] == 3)
                        not_arith = false;
                }
                else
                    d3[val] = 1;
            }
        }

        if(not_arith)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
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

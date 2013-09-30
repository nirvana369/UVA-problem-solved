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

#define fi "11849.inp"
#define fo "11849.out"
/**/
using namespace std;
/**/
queue <long long> jcd;
long long ja,ji;
/**/
void input()
{
    long long i;
    long long dem;
    long long temp,gt;
    
    while(true)
    {
        cin >> ja >> ji;
        if(!ja && !ji)
            break;
        while(!jcd.empty())
            jcd.pop();
        for(i=0;i<ja;i++)
        {
            cin >> temp;
            jcd.push(temp);
        }
        dem = 0;
        for(i=0;i<ji;i++)
        {
            cin >> temp;
            if(!jcd.empty())
            {
                gt = jcd.front();
                
                while(gt < temp)
                {
                    jcd.pop();
                    if(jcd.empty())
                        break;
                    gt = jcd.front();
                }
                
                if(gt == temp)
                    dem++;
            }
        }
        cout << dem << endl;
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

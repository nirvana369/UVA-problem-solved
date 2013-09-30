/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "997.inp"
#define fo "997.out"
/**/
using namespace std;
/**/
char s[100000];
int n;
/**/
vector<long long> solve(int vt)
{
    int i,dem;
    char tmp[100];
    long long val;
    vector<long long > a,b;
    
    a.clear();
    dem = 0;
    while(s[vt])
    {
        if(s[vt] == ']')    
        {
            tmp[dem] = 0;
            sscanf(tmp,"[ %d",&val);
            for(i=0;i<n;i++)
                a.push_back(val);
            return a;
        }
        else if(s[vt] == '+')
        {
            tmp[dem] == 0;
            sscanf(tmp,"[ %d",&val);
            
            b = solve(vt+1);
            a.push_back(val);
            
            for(i=1;i<n;i++)
                a.push_back(a[i-1]+b[i-1]);
                
            return a;
        }
        else if(s[vt] == '*')
        {
            tmp[dem] == 0;
            sscanf(tmp,"[ %d",&val);
            
            b = solve(vt+1);
            
            a.push_back(b[0] * val);
            
            for(i=1;i<n;i++)
                a.push_back(b[i] * a[i-1]);
        }
        else
            tmp[dem++] = s[vt];
        vt++;
    }
}
/**/
void input()
{
    int i;
    vector<long long> a;
    
    while(scanf("%s %d",&s,&n) == 2)
    {
        a = solve(0);
    
        for(i=0;i<n;i++)
        {
            if(i)
                printf(" ");
            printf("%d" , a[i]);
        }
        printf("\n");
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

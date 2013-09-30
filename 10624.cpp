/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10624.inp"
#define fo "10624.out"
/**/
using namespace std;
/**/
int num[32];
bool match;
int n,m;
/**/
bool chk(int x)
{
    int i;
    int val;

    if(x < n)
        return true;
        
    val = 0;

    for(i=1;i<=x;i++)
    {
        val *= 10;
        val += num[i];
        if(val >= x)
            val %= x;
    }
    return !val;
}
/**/
void findnum(int id)
{
    int i;
    int start;
    
    if(id > m)
    {
        match = true;
        return;
    }
    if(id != 1)
        start = 0;
    else
        start = 1;
        
    for(i=start;i<10;i++)
    {
        num[id] = i;
        
        if(chk(id))
            findnum(id+1);
        
        if(match)
            return;
    }
}
/**/
void output(int id)
{
    int i;
    
    printf("Case %d: ",id);
    
    if(match)
        for(i=1;i<=m;i++)
            printf("%d",num[i]);
    else
        printf("-1");
        
    printf("\n");
}
/**/
void input()
{
    int id;
    int ntest;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        
        match = false;
        
        findnum(1);
        
        output(id++);
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

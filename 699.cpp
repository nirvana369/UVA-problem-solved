/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "699.inp"
#define fo "699.out"
/**/
using namespace std;
/**/
int t[1100];
/**/
void ctree(int val,int id)
{
    if(val == -1)
        return;
        
    t[id] += val; // overlap
    
    scanf("%d",&val);
    
    ctree(val,id-1);    // go left
    
    scanf("%d",&val); // go right
    
    ctree(val,id+1);
}
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<=1000;i++)
        t[i] = 0;
}
/**/
void input()
{
    int i,id;
    int val;
    
    id = 1;
    while(scanf("%d",&val) == 1)
    {
        if(val == -1)
            break;
            
        khoitao();
        
        ctree(val,500);
        
        for(i=500;i>=0;i--)
            if(!t[i])
            {
                i++;
                break;
            }
        printf("Case %d:\n",id++);
        printf("%d",t[i++]);
        while(t[i])
        {
            printf(" %d",t[i]);
            i++;
        }
        printf("\n\n");
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

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

#define fi "907.inp"
#define fo "907.out"
/**/
using namespace std;
/**/
int camp[610];
int low,high,mid,n,k;
/**/
bool solve()
{
     int go,day;
     int i;
     
     go = day = 0;
     
     for(i=0;i<=n;i++)
         if(go + camp[i] < mid)
            go += camp[i];
         else
         {
             go += camp[i];
             day++;
             
             if( go == mid ) 
                go = 0;
             else
             {
                 if(camp[i] > mid)
                    return false;
                 else 
                    go = camp[i];
             }    
             
             if(day > k) 
                return false;
         }
     
     if(go) 
        day++;
        
     if(day > k) 
        return false;
     return true;
}
/**/
void input()
{
    int i;
    int ans;
    while(scanf("%d %d",&n,&k) == 2)
    {
        k++;
        high = 0;
           
        for(i=0;i<=n;i++)
        {
           scanf("%d",&camp[i]);
           high += camp[i];
        }
           //load
        ans = high * 2;
        low = 0;
    
        while(low <= high)
        {
            mid = (high + low) / 2;
              
            if(solve())
            {
                ans = ans < mid ? ans : mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
    
        printf("%d\n",ans);    
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

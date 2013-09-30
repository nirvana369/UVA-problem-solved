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

#define fi "10722.inp"
#define fo "10722.out"
/**/
using namespace std;
/**/
int way[110][130];
int n,b;
/**/
int dfs(int len,int bas)
{
    int i,j;
    int sum;

    if(!bas)
        return 0;
        
    if(way[len][bas])
        return way[len][bas];
        
    sum = 0;
    for(i=0;i<bas;i++)
        sum += dfs(len-1,i);
    sum--;
    way[len][bas] = sum;
    return sum;
}
/**/
void input()
{
    int i,j;
    while(scanf("%d %d",&b,&n))
    {
        if(!b && !n)
            break;
        for(i=0;i<=b;i++)
            for(j=1;j<=n;j++)
                if(j == 1 && i)
                    way[j][i] = 1;
                else
                    way[j][i] = 0;
        int kq = dfs(n,b-1);
        printf("%d\n",kq);
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

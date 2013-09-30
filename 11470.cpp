/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11470.inp"
#define fo "11470.out"
/**/
using namespace std;
/**/
long t[10];
/**/
int getpos(int i,int j,int id,int h,int c)
{
    if(h > c)
        return 0;
        
    if(i == h || j == h || i == c || j == c)
        return id+1;
    return getpos(i,j,id+1,h+1,c-1);
}
/**/
void input()
{
    int i,j;
    int n,temp,id,cs;
    
    cs = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=1;i<=n;i++)
            t[i] = 0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&temp);
                id = getpos(i,j,0,1,n); 
                t[id] += temp;
            }
            
        printf("Case %d: ",cs);
        if(n % 2 == 0)
            id = n/2;
        else
            id = n/2 + 1;
        for(i=1;i<=id;i++)
        {
            if(i != 1)
                printf(" ");
            printf("%d",t[i]);
        }
        printf("\n");
        cs++;
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

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

#define fi "12269.inp"
#define fo "12269.out"
/**/
using namespace std;
/**/
double ver[1010],hor[1010];
int nx,ny;
double w;
/**/
void sapxep(double arr[],int maxa)
{
    int i,j;
    double temp;
    
    for(i=0;i<maxa-1;i++)
        for(j=i+1;j<maxa;j++)
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
bool solve(double arr[],int maxa,double leng)
{
    int i;
    double s;
    
    if(arr[0] - w > 0 || arr[maxa-1] + w < leng)
        return false;
    
    s = 0;
    for(i=0;i<maxa;i++)
    {
        if(arr[i] - w > s)
            return false;
        s = arr[i] + w;
    }
    return true;
}
/**/
void input()
{
    int i;
    while(scanf("%d %d %lf",&nx,&ny,&w) == 3)
    {
        w /= 2.0;
        if(!nx && !ny)
            break;
        for(i=0;i<nx;i++)
            scanf("%lf",&ver[i]);
            
        for(i=0;i<ny;i++)
            scanf("%lf",&hor[i]);
            
        sapxep(ver,nx);
        sapxep(hor,ny);
        
        if(!solve(hor,ny,100) || !solve(ver,nx,75))
            printf("NO\n");
        else
            printf("YES\n");
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

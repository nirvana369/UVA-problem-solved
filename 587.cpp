/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "587.inp"
#define fo "587.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
toado h[8];
/**/
void khoitao()
{
    double cheo;
    cheo = sqrt(2)/2;
    h[0].x = 1;
    h[0].y = 0;  
    
    h[1].x = cheo;
    h[1].y = cheo;   
    
    h[2].x = 0;
    h[2].y = 1;   
    
    h[3].x = -cheo;
    h[3].y = cheo;
    
    h[4].x = -1;
    h[4].y = 0;  
    
    h[5].x = -cheo;
    h[5].y = -cheo;
    
    h[6].x = 0;
    h[6].y = -1;   
    
    h[7].x = cheo;
    h[7].y = -cheo;
}
/**/
int getdir(char s[],int len)
{
    if(len == 1)
    {
        if(s[0] == 'N')
            return 0;
        if(s[0] == 'E')
            return 2;
        if(s[0] == 'S')
            return 4;
        return 6;
    }
    else
    {
        if(s[0] == 'N')
        {
            if(s[1] == 'W')
                return 7;
            if(s[1] == 'E')
                return 1;
        }
        else
        {
            if(s[1] == 'W')
                return 5;
            if(s[1] == 'E')
                return 3;
        }
    }
}
/**/
void solve(char s[])
{
    int i;
    int l,ds,dh,steps,dir;
    char step[100],huong[100];
    double x,y;
    
    l = strlen(s);
    ds = 0;
    dh = 0;
    x = y = 0;
    for(i=0;i<l;i++)
        if(s[i] == ',' || s[i] == '.')
        {
            step[ds] = 0;
            huong[dh] = 0;
            sscanf(step,"%d",&steps);
            dir = getdir(huong,dh);
            x = x + h[dir].x * steps;
            y = y + h[dir].y * steps;
            ds = 0;
            dh = 0;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            step[ds++] = s[i];
        else if(s[i] >= 'A' && s[i] <= 'Z')
            huong[dh++] = s[i];
    
    printf("The treasure is located at (%0.3lf,%0.3lf).\n",y,x);
    printf("The distance to the treasure is %0.3lf.\n\n",sqrt(x*x+y*y));
}
/**/
void input()
{
    char quit[1000],temp[10000];
    int id;
    
    strcpy(quit,"END");
    khoitao();
    id = 1;
    while(true)
    {
        gets(temp);
        if(strcmp(quit,temp) == 0)
            break;
        printf("Map #%d\n",id);
        solve(temp);
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

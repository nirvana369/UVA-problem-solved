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

#define fi "10377.inp"
#define fo "10377.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
char a[70][70];
int nhang,ncot,dir,x,y;
/**/
char getdir(int huong)
{
    if(huong == 0)
        return 'N';
    if(huong == 1)
        return 'E';
    if(huong == 2)
        return 'S';
    return 'W';
}
/**/
void dichuyen(char s[])
{
    int i;
    int px,py;
    i = 0;
    while(s[i] != 0)
    {
        if(s[i] == 'R')
        {
            dir++;
            if(dir > 3)
                dir = 0;
        }
        else if(s[i] == 'L')
        {
            dir--;
            if(dir < 0)
                dir = 3;
        }
        else if(s[i] == 'F')
        {
            px = x + h[dir].x;
            py = y + h[dir].y;
            if(px >= 0 && px < nhang && py >= 0 && py < ncot && a[px][py] == ' ')
            {
                x = px;
                y = py;
            }
        }
        else if(s[i] == 'Q')
            printf("%d %d %c\n",x+1,y+1,getdir(dir));
        i++;
    }
}
/**/
void input()
{
    int ntest;
    int i;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&nhang,&ncot);
        gets(a[0]);
        for(i=0;i<nhang;i++)
            gets(a[i]);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        dir = 0;
        gets(a[nhang]);
        while(true)
        {
            a[nhang][0] = 0;
            gets(a[nhang]);
            if(!a[nhang][0])
                break;
            dichuyen(a[nhang]);
        }
        if(ntest)
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

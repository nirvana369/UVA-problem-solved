/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "366.inp"
#define fo "366.out"
/**/
using namespace std;
/**/
void input()
{
    while(scanf("%d %d %d",&size,&ncot,&nhang))
    {
        if(!size && !ncot && !nhang)
            break;
        if(size >= nhang)
        {
            h = 0;
            tmp = nhang;
            while(tmp != 1)
            {
                nhang /= 2;
                h++;
            }
        }
        if(size >= ncot)
        {
            c = 0;
            tmp = ncot;
            while(tmp != 1)
            {
                
            }
        }
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

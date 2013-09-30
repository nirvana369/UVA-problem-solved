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

#define fi "11839.inp"
#define fo "11839.out"
/**/
using namespace std;
/**/
void input()
{
    int i,j;
    int val,id;
    bool color;
    int n;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            id = -1;
            color = true;
            for(j=0;j<5;j++)
            {
                scanf("%d",&val);
                if(val <= 127)
                {
                    if(id == -1)
                        id = j;
                    else
                        color = false;
                }
            }
            if(color && id != -1)
                printf("%c\n",id+65);
            else
                printf("*\n");
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

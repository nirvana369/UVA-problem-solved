/*
                                                            Hoang Linh
                                                    
                                        Problem: BACK TO HIGH SCHOOL PHYSICS - 10071 (10071.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10071.inp"
#define fo "10071.out"
/**/
using namespace std;
/**/
void input()
{
    int v,t;
    while(scanf("%d %d",&v,&t) == 2)
        printf("%d\n",2 * v * t);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

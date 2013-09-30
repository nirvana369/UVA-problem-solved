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

#define fi "756.inp"
#define fo "756.out"
/**/
using namespace std;
/**/
void input()
{
    int p,e,i,d;
    int id;
    
    id = 1;
    while (scanf("%d %d %d %d",&p,&e,&i,&d) == 4)
    {
        if(p == -1)
            break;
        while((p-e) % 28 != 0)
            p += 23;
            
        while((p-i) % 33 != 0)
            p+= 23 * 28;
            
        while(p > d)
            p -= 23 * 28 * 33;
        
        while(p <= d)
            p += 23 * 28 * 33;
    
        printf("Case %d",id++);
        printf(": the next triple peak occurs in %d days.\n",p-d);
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

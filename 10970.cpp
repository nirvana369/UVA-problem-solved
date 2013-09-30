/*
                                            Hoang Linh
                                            
                                  Problem: BIG CHOCOLATE - 10970 (10970.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10970.inp"
#define fo "10970.out"
/**/
void input()
{
    int m,n;
    long kq;
    
    while(true)
    {
        m = 0;
        scanf("%d %d",&m,&n);    
        if(m == 0)
            break;
        kq = m * n - 1;
        printf("%ld\n",kq);
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

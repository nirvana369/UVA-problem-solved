/*
                                                    Hoang Linh

*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11942.inp"
#define fo "11942.out"
/**/
using namespace std;
/**/
void input()
{
    int itest,i;
    int ntest;
    bool tang,giam;
    int a[10];
    printf("Lumberjacks:\n");
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        tang = false;
        giam = false;
        scanf("%d",&a[0]);
        for(i=1;i<10;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] > a[i-1])
                tang = true;
            if(a[i] < a[i-1])
                giam = true;
        }
        if(tang && giam)
        {
            if(tang)
                printf("Unordered\n");
            else
                printf("Ordered\n");
        }
        else
            printf("Ordered\n");
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

/*
                                                    Hoang Linh
                                                    
                                        Problem: INTERSECTING LINES - 378 (378.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "378.inp"
#define fo "378.out"
#define ndiem 4
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado point[4];
/**/
void solve()
{
    int a1,a2,b1,b2,c1,c2;
    int dem,k;
    float d,x,y;
    
    a1 = point[0].y - point[1].y;
    b1 = point[1].x - point[0].x;   
    c1 = (-1) * (a1*point[0].x + b1*point[0].y);
    //////////////
    a2 = point[2].y - point[3].y;
    b2 = point[3].x - point[2].x;   
    c2 = (-1) * (a2*point[2].x + b2*point[2].y);
    
    d = (float)(a1*b2 - a2*b1);
    if(d != 0)
    {
        x = (float)((b1*c2 - b2*c1) / d);
        y = (float)((c1*a2 - c2*a1) / d);
        printf("POINT %0.2f %0.2f\n",x,y);
    }
    else
    {
        dem = 0;
        for(k=2;k<ndiem;k++)
            if(point[k].x*a1 + point[k].y*b1 + c1 == 0)
                dem++;
        if(dem == 2)
            printf("LINE\n");
        else
            printf("NONE\n");
    }
}
/**/
void input()
{
    int ntest;
    int itest,i;
    scanf("%d",&ntest);
    printf("INTERSECTING LINES OUTPUT\n");
    for(itest=0;itest<ntest;itest++)
    {
        for(i=0;i<ndiem;i++)
            scanf("%d %d",&point[i].x,&point[i].y);
        solve();
    }
    printf("END OF OUTPUT\n");
}
/**/
main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
}

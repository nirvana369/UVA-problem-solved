/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "972.inp"
#define fo "972.out"
/**/
using namespace std;
/**/
struct hl{
            double h,l;
            };
double pf[110],pg[110];
hl f[110],g[110];
int nf,ng;

/**/
void input()
{
    double tmp,hig,xf,xg;
    int idf,idg;
    int i;
    
    while(scanf("%d",&nf) == 1)
    {
        tmp = 0;
        for(i=0;i<nf;i++)
        {
            scanf("%lf %lf",&f[i].h,&f[i].l);
            tmp += f[i].l;
            pf[i] = tmp;
        }
        
        scanf("%d",&ng);
        tmp = 0;
        for(i=0;i<ng;i++)
        {
            scanf("%lf %lf",&g[i].h,&g[i].l);
            tmp += g[i].l;
            pg[i] = tmp;
        }
        idf = idg = 0;
        hig = 1e7;
    
        while(idf < nf && idg < ng)
        {
            if(pf[idf] <= pg[idg])
            {
                hig = min(hig,max(f[idf].h,g[idg].h));
                idf++;
            }
            else
            {
                hig = min(hig,max(f[idf].h,g[idg].h));
                idg++;
            }
        }
        while(idf < nf)
        {
            hig = min(hig,max(f[idf].h,g[nf-1].h));
            idf++;
        }
        
        while(idg < ng)
        {
            hig = min(hig,max(f[nf-1].h,g[idg].h));
            idg++;
        }
        
        printf("%0.3lf\n",hig);
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

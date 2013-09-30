/*
                                                                Hoang Linh
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "201.inp"
#define fo "201.out"
/**/
using namespace std;
/**/
struct hv201{
                int h,v;
            };
hv201 d[10][10];
int hv[10];
int m,n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j].h=0;
            d[i][j].v=0;
        }
        hv[i]=0;
    }
}
/**/
bool kiemtra(int i,int j,int ifix,int jfix,int size)
{
    int dem;
    dem=0;
    while(d[ifix][j].h==1 && d[i][jfix].v==1)
    {
        dem++;
        i++;
        j++;
        if(dem==size)
            return true;
    }
    return false;        
}
/**/
void output()
{
    int i;
    bool tontaihv;
    tontaihv=false;
    for(i=1;i<=n;i++)
        if(hv[i]!=0)
        {
            tontaihv=true;
            printf("\n%d square (s) of size %d",hv[i],i);
        }
    if(!tontaihv)
        printf("\nNo completed squares can be found.");
    printf("\n");
}
/**/
void solve()
{
    int in,jn,itemp,jtemp;
    int dodai;
    
    for(in=1;in<=n;in++)
    {
        for(jn=1;jn<=n;jn++)
        {
            if(d[in][jn].h==1 && d[in][jn].v==1)
            {
                dodai=1;
                itemp=in;
                jtemp=jn;
                while(d[in][jtemp].h==1 && d[itemp][jn].v==1)
                {
                    if(kiemtra(in,jn,itemp+1,jtemp+1,dodai))
                        hv[dodai]++;
                    dodai++;
                    itemp++;
                    jtemp++;
                }
            }
        }
    }
    output();
}
/**/
void input()
{
    int im,id;
    int i,j;
    char chieu[2];
    id=1;
    scanf("%d",&n);
    while(n!=1)
    {
        printf("Problem #%d\n",id);
        khoitao();
        scanf("%d",&m);
        for(im=0;im<m;im++)
        {
            scanf("%s %d %d",&chieu,&i,&j);
            if(chieu[0]=='H')
                d[i][j].h=1;
            else
                d[j][i].v=1;
        }
        solve();
        n=1;
        scanf("%d",&n);
        if(n!=1)
        {
            id++;
            printf("\n**********************************\n\n");
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

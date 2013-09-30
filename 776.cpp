/*
                                                        Hoang Linh
                                                        
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "776.inp"
#define fo "776.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado huong[8],queue[40010];
char a[300][300];
int kq[300][300],d[300][300];
int h,c;
/**/
void khoitaohuong()
{
    huong[0].x = -1;
    huong[0].y = 0;
    
    huong[1].x = -1;
    huong[1].y = 1;
    
    huong[2].x = 0;
    huong[2].y = 1;
    
    huong[3].x = 1;
    huong[3].y = 1;
    
    huong[4].x = 1;
    huong[4].y = 0;
    
    huong[5].x = 1;
    huong[5].y = -1;
    
    huong[6].x = 0;
    huong[6].y = -1;
    
    huong[7].x = -1;
    huong[7].y = -1;
}
/**/
void mahoa(char s[],int id)
{
    int i,dem;
    int l;
    l = strlen(s);
    dem = 0;
    for(i=0;i<l;i++)
    {
        if(s[i] != ' ')
        {
            a[id][dem] = s[i];
            d[id][dem] = 0;
            dem++;
        }
    }
    c = dem;
}
/**/
void loang(int hang,int cot,char kt,int gt)
{
    int dau,cuoi;
    int i;
    toado vitri;
    
    dau = -1;
    cuoi = 0;
    
    queue[0].x = hang;
    queue[0].y = cot;
    d[hang][cot] = 1;
    kq[hang][cot] = gt;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<8;i++)
        {
            vitri.x = queue[dau].x + huong[i].x;
            vitri.y = queue[dau].y + huong[i].y;
            if(vitri.x >= 0 && vitri.x < h && vitri.y >= 0 && vitri.y < c)
                if(d[vitri.x][vitri.y] == 0 && a[vitri.x][vitri.y] == kt)
                {
                    cuoi++;
                    queue[cuoi].x = vitri.x;
                    queue[cuoi].y = vitri.y;
                    d[vitri.x][vitri.y] = 1;
                    kq[vitri.x][vitri.y] = gt;
                }
        }
    }
}
/**/
int laygt(int value)
{
    if(value > 9999)
        return 5;
    if(value > 999)
        return 4;
    if(value > 99)
        return 3;
    if(value > 9)    
        return 2;
    return 1;
}
/**/
int maxgt(int gt1,int gt2)
{
    if(gt1 > gt2)
        return gt1;
    return gt2;
}
/**/
void output()
{
    int i,j;
    int gt;
    int form[5000];
    
    for(i=0;i<c;i++)
        form[i] = 0;
        
    for(i=0;i<c;i++)
    {
        for(j=0;j<h;j++)
        {
           gt = laygt(kq[j][i]); 
           form[i] = maxgt(gt,form[i]);
        }
    }
    
    for(i=0;i<h;i++)
    {
        for(j=0;j<c;j++)
        {
            if(j != 0)
                printf(" ");
            if(form[j] == 5)
                printf("%5d",kq[i][j]);
            else if(form[j] == 4)
                printf("%4d",kq[i][j]);
            else if(form[j] == 3)
                printf("%3d",kq[i][j]);
            else if(form[j] == 2)
                printf("%2d",kq[i][j]);
            else
                printf("%d",kq[i][j]);
        }
        printf("\n");
    }
    printf("%%\n");
}
/**/
void solve()
{
    int i,j;
    int dem;
    dem = 1;
    
    for(i=0;i<h;i++)
        for(j=0;j<c;j++)
            if(d[i][j] == 0)
            {
                loang(i,j,a[i][j],dem);
                dem++;
            }
    output();
}
/**/
void input()
{
    int id;
    char temp[10000];
    khoitaohuong();
    id = 0;
    while(!feof(stdin))
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] != 0)
        {
            if(temp[0] == '%')
            {
                h = id;
                id = 0;
                solve();
            }
            else
            {
                mahoa(temp,id);
                id++;
            }
        }
    }
    h = id;
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

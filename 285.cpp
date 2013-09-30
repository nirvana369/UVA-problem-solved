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

#define fi "285.inp"
#define fo "285.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
int nhang,ncot;
char a[10000],b[10000],arr[200][200];
int da,maxcot,maxhang,db;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<120;i++)
        for(j=0;j<120;j++)
            arr[i][j] = ' ';
}
/**/
void xuly(char s[],int hang,int cot,int dir)
{
    int i;
    i = 0;
    while(s[i] != 0)
    {
        if(hang >= 0 && cot >= 0)
            arr[hang][cot] = s[i];
        if(hang > maxhang)
            maxhang = hang;
        if(cot > maxcot)
            maxcot = cot;
        hang += h[dir].x;
        cot += h[dir].y;
        i++;
    }
}
/**/
int getdir(char dir)
{
    if(dir == 'u')
        return 0;
    if(dir == 'r')
        return 1;
    if(dir == 'd')
        return 2;
    return 3;
}
/**/
void solve()
{
    int i,j;

    da = 0;
    for(i=0;i<=nhang;i++)
        for(j=0;j<=ncot;j++)
            if(arr[i][j] >= 'a' && arr[i][j] <= 'z')
                a[da++] = arr[i][j];
    a[da] = 0;
}
/**/
bool kt(char s[])
{
    int i;
    i = 0;
    while(s[i] != 0)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            b[db++] = s[i];
        if(s[i] == '$')
            return true;
        i++;
    }
    return false;
}
/**/
void input()
{
    int cot,hang;
    char dir[10],s[1000];
    int i;
    bool corr,iquit;
    
    while(true)
    {
        khoitao();
        maxcot = maxhang = 0;
        
        while(true)
        {
            s[0] = 0;
            scanf("%s",&s);
            if(!s[0])
                return;
            if(s[0] == '#')
                break;
            scanf("%d %d %s",&cot,&hang,&dir);
            cot--;
            hang--;
            
            xuly(s,hang,cot,getdir(dir[0]));
        }
        scanf("%d %d",&ncot,&nhang);
        ncot--;
        nhang--;
        solve();
        i = 0;
        corr = true;
        iquit = false;
        db = 0;
        while(!iquit)
        {
            scanf("%s",&s);
            iquit = kt(s);
        }
        b[db] = 0;
        if(ncot > maxcot || nhang > maxhang || strcmp(a,b) != 0)
            corr = false;
        if(corr)
            printf("The solution is correct.\n");
        else
            printf("The solution is incorrect.\n");
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

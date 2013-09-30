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

#define fi "466.inp"
#define fo "466.out"
/**/
using namespace std;
/**/
int n;
char p1[15][15],p2[15][15],p3[15][15];
/**/
void rotation()
{
    int i,j;
    for(i=n;i>=0;i--)
        for(j=0;j<=n;j++)
            p3[n-i][j] = p2[j][i];
}
/**/
void copyp()
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            p2[i][j] = p3[i][j];
}
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            p3[i][j] = p2[i][j];
}
/**/
bool kiemtra()
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            if(p1[i][j] != p3[i][j])
                return false;
    return true;
}
/**/
void reflection()
{
    int i,j;
    for(i=n;i>=0;i--)
        for(j=0;j<=n;j++)
            p3[n-i][j] = p2[i][j];
}
/**/
void solve()
{
    int i;
    bool trans,reflec;
    
    reflec = false;
    trans = false;
    
    khoitao();
    for(i=0;i<4;i++)
    {
        if(i)
        {
            rotation(); // rotated 90 -> 180 -> 270 
            copyp();    // copy pattern2 to pattern 3
        }
        if(kiemtra())
        {
            trans = true;
            break;
        }
    }
    
    
    if(!trans)
        for(i=0;i<4;i++)
        {
            rotation(); // rotated 0 -> 90 -> 180 -> 270 
            copyp();    // copy pattern2 to pattern 3
            
            reflection();   // replection vertical
            
            if(kiemtra())
                reflec = true;
                
            if(reflec)
                break;
        }
        
    if(i == 0 && (trans || reflec))
    {
        if(trans)
            printf("was preserved.");
        else
            printf("was reflected vertically.");
    }
    else if(i == 1 && (trans || reflec))
    {
        if(trans)
            printf("was rotated 90 degrees.");
        else
            printf("was reflected vertically and rotated 90 degrees.");
    }
    else if(i == 2 && (trans || reflec))
    {
        if(trans)
            printf("was rotated 180 degrees.");
        else
            printf("was reflected vertically and rotated 180 degrees.");
    }
    else if(i == 3 && (trans || reflec))
    {
        if(trans)
            printf("was rotated 270 degrees.");
        else
            printf("was reflected vertically and rotated 270 degrees.");
    }
    else
        printf("was improperly transformed.");
    printf("\n");
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%s %s",&p1[i],&p2[i]);
        n--;
        printf("Pattern %d ",id++);
        solve();
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

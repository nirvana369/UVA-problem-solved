/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "736.inp"
#define fo "736.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
char a[60][60];
int n;
/**/
bool chk(int hang,int cot,int dir,char s[])
{
    int i;
    i = 0;
    while(s[i])
    {
        if(!(hang >=0 && hang < n && cot >= 0 && cot < n))
            return false;
        if(a[hang][cot] == ' ')
            i--;
        else if(a[hang][cot] != s[i])
            return false;
        i++;
        hang += h[dir].x;
        cot += h[dir].y;
    }
    return true;
}
/**/
void getdir(int dir)
{
    if(dir == 0)
        printf("N");
    else if(dir == 1)
        printf("NE");
    else if(dir == 2)
        printf("E");
    else if(dir == 3)
        printf("SE");
    else if(dir == 4)
        printf("S");
    else if(dir == 5)
        printf("SW");
    else if(dir == 6)
        printf("W");
    else if(dir == 7)
        printf("NW");
}
/**/
void solve(char s[])
{
    int i,j,k;
    bool found;
    
    found = false;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[0] == a[i][j])
                for(k=0;k<8;k++)
                    if(chk(i,j,k,s))
                    {
                        found = true;
                        printf("\n(%d,%d) - ",i+1,j+1);
                        getdir(k);
                    }
    if(!found)
        printf("\nnot found");
    printf("\n");
}
/**/
void input()
{
    int i;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        gets(a[0]);
        for(i=0;i<n;i++)
            gets(a[i]);
        while(true)
        {
            a[n][0] = 0;
            gets(a[n]);
            if(!a[n][0])
                break;
            printf("\n%s",a[n]);
            solve(a[n]);        
        }
        if(ntest)
            printf("\n");
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

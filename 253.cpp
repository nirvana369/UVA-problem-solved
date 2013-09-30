/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "253.inp"
#define fo "253.out"
/**/
using namespace std;
/**/
char cube[20];
/**/
void flipx()
{
    char temp;
    temp = cube[0];
    cube[0] = cube[1];
    cube[1] = cube[5];
    cube[5] = cube[4];
    cube[4] = temp;
}
/**/
void flipy()
{
    char temp;
    temp = cube[1];
    cube[1] = cube[2];
    cube[2] = cube[4];
    cube[4] = cube[3];
    cube[3] = temp;
}
/**/
void flipz()
{
    char temp;
    temp = cube[0];
    cube[0] = cube[2];
    cube[2] = cube[5];
    cube[5] = cube[3];
    cube[3] = temp;
}
/**/
bool kiemtra()
{
    int i;
    for(i=0;i<6;i++)
        if(cube[i] != cube[i+6])
            return false;
    return true;
}
/**/
void solve()
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        flipx();
        for(j=0;j<4;j++)
        {
            flipy();
            for(k=0;k<4;k++)
            {
                flipz();
                if(kiemtra())
                {
                    printf("TRUE\n");
                    return;
                }
            }
        }
    }
    printf("FALSE\n");
}
/**/
void input()
{
    while(!feof(stdin))
    {
        gets(cube);
        if(feof(stdin))
            break;
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

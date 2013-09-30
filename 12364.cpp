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
#include <vector>

#define fi "12364.inp"
#define fo "12364.out"
/**/
using namespace std;
/**/
int bin[11][4],a[100][100];
char str[5][5];
int n;
map <string, int> maps;
/**/
void _init()
{
    bin[1][1] = 2;                      bin[6][1] = 3;
    bin[1][2] = 0;                      bin[6][2] = 2;
    bin[1][3] = 0;                      bin[6][3] = 0;
    
    bin[2][1] = 2;                      bin[7][1] = 3;
    bin[2][2] = 2;                      bin[7][2] = 3;
    bin[2][3] = 0;                      bin[7][3] = 0;
    
    bin[3][1] = 3;                      bin[8][1] = 2;
    bin[3][2] = 0;                      bin[8][2] = 3;
    bin[3][3] = 0;                      bin[8][3] = 0;
    
    bin[4][1] = 3;                      bin[9][1] = 1;
    bin[4][2] = 1;                      bin[9][2] = 2;
    bin[4][3] = 0;                      bin[9][3] = 0;
        
    bin[5][1] = 2;                      bin[0][1] = 1;
    bin[5][2] = 1;                      bin[0][2] = 3;
    bin[5][3] = 0;                      bin[0][3] = 0;
    
    maps.clear();
    maps["**"] = 3;
    maps["*."] = 2;
    maps[".*"] = 1;
    maps[".."] = 0;
    
    strcpy(str[0],"..");
    strcpy(str[1],".*");
    strcpy(str[2],"*.");
    strcpy(str[3],"**");
}
/**/
void outs(char s[])
{
    int i,j;
    for(j=1;j<4;j++)
    {
        for(i=0;s[i];i++)
        {
            if(i)
                printf(" ");
            printf("%s",str[bin[s[i]-48][j]]);
        }
        printf("\n");
    }
}
/**/
void solve(int id,char s[])
{
    int i,j;
    char temp[4];
    j = 0;
    for(i=0;s[i];i++)
        if(s[i] != ' ')
        {
            temp[0] = s[i];
            temp[1] = s[i+1];
            temp[2] = 0;
            a[id][j++] = maps[temp];
            i++;
        }
}
/**/
int matchnum(int id)
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=1;j<4;j++)
            if(bin[i][j] != a[j][id])
                break;
        if(j == 4)
            return i;
    }
}
/**/
void outb()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d",matchnum(i));
    printf("\n");
}
/**/
void input()
{
    char s[1000];
    int i;
    _init();
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        gets(s);
        gets(s);
        if(s[0] == 'S')
        {
            gets(s);
            outs(s);
        }
        else
        {
            for(i=1;i<4;i++)
            {
                gets(s);
                solve(i,s);
            }
            outb();
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

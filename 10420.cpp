/*
                                                Hoang Linh
                                                
                                Problem: LIST OF CONQUESTS - 10420 (10420.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10420.inp"
#define fo "10420.out"
/**/
using namespace std;
/**/
char name[1000];
char country[2100][100];
int dem[2100];
int maxname;
/**/
void kiemtra()
{
    int i;
    for(i=0;i<maxname;i++)
        if(strcmp(name,country[i]) == 0)
        {
            dem[i]++;
            return;
        }
    strcpy(country[maxname],name);
    dem[maxname] = 1;
    maxname++;
}
/**/
void swaptp(int id1,int id2)
{
    char temp[1000];
    int tempgt;
    
    strcpy(temp,country[id1]);
    strcpy(country[id1],country[id2]);
    strcpy(country[id2],temp);
    
    tempgt = dem[id1];
    dem[id1] = dem[id2];
    dem[id2] = tempgt;
}
/**/
void sapxep()
{
    int i,j;
    
    for(i=0;i<maxname-1;i++)
    {
        for(j=i+1;j<maxname;j++)
            if(strcmp(country[i],country[j]) > 0)
                swaptp(i,j);
        printf("%s %d\n",country[i],dem[i]);
    }
    printf("%s %d\n",country[maxname-1],dem[maxname-1]);
}
/**/
void input()
{
    int itest;
    char temp[1000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    maxname = 0;
    for(itest=0;itest<ntest;itest++)
    {
        gets(temp);
        sscanf(temp,"%s",&name);
        kiemtra();
    }
    sapxep();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

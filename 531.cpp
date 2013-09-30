/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "531.inp"
#define fo "531.out"
/**/
using namespace std;
/**/
char kq[110][100],a[110][100],b[110][100];
int da,db,id;
int l[110][110];
/**/
void xuly(char s[])
{
    int i,j;
    char tmp[100];
    int l;
    
    l = strlen(s);
    if(l == 1 && s[0] == '#')
    {
        id++;
        return;
    }
    s[l] = ' ';
    i = j = 0;
    while(i <= l)
    {
        if(s[i] != ' ')
            tmp[j++] = s[i];
        else if(j)
        {
            tmp[j] = 0;
            j = 0;
            if(!id)
                strcpy(a[da++],tmp);
            else
                strcpy(b[db++],tmp);
        }
        i++;
    }
}
/**/
void solve()
{
    int i,j,k;
    
    if(da == 1 || db == 1)
        return;
        
    for(i=0;i<da;i++)
        for(j=0;j<db;j++)
            l[i][j] = 0;
            
    for(i=1;i<da;i++)
        for(j=1;j<db;j++)
            if(!strcmp(a[i],b[j]))
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
    i = da - 1;
    j = db - 1;
    k = 0;
    while(l[i][j])
    {
        if(l[i][j] == l[i-1][j])
            i--;
        else if(l[i][j] == l[i][j-1])
            j--;
        else
        {
            strcpy(kq[k++],a[i]);
            i--;
            j--;            
        }
    }

    for(i=k-1;i>=0;i--)
        if(i)
            printf("%s ",kq[i]);
        else
            printf("%s",kq[i]);
    printf("\n");
}
/**/
void input()
{
    char s[10000];
    id = 0;
    da = db = 1;
    while(!feof(stdin))
    {
        gets(s);
        xuly(s);
        if(id == 2)
        {
            solve();
            id = 0;
            da = db = 1;
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

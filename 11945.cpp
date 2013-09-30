/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11945.inp"
#define fo "11945.out"
/**/
using namespace std;
/**/
char s[1000];
/**/
void output()
{
    int i,j,dem;
    bool comas;
    char tmp[1000];

    i = strlen(s)-1;
    j = 0;
    comas = false;
    while(i >= 0)
    {
        tmp[j++] = s[i];
        if(s[i] == '.')
        {
            dem = 0;
            comas = true;
        }
        else if(comas)
        {
            dem++;
            if(dem == 3 && i != 0)
            {
                tmp[j++] = ',';
                dem = 0;
            }
        }
        i--;
    }
    for(i=j-1;i>=0;i--)
        printf("%c",tmp[i]);
    printf("\n");
}
/**/
void input()
{
    int ntest,id;
    double tong,tmp;
    int i,j;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        tong = 0;
        for(i=0;i<12;i++)
        {
            scanf("%lf",&tmp);         
            tong += tmp;
        }
        tong /= 12;
        printf("%d $",id++);
        sprintf(s,"%.2lf",tong);
        output();
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

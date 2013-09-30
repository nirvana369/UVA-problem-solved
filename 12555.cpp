/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12555.inp"
#define fo "12555.out"
/**/
using namespace std;
/**/
int a[3];
/**/
void xuly(char s[])
{
    int dem;
    int i,id;
    char tmp[10];
    
    i = dem = 0;
    a[0] = 0;
    a[1] = 0;
    id = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            sscanf(tmp,"%d",&a[id++]);
            dem = 0;
        }
        i++;
    }
}
/**/
void solve(int id)
{
    int i;
    int l,tmp;
    float val;
    
    val = 0.5 * a[0] + 0.05 * a[1] + 1e-7;
    
    printf("Case %d: ",id);
    tmp = (int)val;
    val -= tmp;
    printf("%d",tmp);
    if((int)(val*10) != 0)
        printf(".");
    do
    {
        val *= 10;
        tmp = (int)val;
        if(tmp)
            printf("%d",tmp);
        val -= tmp;
    }while(tmp != 0);
    printf("\n");
}
/**/
void input()
{
    char s[100];
    int ntest,id;
    scanf("%d",&ntest);
    gets(s);
    id = 1;
    while(ntest--)
    {
        gets(s);
        xuly(s);
        solve(id++);
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

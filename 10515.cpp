/*
                                                    Hoang Linh
                                                    
                                        Problem: POWERS ET AL. - 10515 (10515.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10515.inp"
#define fo "10515.out"
/**/
using namespace std;
/**/
int d[10] = {1,1,4,4,2,1,1,4,4,2};
int last[11][6];
char n[110],m[110];
int lm,ln;
/**/
void khoitao()
{
    int i,j;
    int value;
    for(i=0;i<10;i++)
    {
        value = 1;
        for(j=1;j<=d[i];j++)
        {
            value *= i;
            last[i][j] = value % 10;
        }
    }
}
/**/
void solve()
{
    int i,id;
    int value;
    id = n[ln-1] - 48;
    value = 0;
    for(i=0;i<lm;i++)
    {
        value *= 10;
        value += m[i] - 48;
        value %= d[id];
    }
    if(value == 0)
        value = d[id];
    printf("%d\n",last[id][value]);
}
/**/
void input()
{
    khoitao();
    while(true)
    {
        scanf("%s %s",&n,&m);
        ln = strlen(n);
        lm = strlen(m);
        if(ln == 1 && lm == 1 && n[0] == '0' && m[0] == '0')
            break;
        if(lm == 1 && m[0] == '0')
            printf("1\n");
        else
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

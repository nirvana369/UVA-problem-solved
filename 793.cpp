/*
                                                                    Hoang Linh
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "793.inp"
#define fo "793.out"

/**/
using namespace std;
/**/
int truoc[40000];
int n;
/**/
int laygoc(int value)
{
    while(value != truoc[value])
        value = truoc[value];
    return value;
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
        truoc[i] = i;
}
/**/
void input()
{
    char temp[1000];
    int ntest;
    char lenh;
    int connect,disconnect,x,y;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        gets(temp);
        khoitao();
        connect = disconnect = 0;
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            sscanf(temp,"%c %d %d",&lenh,&x,&y);
            if(lenh == 'c')
                truoc[laygoc(x)] = laygoc(y);
            else
                if(laygoc(x) == laygoc(y))
                    connect++;
                else
                    disconnect++;
        }
        printf("%d,%d\n",connect,disconnect);
        if(ntest != 0)
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

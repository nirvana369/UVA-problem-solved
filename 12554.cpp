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

#define fi "12554.inp"
#define fo "12554.out"
/**/
using namespace std;
/**/
bool d[110];
char sing[20][10],name[110][1000];
int n;
/**/
void _init()
{
    int i;
    
    strcpy(sing[0],"Happy");    
    strcpy(sing[1],"birthday");
    strcpy(sing[2],"to");
    strcpy(sing[3],"you");
    strcpy(sing[4],"Happy");
    strcpy(sing[5],"birthday");
    strcpy(sing[6],"to");
    strcpy(sing[7],"you");
    strcpy(sing[8],"Happy");
    strcpy(sing[9],"birthday");
    strcpy(sing[10],"to");
    strcpy(sing[11],"Rujia");
    strcpy(sing[12],"Happy");
    strcpy(sing[13],"birthday");
    strcpy(sing[14],"to");
    strcpy(sing[15],"you");
    
    for(i=0;i<n;i++)
        d[i] = true;
}
/**/
void input()
{
    int i,j,dem;
    
    scanf("%d",&n);
    _init();
    
    for(i=0;i<n;i++)
        scanf("%s",&name[i]);
    dem = 0;
    j = i = 0;
    while(!(dem == n && i == 16))
    {
        if(i == 16)
            i = 0;
        if(j == n)
            j = 0;
        printf("%s: %s\n",name[j],sing[i]);
        if(d[j])
        {
            d[j] = false;
            dem++;
        }
        i++;
        j++;
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

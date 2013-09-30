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

#define fi "12230.inp"
#define fo "12230.out"
/**/
using namespace std;
/**/
struct rv{
            int leng,bank,speed;
         };
rv r[12];
int nsong,dodai;
void sapxep()
{
    int i,j;
    rv temp;
    for(i=0;i<nsong-1;i++)
        for(j=i+1;j<nsong;j++)
            if(r[i].bank > r[j].bank)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
}
/**/
void solve()
{
    int i;
    float timec;
    int xp;
    
    timec = 0;
    xp = 0;
    for(i=0;i<nsong;i++)
    {
        timec += (r[i].bank - xp);
        xp = r[i].bank + r[i].leng;
        timec += (float)r[i].leng/r[i].speed * 2;
    }
    timec += (float)dodai - xp;
    printf("%0.3f\n\n",timec);
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        scanf("%d %d",&nsong,&dodai);
        if(!nsong && !dodai)
            break;
        for(i=0;i<nsong;i++)
            scanf("%d %d %d",&r[i].bank,&r[i].leng,&r[i].speed);
        sapxep();
        printf("Case %d: ",id++);
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

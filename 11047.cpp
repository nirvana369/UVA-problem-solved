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

#define fi "11047.inp"
#define fo "11047.out"
#define inf 32767
/**/
using namespace std;
/**/
map<string, int > nmap;
map<int, string> mmap;
int a[110][110],tr[110][110];
int n;
/**/
void solve()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    tr[i][j] = tr[i][k];
                }
}
/**/
void outroad(int x,int y)
{
    while(x != y)
    {
        cout << " " << mmap[x];
        x = tr[x][y];
    }
}
/**/
void input()
{
    char s[50],s1[50],s2[50];
    int id1,id2;
    int i,j;
    int ntest,m;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        mmap.clear();
        nmap.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%s",&s);
            mmap[i] = s;
            nmap[s] = i;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j] == -1)
                    a[i][j] = inf;
                tr[i][j] = j;
            }
        solve();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s %s %s",&s,&s1,&s2);       
            id1 = nmap[s1];
            id2 = nmap[s2];
            if(a[id1][id2] == inf)// || !timkiem(id1,id2))
                printf("Sorry Mr %s you can not go from %s to %s\n",s,s1,s2);
            else
            {
                printf("Mr %s to go from %s to %s, you will receive %d euros\n",s,s1,s2,a[id1][id2]);
                cout << "Path:" << s1;
                outroad(tr[id1][id2],id2);
                cout << " " << s2 << endl;
            }
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

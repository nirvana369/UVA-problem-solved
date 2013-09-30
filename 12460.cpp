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

#define fi "12460.inp"
#define fo "12460.out"
#define maxa 20000
/**/
using namespace std;
/**/
char a[maxa+10][30];
int d[maxa+10],truoc[maxa+10],q[maxa+10];
map <string, int> mmap;
int da;

/**/
int fpre(int id)
{
    while(id != truoc[id])
        id = truoc[id];
    return id;
}
/**/
void loang(int id)
{
    int dau,cuoi;
    int i,j;
    char kt;
            
    dau = -1;
    cuoi = 0;
    q[0] = id;
    d[id] = 1;
    while(dau != cuoi)
    {
        dau++;
        i = 0;
        while(a[q[dau]][i] != 0)
        {
            kt = a[q[dau]][i];
            for(j='a';j<='z';j++)
            {
                a[q[dau]][i] = j;
                if(mmap[a[q[dau]]] != 0 && !d[mmap[a[q[dau]]]])
                {
                    cuoi++;
                    d[mmap[a[q[dau]]]] = 1;
                    truoc[mmap[a[q[dau]]]] = fpre(q[dau]);
                    q[cuoi] = mmap[a[q[dau]]];
                }
            }
            a[q[dau]][i] = kt;
            i++;
        }
    }
}
/**/
void solve()
{
    int i;
    
    for(i=1;i<da;i++)
        if(truoc[i] == i)
            loang(i);
}
/**/
void input()
{
    char s1[100],s2[100];
    bool nochange;
    da = 1;
    mmap.clear();
    while(true)
    {
        scanf("%s",&a[da]);
        if(a[da][0] == '-' && a[da][1] == '-')
            break;
        mmap[a[da]] = da;
        d[da] = 0;
        truoc[da] = da;
        da++;
    }
    solve();
    
    while(scanf("%s %s",&s1,&s2) == 2)
    {
        nochange = false;
        if(mmap[s1] == 0 || mmap[s2] == 0)
            nochange = true;
        else
            if(fpre(mmap[s1]) != fpre(mmap[s2]))
                nochange = true;
        if(nochange)
            printf("No\n");
        else
            printf("Yes\n");
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

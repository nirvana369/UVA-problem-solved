/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>

#define fi "10150.inp"
#define fo "10150.out"
/**/
using namespace std;
/**/
bool d[25100];
int q[25100],trc[25100],len[25100];
map<string, int > mmap;
vector<int > dic[25100];
char a[25100][20];
int da,xp,kt;
bool solution;
/**/
void xuly(char s[])
{
    int i,j;
    int dem;
    
    mmap[s] = da;
    len[da] = strlen(s);
    
    for(i=da-1;i>=1;i--)
        if(len[da] == len[i])
        {
            dem = 0;
            for(j=0;j<len[da];j++)
            {
                if(a[i][j] != s[j])
                    dem++;
                if(dem > 1)
                    break;
            }
            if(dem == 1)
            {
                dic[da].push_back(i);
                dic[i].push_back(da);
            }
        }
    da++;
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<da;i++)
        d[i] = true;
}
/**/
bool loang()
{
    int dau,cuoi;
    int i;
    int tmp;
    
    khoitao();
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    d[xp] = false;
    
    while(dau != cuoi)
    {
        dau++;
        tmp = q[dau];
        for(i=0;i<dic[tmp].size();i++)
            if(d[dic[tmp][i]])
            {
                cuoi++;
                q[cuoi] = dic[tmp][i];
                trc[dic[tmp][i]] = tmp;
                d[dic[tmp][i]] = false;
                if(dic[tmp][i] == kt)
                    return true;
            }
    }
    return false;
}
/**/
void output()
{
    int i;
    int kq[25100];
    
    if(solution)
    {
        i = 0;
        while(kt != xp)
        {
            kq[i++] = kt;
            kt = trc[kt];
        }
        kq[i++] = xp;
        while(i--)
            printf("%s\n",a[kq[i]]);
    }
    else
        printf("No solution.\n");
}
/**/
void input()
{
    int id;
    char s1[20],s2[20];
    
    da = 1;
    mmap.clear();
    while(true)
    {
        dic[da].clear();
        a[da][0] = 0;
        gets(a[da]);
        if(!a[da][0])
            break;
        xuly(a[da]);
    }
    id = 0;
    while(scanf("%s %s",&s1,&s2) == 2)
    {
        xp = mmap[s1];
        kt = mmap[s2];
        if(!xp || !kt)
            solution = false;
        else
        {
            if(kt != xp)
                solution = loang();
            else
                solution = true;
        }
        if(id)
            printf("\n");
        output();
        id++;
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

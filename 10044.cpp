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

#define fi "10044.inp"
#define fo "10044.out"
/**/
using namespace std;
/**/
map<string, long> mmap;
long idn,xp;
int a[6010][6010],q[6010],d[6010],kc[6010];
vector<int> luu;
int m,n;
/**/
void xuly(char s[])
{
    char temp[10000];
    int i,j,k;
    bool thoat;
    int dem,l;
    
    luu.clear();
    dem = 0;
    l = strlen(s);
    thoat = false;
    k = 0;
    
    for(i=0;i<l;i++)
    {
        if(s[i] == ',' || s[i] == ':')
        {
            k++;
            
            if(s[i] == ':')
                thoat = true;
            if(k == 2)
            {
                temp[dem] = 0;
                if(mmap[temp] == 0)
                {
                    mmap[temp] = idn;
                    luu.push_back(idn);
                    idn++;
                }
                else
                    luu.push_back(mmap[temp]);
                dem = k = 0;
                i++;
            }
            else
                temp[dem++] = s[i];
        }
        else
            temp[dem++] = s[i];
            
        if(thoat)
            break;
    }
    
    for(i=0;i<luu.size()-1;i++)
        for(j=i+1;j<luu.size();j++)
            a[luu[i]][luu[j]] = a[luu[j]][luu[i]] = 1;
}
/**/
void loang()
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = mmap["Erdos, P."];
    kc[q[0]] = 0;
    d[q[0]] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<idn;i++)
            if(!d[i] && a[q[dau]][i])
            {
                cuoi++;
                kc[i] = kc[q[dau]] + 1;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
}
/**/
void khoitao()
{
    int i,j;
    
    idn = 1;
    mmap.clear();
    
    for(i=0;i<5100;i++)
    {
        for(j=0;j<5100;j++)
            a[i][j] = 0;
        d[i] = 0;
        kc[i] = -1;
    }
}
/**/
void input()
{
    char s[100000];
    int i;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        gets(s);
        
        khoitao();
        for(i=0;i<n;i++)
        {
            gets(s);
            xuly(s);
        }
        loang();
        printf("Scenario %d\n",id++);
        for(i=0;i<m;i++)
        {
            gets(s);
            printf("%s ",s);
            if(mmap[s] == 0 || kc[mmap[s]] == -1)
                printf("infinity\n");
            else
                printf("%d\n",kc[mmap[s]]);
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "1449.inp"
#define fo "1449.out"
/**/
using namespace std;
/**/
vector<int > vt[30];
int d[30],len[155],freq[155];
char s[1000010],a[155][100];
int n;
/**/
void solve()
{
    long i,j;
    int maxf,tmp,id;
    int dau1,cuoi1,dau2,cuoi2;
    
    i = 0;
    maxf = 0;
    while(s[i])
    {
        if(d[s[i]-97])
        {
            tmp = s[i]-97;
            for(j=0;j<vt[tmp].size();j++)
            {
                id = vt[tmp][j];
                dau1 = i;
                cuoi1 = i + len[id] - 1;
                dau2 = 0;
                cuoi2 = len[id] - 1;
                while(dau2 <= cuoi2)
                {
                    if(s[dau1] != a[id][dau2])
                        break;
                    if(s[cuoi1] != a[id][cuoi2])
                        break;
                    dau1++;
                    dau2++;
                    cuoi1--;
                    cuoi2--;
                }
                if(dau2 > cuoi2)
                {
                    freq[id]++;
                    if(freq[id] > maxf)
                        maxf = freq[id];
                }
            }
        }
        i++;
    }
    
    printf("%d\n",maxf);
    for(i=0;i<n;i++)
        if(freq[i] == maxf)
            printf("%s\n",a[i]);
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=26;i++)
    {
        d[i] = 0;
        vt[i].clear();
    }
}
/**/
void input()
{
    int i;
    int tmp;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            len[i] = strlen(a[i]);
            
            freq[i] = 0;
            tmp = a[i][0] - 97;     
            d[tmp] = 1;
            vt[tmp].push_back(i);
        }
        scanf("%s",&s);
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

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10665.inp"
#define fo "10665.out"
/**/
using namespace std;
/**/
map <char, int> mmap;
char wk[30],kq[30];
int nwk;
/**/
bool kiemtra(char x,char y,int flag)
{
    if(flag == 0)
        if(mmap[x] < mmap[y])
            return true;
    if(flag == 1)
        if(mmap[x] > mmap[y])
            return true;
    return false;
}
/**/
void sapxep(char kt[],int dau,int cuoi,int flag)
{
    int i,j;
    char temp;
    for(i=dau;i<cuoi-1;i++)
        for(j=i+1;j<cuoi;j++)
            if(kiemtra(kt[i],kt[j],flag))
            {
                temp = kt[i];
                kt[i] = kt[j];
                kt[j] = temp;
            }
            else if(mmap[kt[i]] == mmap[kt[j]])
                if(kt[i] > kt[j])
                {
                    temp = kt[i];
                    kt[i] = kt[j];
                    kt[j] = temp;
                }
}
/**/
void solve()
{
    int i,j,k;
    char temp;
    i = j = 0;
    k = nwk - 1;
    while(j < k)
    {
        if(wk[i] < wk[i+1])
        {
            kq[j] = wk[i];
            kq[k] = wk[i+1];
        }
        else
        {
            kq[j] = wk[i+1];
            kq[k] = wk[i];
        }
        j++;
        k--;
        i += 2;
    }
    if(j == k)
        kq[j] = wk[i];
        
    for(i=0;i<=k;i++)
        for(j=nwk-i-1;j<nwk;j++)
            if(mmap[kq[i]] == mmap[kq[j]] && kq[i] > kq[j])
            {
                temp = kq[i];
                kq[i] = kq[j];
                kq[j] = temp;
            }
            else if(mmap[kq[i]] > mmap[kq[j]])
                break;
    sapxep(kq,0,k,0);
    sapxep(kq,k,nwk,1);
    for(i=0;i<nwk;i++)
        printf("%c ",kq[i]);
    printf("\n");
    for(i=0;i<nwk;i++)
        cout << mmap[kq[i]] << " ";
    printf("\n");
}
/**/
void khoitao()
{
    int i;
    for(i='A';i<='Z';i++)
        mmap[i] = 0;
}
/**/
void input()
{
    int i,j;
    int l;
    char temp[10000];
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&nwk);
        khoitao();
        gets(temp);
        gets(temp);
        l = strlen(temp);
        i = j = 0;
        while(i < l)
        {
            if(temp[i] == '#')
                break;
            if(mmap[temp[i]] == 0)
            {
                wk[j++] = temp[i];
                mmap[temp[i]]++;
            }
            else
                mmap[temp[i]]++;
            i++;
        }
        i = 'A';
        while(j < nwk)
        {
            if(mmap[i] == 0)
                wk[j++] = i;
            i++;
        }
        sapxep(wk,0,nwk,0);
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

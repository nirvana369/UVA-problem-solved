/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>

#define fi "755.inp"
#define fo "755.out"
/**/
using namespace std;
/**/
long value[100111];
long ntele,nkq;
bool tontai;
priority_queue <long, vector <long>, greater <long> > pq;
map <long, int> mmap;
map <char, int> kmap;
/**/
void mahoa()
{
    kmap['A'] = 2;
    kmap['B'] = 2;
    kmap['C'] = 2;
    kmap['D'] = 3;
    kmap['E'] = 3;
    kmap['F'] = 3;
    kmap['G'] = 4;
    kmap['H'] = 4;
    kmap['I'] = 4;
    kmap['J'] = 5;
    kmap['K'] = 5;
    kmap['L'] = 5;
    kmap['M'] = 6;
    kmap['N'] = 6;
    kmap['O'] = 6;
    kmap['P'] = 7;
    kmap['R'] = 7;
    kmap['S'] = 7;
    kmap['T'] = 8;
    kmap['U'] = 8;
    kmap['V'] = 8;
    kmap['W'] = 9;
    kmap['X'] = 9;
    kmap['Y'] = 9;
}
/**/
void output(long val)
{
    int i,j;
    char s[10],temp[10];
    sprintf(s,"%ld",val);
    if(strlen(s) != 7)
    {
        for(i=strlen(s)-1,j=6;i>=0;i--,j--)
            temp[j] = s[i];
        while(j >= 0)
        {
            temp[j] = '0';
            j--;
        }
        temp[7] = 0;
        strcpy(s,temp);
    }
    for(i=0;i<3;i++)
        printf("%c",s[i]);
    printf("-");
    for(i=3;i<7;i++)
        printf("%c",s[i]);
}
/**/
void solve()
{
    long val;
    if(tontai)
    {
        while(!pq.empty())
        {
            val = pq.top();
            if(mmap[val] > 1)
            {
                output(val);
                cout << " " << mmap[val] << endl;
            }
            mmap[val] = 0;
            pq.pop();
        }
    }
    else
        printf("No duplicates.\n");
}
/**/
void xuly(int id,char s[])
{
    int i;
    int l;
    l = strlen(s);
    value[id] = 0;
    for(i=0;i<l;i++)
    {
        if(s[i] >= '0' && s[i] <='9')
            value[id] = value[id] * 10 + (s[i] - 48);
        else if(s[i] >= 'A' && s[i] <= 'Z')
            value[id] = value[id] * 10 + kmap[s[i]];
    }
    pq.push(value[id]);
    mmap[value[id]]++;
    if(mmap[value[id]] > 1)
        tontai = true;
}
/**/
void input()
{
    int itest;
    int ntest;
    char temp[1000];
    long i;
    mahoa();
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%ld",&ntele);
        mmap.clear();
        while(!pq.empty())
            pq.pop();
        tontai = false;
        gets(temp);
        for(i=1;i<=ntele;i++)
        {
            gets(temp);
            xuly(i,temp);
        }
        solve();
        if(itest != ntest-1)
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

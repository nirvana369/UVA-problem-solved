/*
                                                    Hoang Linh
                                                
                                        Problem: ANAGRAMS 2.0  - 156 (anagram2.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "156.inp"
#define fo "156.out"
/**/
using namespace std;
/**/
struct ana{
                int len;
                char s1[500];
                char s2[500];
          };
ana data[1100],kq[1100];
int d[1100];
int maxdata;
/**/
void sapxep(char s[],int maxs)
{
    int i,j;
    char temp;
    
    for(i=0;i<maxs-1;i++)
        for(j=i+1;j<maxs;j++)
            if(s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}
/**/
void xuly(char s[])
{
    int i;
    int l,dem;
    char temp[1000],temp1[1000];
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    for(i=0;i<=l;i++)
    {
        if(s[i] == ' ' && dem > 0)
        {
            temp[dem] = 0;
            temp1[dem] = 0;
            strcpy(data[maxdata].s1,temp);
            sapxep(temp1,dem);
            strcpy(data[maxdata].s2,temp1);
            data[maxdata].len = dem;
            d[maxdata] = 0;
            maxdata++;
            dem = 0;
        }
        if(s[i] != ' ')
        {
            temp[dem] = s[i];
            temp1[dem] = s[i];
            if(temp1[dem] >= 'A' && temp1[dem] <= 'Z')
                temp1[dem] = temp1[dem] + 32;
            dem++;
        }
    }
}
/**/
bool sosanh(int id1,int id2)
{
    int i;
    int minl;
    if(kq[id1].len < kq[id2].len)
        minl = kq[id1].len;
    else
        minl = kq[id2].len;
    for(i=0;i<minl;i++)
    {
        if(kq[id1].s1[i] > kq[id2].s1[i])
            return true;
        if(kq[id1].s1[i] < kq[id2].s1[i])
            return false;
    }
    return false;
}
/**/
void solve()
{
    int i,j;
    int dem;
    bool nota;
    ana temp;
    
    dem = 0;
    for(i=0;i<maxdata-1;i++)
    {
        nota = false;
        if(d[i] == 0)
            for(j=i+1;j<maxdata;j++)
            {
                if(strcmp(data[i].s2,data[j].s2) == 0)
                {
                    d[j] = 1;
                    nota = true;
                }
            }
        if(nota)
            d[i] = 1;
        else if(d[i] == 0)
        {
            kq[dem] = data[i];
            dem++;
        }
    }
    if(d[maxdata-1] == 0)
    {
        kq[dem] = data[maxdata-1];
        dem++;
    }
        
    for(i=0;i<dem-1;i++)
    {
        for(j=i+1;j<dem;j++)
            if(strcmp(kq[i].s1,kq[j].s1) > 0)
            {
                temp = kq[i];
                kq[i] = kq[j];
                kq[j] = temp;
            }
    }
    
    for(i=0;i<dem;i++)
        printf("%s\n",kq[i].s1);
}
/**/
void input()
{
    char temp[10000];
    maxdata = 0;
    while(true)
    {
        gets(temp);
        if(temp[0] == '#')
        {
            solve();
            break;
        }
        xuly(temp);
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

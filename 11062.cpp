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

#define fi "11062.inp"
#define fo "11062.out"
/**/
using namespace std;
/**/
char s[100000],temp[1000];
priority_queue <string, vector <string>, greater <string> > pq;
map <string, int> mmap;
int dem;
/**/
void solve()
{
    int i;
    int l;
    
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '-')
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            temp[dem++] = s[i];
        }
        else
        {
            temp[dem] = 0;
            if(dem != 0)
            {
                if(mmap[temp] == 0)
                {
                    mmap[temp] = 1;
                    pq.push(temp);
                }
            }
            dem = 0;
        }
    }
    
    if(dem != 0)
    {
        if(temp[dem-1] != '-')
        {
            temp[dem] = 0;
            if(mmap[temp] == 0)
            {
                mmap[temp] = 1;
                pq.push(temp);
            }
            dem = 0;
        }
        else
            dem--;
    }
}
/**/
void output()
{
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
/**/
void input()
{
    while(!pq.empty())
        pq.pop();
    mmap.clear();
    dem = 0;
    while(!feof(stdin))
    {
        gets(s);
        if(feof(stdin))
            break;
        solve();
    }
    output();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

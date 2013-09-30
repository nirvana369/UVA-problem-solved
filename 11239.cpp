/*
                                                                Hoang Linh
                                                                
*/
// map + priority_queue

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "11239.inp"
#define fo "11239.out"
/**/
using namespace std;
/**/
struct lib{
                char name[1000];
                int val;
            };

class cmpmap
{
public:
    bool operator()(lib &l1,lib &l2)
    {
        if(l1.val < l2.val)
            return true;
        else if(l1.val == l2.val)
            if(strcmp(l1.name,l2.name) > 0)
                return true;
        return false;
    }
};

lib proj[110];
int dp;

map <string, string> mmap;
map <string,int> pmap;
priority_queue <lib, vector <lib>, cmpmap > pq;
/**/
/**/
void solve()
{
    int i;
    lib temp;
    for(i=1;i<=dp;i++)
    {
        proj[i].val = pmap[proj[i].name];
        pq.push(proj[i]);
    }
    
    while(!pq.empty())
    {
        temp = pq.top();
        printf("%s %d\n",temp.name,temp.val);
        pq.pop();
    }
}
/**/
void input()
{
    char s[1000];
    while(true)
    {
        mmap.clear();
        pmap.clear();
        dp = 0;
        while(true)
        {
            gets(s);
            if(s[0] == '1')
                break;
            if(s[0] == '0')
                return;
            if(s[0] >= 'A' && s[0] <= 'Z')
            {
                dp++;
                strcpy(proj[dp].name,s);
                pmap[proj[dp].name] = 0;
            }
            else
            {
                if(mmap[s] == "")
                {
                    mmap[s] = proj[dp].name;
                    pmap[proj[dp].name]++;
                }
                else if(mmap[s] != proj[dp].name || mmap[s] == s)
                {
                    pmap[mmap[s]]--;
                    mmap[s] = s;
                }
            }
        }
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

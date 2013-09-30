/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
#include <map>

#define fi "1251.inp"
#define fo "1251.out"
/**/
using namespace std;
/**/
struct sed{
                char s[1000];
                int d;
            };
char x[1000][1000],y[1000][1000],kt[15];
queue<sed > q;
map<string, int > mmap;
int n;
sed xp;
/**/
bool chk(char s1[],int id,char s2[])
{
    int i,j,j1,k;
    bool change,find;
    
    i = k = 0;
    change = find = false;
    while(s1[i])
    {
        if(s1[i] == x[id][0])
        {
            j = i;
            j1 = 0;
            while(s1[j] && x[id][j1])
            {
                if(s1[j] != x[id][j1])
                    break;
                                    
                j++;
                j1++;
            }
            if(!x[id][j1])
            {
                j1 = 0;
                while(y[id][j1])
                    s2[k++] = y[id][j1++];
                i = j-1;
                change = true;
                find = true;
            }
        }
        if(!change)
            s2[k++] = s1[i];
        else
            change = false;
        i++;
    }
    s2[k] = 0;
    if(!find)
        return false;
    if(k > 10)
        return false;
    return true;
}
/**/
int solve()
{
    long dau,cuoi;
    int i;
    sed t,tmp;
    int id;
    
    xp.d = 0;
    q.push(xp);
    
    if(strcmp(xp.s,kt) == 0)
        return 0;
    mmap[xp.s] = 1;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        for(i=0;i<n;i++)
        {
            if(chk(t.s,i,tmp.s))
            {
                tmp.d = t.d + 1;
                id = mmap[tmp.s];
                if(id == 2)
                    return tmp.d;
                else if(!id)
                {
                    mmap[tmp.s] = 1;
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}
/**/
void input()
{
    int i;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%s %s",&x[i],&y[i]);
            
        mmap.clear();
        scanf("%s %s",&xp.s,&kt);
        mmap[kt] = 2;
        
        printf("%d\n",solve());
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

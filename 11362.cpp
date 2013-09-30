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

#define fi "11362.inp"
#define fo "11362.out"
/**/
using namespace std;
/**/
priority_queue <string, vector<string>, greater <string> > pq;
string a[10010];
/**/
bool sosanh(string s1,string s2)
{
    int i;
    int len;
    if(s1.size() < s2.size())
        return false;
    len = s2.length();
    for(i=0;i<len;i++)
        if(s1[i] != s2[i])
            return false;
    return true;
}
/**/
bool kiemtra()
{
    int i;
    i = 0;
    while(!pq.empty())
    {
        a[i] = pq.top();
        pq.pop();
        if(i)
            if(sosanh(a[i],a[i-1]))
                return false;
        i++;
    }
    return true;
}
/**/
void input()
{
    int i,n;
    char s[15];
    int ntest;
    bool list;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        while(!pq.empty())
            pq.pop();
        list = true;
        for(i=0;i<n;i++)
        {
            scanf("%s",&s);
            pq.push(s);
        }
        list = kiemtra();
        if(list)
            printf("YES\n");
        else
            printf("NO\n");
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

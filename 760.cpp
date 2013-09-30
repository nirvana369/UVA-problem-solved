/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <iostream>

#define fi "760.inp"
#define fo "760.out"
/**/
using namespace std;
/**/
priority_queue<string, vector<string>, greater<string> > pq;
map<string, int > mmap;
/**/
void output()
{
    
    if(pq.empty())
        printf("No common sequence.\n");
    else
    {
        while(!pq.empty())
        {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}
/**/
void khoitao()
{
    while(!pq.empty())
        pq.pop();
    mmap.clear();
}
/**/
void input()
{
    int i,j,k,k1,k2;
    char s1[310],s2[310],tmp[310];
    int id;
    bool dif;
    id = 0;
    
    while(scanf("%s %s",&s1,&s2) == 2)
    {
        khoitao();
        for(i=0;s1[i];i++)
            for(j=0;s2[j];j++)
                if(s1[i] == s2[j])
                {
                    k = 0;
                    k1 = i;
                    k2 = j;
                    dif = false;
                    while(s1[k1] == s2[k2] && s1[k1] && s2[k2])
                    {
                        tmp[k] = s1[k1];
                        if(k && tmp[k] != tmp[0])
                            dif = true;
                        k++;
                        k1++;
                        k2++;
                    }
                    tmp[k] = 0;
                    if(k > 1 && dif && !mmap[tmp])
                    {
                        mmap[tmp] = 1;
                        pq.push(tmp);
                    }
                }
        if(id++)
            printf("\n");
        output();
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

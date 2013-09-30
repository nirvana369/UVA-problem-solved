/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10374.inp"
#define fo "10374.out"
/**/
using namespace std;
/**/
map <string, string> mmap;
map <string, int> pmap;
/**/
void input()
{
    int ntest;
    int n,m,maxvote,dem;
    char name[100],party[100];
    int i;
    scanf("%d",&ntest);
    
    map <string, int>::iterator j,temp;
    while(ntest--)
    {
        mmap.clear();
        pmap.clear();
        
        scanf("%d",&n);
        gets(name);
        
        for(i=0;i<n;i++)
        {
            gets(name);
            gets(party);
            mmap[name] = party;
            pmap[name] = 0;
        }
        
        scanf("%d",&m);
        gets(name);
        
        maxvote = 0;
        for(i=0;i<m;i++)
        {
            gets(name);
            if(mmap[name] != "")
            {
                pmap[name]++;
                if(pmap[name] > maxvote)
                    maxvote = pmap[name];
            }
        }
        
        dem = 0;
        for(j=pmap.begin();j!=pmap.end();j++)
            if(j->second == maxvote)
            {
                dem++;
                temp = j;
            }
        
        if(dem > 1)
            printf("tie\n");
        else
            cout << mmap[temp->first] << endl;

        if(ntest != 0)
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

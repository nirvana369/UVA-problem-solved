#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "12592.inp"
#define fo "12592.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    char s1[200],s2[200];
    int n,q;
    
    map <string, string> mmap;
    mmap.clear();
    scanf("%d",&n);
    gets(s1);
    for(i=0;i<n;i++)
    {
        gets(s1);
        gets(s2);
        mmap[s1] = s2;
    }
    scanf("%d",&q);
    gets(s1);
    for(i=0;i<q;i++)
    {
        gets(s1);
        cout << mmap[s1] << endl;
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

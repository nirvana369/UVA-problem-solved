/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
#include <map>

#define fi "12207.inp"
#define fo "12207.out"
#define maxval 2000000000l
/**/
using namespace std;
/**/
map<long, int > mmap;
long maxid,minid;
/**/
void chk()
{
    long val,id;
    map<long, int >::iterator i;
    
    val = maxval;
    
    for(i=mmap.begin();i!=mmap.end();i++)
        if(i -> second < val)
        {
            val = i -> second;
            id = i -> first;
        }
    mmap[id] = ++maxid;
    printf("%ld\n",id);
}
/**/
void input()
{
    int i;
    long val,tmp;
    long n;
    int qe,id;
    char s[3];
    
    id = 1;
    while(scanf("%ld %d",&n,&qe))
    {
        if(!n && !qe)
            break;
            
        printf("Case %d:\n",id++);

        mmap.clear();
        
        val = n > qe ? qe : n;
        for(i=1;i<=val;i++)
            mmap[i] = i;
        minid = 0;
        maxid = val;
        while(qe--)
        {
            scanf("%s",&s);
            if(s[0] == 'E')
            {
                scanf("%ld",&val);
                if(val <= n)
                    mmap[val] = minid--;
            }
            else
                chk();
        }
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





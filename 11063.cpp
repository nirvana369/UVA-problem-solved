/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11063.inp"
#define fo "11063.out"
/**/
using namespace std;
/**/
void input()
{
    int i,id,j;
    int n;
    int a[110];
    bool b2;
    
    map <int, int> mmap;
    map <int, int>::iterator k;
    id = 1;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        mmap.clear();
        b2 = true;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] < 1)
                b2 = false;
            if(i != 0 && a[i] <= a[i-1])
                b2 = false;
        }
        
        if(b2)
            for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                {
                    for(k=mmap.begin();k!=mmap.end();k++)
                        if(k->second == a[i]+a[j])
                        {
                            b2 = false;
                            break;
                        }
                    mmap[a[i] + a[j]] = a[i] + a[j];
                }
                if(!b2)
                    break;
            }
        printf("Case #%d: ",id);
        if(b2)
            printf("It is a B2-Sequence.\n\n");
        else
            printf("It is not a B2-Sequence.\n\n");
        id++;
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

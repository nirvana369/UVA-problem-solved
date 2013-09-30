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
//#include <map>

#define fi "10874.inp"
#define fo "10874.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    long pass,pass1;
    int n;
    int r,l,pos,pos1;
    
    while(scanf("%d",&n) && n)
    {
        pos = pos1 = 1;
        pass = pass1 = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&l,&r);
            //if(abs(l-pos) < abs(r-pos))
            //{
                pass += abs(l-pos);
                pos = r;
                
                pass1 += abs(r-pos1);
                pos1 = l;
            //}
            //else
            //{
                pass += abs(r-pos);
                pos = l;
                
                pass1 = abs(l-pos1);
                pos1 = r;
            //}
            pass += r - l + 1;
            pass1 += r - l + 1;
        }
        pass += abs(n-pos);
        pass1 += abs(n-pos1);
        pass = min(pass,pass1);
        printf("%ld\n",pass-1);
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

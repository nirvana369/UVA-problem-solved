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

#define fi "10493.inp"
#define fo "10493.out"
/**/
using namespace std;
/**/
void input()
{
    long n,m;
    long cat,sum;
    
    while(scanf("%ld %ld",&n,&m))
    {
        if(!n && !m)
            break;
        printf("%ld %ld ",n,m);
        if(m == 1 && n == 1)
            printf("Multiple\n",n,m);
        else if(n == 1 || (n*m-1)%(n-1))
            printf("Impossible\n");
        else
            printf("%ld\n",(n*m-1)/(n-1));
/*        cat = 1;
        sum = 0;
        while(cat < m)
        {
            sum += cat;
            if(cat * n >= m)
                break;
            cat *= n;
        }
        
        while(cat < m)
        {
            cat--;
            cat += n;
            sum += n;
            if(cat >= m)
                break;
        }
        
        if(cat == m)
            printf("%ld %ld %ld\n",n,m,sum);
        else
            printf("%ld %ld Impossible\n",n,m);*/
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

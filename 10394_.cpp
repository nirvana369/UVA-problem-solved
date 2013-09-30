#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10394.inp"
#define fo "10394.out"
/**/
using namespace std;
/**/
struct data{
                long a,b;
            };
data couple[100005];
int d[20000000];
/**/
bool isnt(long value)
{
    int i;
    int add,temp;
    
    if(value == 2 || value == 3)
        return true;
    if(value % 2 == 0 || value % 3 == 0)
        return false;
    temp = (int)sqrt(value);
    add = 2;
    for(i=5;i<=temp;i=i+add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    long i,j;
    long id;
    
    id = 1;
    d[1] = 0;
    for(i=3;i<=18409201;i+=2)
        d[i] = 0;
        
    for(i=3;i<=18409201;i+=2)
    {
        if(d[i] == 0)
        {
            for(j=3;j<=9204600;j+=2)
            {
                if(i * j > 18409201)            
                    break;
                d[i * j] = 2;
            }
            if(isnt(i))
            {
                d[i] = 1;
                if(d[i-2] == 1)
                {
                    couple[id].a = i-2;
                    couple[id].b = i;
                    id++;
                }
            }
            else
                d[i] = 2;
        }
    }
}
/**/
void input()
{
    long n;
    precal();
    
    while(scanf("%ld",&n) == 1)
        printf("(%ld, %ld)\n",couple[n].a,couple[n].b);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

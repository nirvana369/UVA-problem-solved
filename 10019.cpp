/*
                                                    Hoang Linh

                                  Problem: FUNNY ENCRYPTION METHOD - 10019 (10019.*) 
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10019.inp"
#define fo "10019.out"
/**/
using namespace std;
/**/
int hex[10] = {0,1,1,2,1,2,2,3,1,2};
int n;
/**/
void solve()
{
    int dembin,demhex;
    int temp;
    temp = n;
    dembin = 0;
    demhex = 0;
    
    while(n != 0 || temp != 0)
    {
        if(temp != 0)
        {
            demhex = demhex + hex[temp%10];
            temp = temp / 10;
        }
        if(n != 0)
        {
            if(n % 2 != 0)    
                dembin++;
            n = n / 2;
        }
    }
    printf("%d %d\n",dembin,demhex);
}
/**/
void input()
{
    int itest;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d",&n);
        solve();
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

/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "377.inp"
#define fo "377.out"
/**/
using namespace std;
/**/
int chuyen(char s[])
{   
    int val;
    int i;
    
    val = 0;
    i = 0;
    while(s[i])   
    {
        val *= 4;
        if(s[i] == 'U')
            val++;
        else if(s[i] == 'C')
            val += 2;
        else if(s[i] == 'D')
            val += 3;
        i++;
    }
    return val;
}
/**/
void input()
{
    int i;
    int ntest;
    int val1,val2;
    char a[1100],b[1100],s[1100];
    
    scanf("%d",&ntest);

    printf("COWCULATIONS OUTPUT\n");
    while(ntest--)
    {
        scanf("%s %s",&a,&b);

        val1 = chuyen(a);
        val2 = chuyen(b);
        
        for(i=0;i<3;i++)
        {
            scanf("%s",&s);
            if(s[0] == 'A')
                val2 += val1;
            else if(s[0] == 'L')
                val2 *= 4;
            else if(s[0] == 'R')
                val2 /= 4;
        }
        scanf("%s",&s);
        if(val2==chuyen(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    printf("END OF OUTPUT\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

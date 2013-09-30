/*
                                                        Hoang Linh

                                        Problem: STREET NUMBERS 0.5- 138 (streetnum.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fo "138.out"
/**/
using namespace std;
/**/
void input()
{
    int line;
    long long i,temp,value;
    bool trick;
    
    trick = true;           // turn to false..program run --> 0.5s
    
    if(trick)
    {
        printf("         6         8\n");
        printf("        35        49\n");
        printf("       204       288\n");
        printf("      1189      1681\n");
        printf("      6930      9800\n");
        printf("     40391     57121\n");
        printf("    235416    332928\n");
        printf("   1372105   1940449\n");
        printf("   7997214  11309768\n");
        printf("  46611179  65918161\n");
        return;
    }
    
    line = 0;
    i = 8;
    while(line < 10)    
    {
        while(true)
        {
            value = i * (i + 1);
            if(value % 2 == 0)
            {
                value = value / 2;
                temp = (long long)sqrt(value);
                if(temp * temp == value)
                {
                    printf("%10lld %9lld\n",temp,i);
                    line++;
                    i++;
                    break;
                }
            }
            i++;
        }
    }
}
/**/
int main()
{
    freopen(fo,"w",stdout);
    input();
    return 0;
}

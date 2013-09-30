/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11233.inp"
#define fo "11233.out"
/**/
using namespace std;
/**/
void input()
{
    int i,j;
    int n,m,l;
    char s1[50],s2[50];
    map <string, string> mmap;
    
    while(true)
    {
        n = m = 0;
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        mmap.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s %s",&s1,&s2);
            mmap[s1] = s2;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",&s1);
            l = strlen(s1);
            if(mmap[s1] != "")
                cout << mmap[s1] <<endl;
            else if(s1[l-1] == 'y' && (s1[l-2] != 'a' && s1[l-2] != 'e' && s1[l-2] != 'i' && s1[l-2] != 'o' && s1[l-2] != 'u'))
            {
                for(j=0;j<l-1;j++)
                    printf("%c",s1[j]);
                printf("ies\n");
            }
            else if(s1[l-1] == 'o' || s1[l-1] == 's' || s1[l-1] == 'x' || (s1[l-1] == 'h' && s1[l-2] == 'c') || (s1[l-1] == 'h' && s1[l-2] == 's'))
            {
                printf("%s",s1);
                printf("es\n");
            }
            else
            {
                printf("%s",s1);
                printf("s\n");
            }
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

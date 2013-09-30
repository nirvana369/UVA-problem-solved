/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10197.inp"
#define fo "10197.out"
/**/
using namespace std;
/**/
char a[1000],b[1000],s[1000],pro[7][100],rd[7][100],st[7][100];
/**/
void khoitao()
{
    strcpy(pro[0],"eu");
    strcpy(pro[1],"tu");
    strcpy(pro[2],"ele/ela");
    strcpy(pro[3],"n");
    pro[3][1] = 243;
    pro[3][2] = 's';
    pro[3][3] = 0;
    strcpy(pro[4],"v");
    pro[4][1] = 243;
    pro[4][2] = 's';
    pro[4][3] = 0;
    strcpy(pro[5],"eles/elas");
    
    strcpy(st[0],"o");
    strcpy(st[1],"s");
    strcpy(st[2],"");
    strcpy(st[3],"mos");
    strcpy(st[4],"is");
    strcpy(st[5],"m");
    
    strcpy(rd[0],"o");
    strcpy(rd[1],"es");
    strcpy(rd[2],"e");
    strcpy(rd[3],"mos");
    strcpy(rd[4],"s");
    strcpy(rd[5],"em");
}
/**/
void output1()
{
    int i;
    char kt;
    kt = a[strlen(a) - 2];
    a[strlen(a) - 2] = 0;
    for(i=0;i<6;i++)
    {
        printf("%-10s%s",pro[i],a);
        if(i)
            printf("%c",kt);
        printf("%s\n",st[i]);
    }
}
/**/
void output2()
{
    int i;
    char kt;
    kt = a[strlen(a) - 2];
    a[strlen(a) - 2] = 0;
    for(i=0;i<6;i++)
    {
        printf("%-10s%s",pro[i],a);
        if(i == 3 || i == 4)
            printf("%c",kt);
        printf("%s\n",rd[i]);
    }
}
/**/
void input()
{
    int id;
    khoitao();
    id = 0;
    while(!feof(stdin))
    {
        gets(s);
        if(feof(stdin))
            break;
        if(id)
            printf("\n");
        sscanf(s,"%s %s",&a,&b);
        printf("%s (to %s)\n",a,b);
        if(a[strlen(a)-1] == 'r')
        {
            if(a[strlen(a)-2] == 'a' || a[strlen(a)-2] == 'e')
                output1();
            else if(a[strlen(a)-2] == 'i')
                output2();
            else
                printf("Unknown conjugation\n");
        }
        else
            printf("Unknown conjugation\n");
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

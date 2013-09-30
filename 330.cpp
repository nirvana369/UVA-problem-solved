/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "330.inp"
#define fo "330.out"
/**/
using namespace std;
/**/
struct inven{
                double mua,ban;
                int sl;
                bool tontai;
            };
inven item[32000];
map<string,int > mmap;
double buycost,sellcost,lo;
int id;
/**/
void add_item()
{
    char s[1000];

    scanf("%s",&s);
    mmap[s] = id;
    item[id].tontai = true;
    item[id].sl = 0;
    scanf("%lf %lf",&item[id].mua,&item[id].ban);
    id++;
}
/**/
void buy_item()
{
    char s[1000];
    int q,tt;
    
    scanf("%s %d",&s,&q);
    tt = mmap[s];
    item[tt].sl += q;
}
/**/
void del_item()
{
    char s[1000];
    int tt;
    
    scanf("%s",&s);
    tt = mmap[s];
    lo += item[tt].mua * item[tt].sl;
    item[tt].tontai = false;
}
/**/
void sel_item()
{
    char s[1000];
    int q,tt;
    
    scanf("%s %d",&s,&q);
    tt = mmap[s];
    
    if(q > item[tt].sl)
        q = item[tt].sl;
        
    buycost += item[tt].mua * q;
    sellcost += item[tt].ban * q;
    item[tt].sl -= q;
}
/**/
void copystr(char s[],string s1)
{
    int i;
    for(i=0;i<s1.length();i++)
        s[i] = s1[i];
    s[i] = 0;
}
/**/
void report()
{
    map<string, int >::iterator i;
    double pfit,tong,tmp;
    int tt;
    string str;
    char s[1000];
    
    pfit = sellcost - buycost - lo;
    buycost = sellcost = lo = tong = 0;
    printf("                  INVENTORY REPORT\n");
    printf("Item Name     Buy At      Sell At      On Hand        Value\n");
    printf("---------     ------      -------      -------        -----\n");
    for(i=mmap.begin();i!=mmap.end();i++)
        if(item[i->second].tontai)
        {
            tt = i -> second;
            str = i -> first;
            copystr(s,str);
            tmp = item[tt].sl*item[tt].mua;
            printf("%-15s%5.2lf%13.2lf%13d%13.2lf\n",s,item[tt].mua,item[tt].ban,item[tt].sl,tmp);
            tong += tmp;
        }
    printf("------------------------\n");
    printf("Total value of inventory%35.2lf\n",tong);
    printf("Profit since last report%35.2lf\n",pfit);
    printf("\n");
}
/**/
void input()
{
    char s[1000];
    
    mmap.clear();
    id = 1;
    buycost = sellcost = lo = 0;
    while(true)
    {
        scanf("%s",&s);
        if(strlen(s) == 1 && s[0] == '*')
            break;
        if(strcmp(s,"new") == 0)
            add_item();
        else if(strcmp(s,"buy") == 0)
            buy_item();
        else if(strcmp(s,"sell") == 0)
            sel_item();
        else if(strcmp(s,"delete") == 0)
            del_item();
        else if(strcmp(s,"report") == 0)
            report();
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

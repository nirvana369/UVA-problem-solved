/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10315.inp"
#define fo "10315.out"
/**/
using namespace std;
/**/
struct poker{
                int lvl,kind;
            };
poker a[3][6];
int ss[3][5];
/**/
int getlvl(char kt)
{
    if(kt > '1' && kt <= '9')
        return kt - 48;
    if(kt == 'T')
        return 10;
    if(kt == 'J')
        return 11;
    if(kt == 'Q')
        return 12;
    if(kt == 'K')
        return 13;
    if(kt == 'A')
        return 14;
}
/**/
int getkind(char kt)
{
    if(kt == 'S')
        return 4;
    if(kt == 'H')
        return 3;
    if(kt == 'D')
        return 2;
    return 1;
}
/**/
void sapxep(int id)
{
    int i,j;
    poker temp;
    for(i=0;i<4;i++)
        for(j=i+1;j<5;j++)
            if(a[id][i].lvl < a[id][j].lvl)
            {
                temp = a[id][i];
                a[id][i] = a[id][j];
                a[id][j] = temp;
            }
}
/**/
bool kiemtra(int id)
{
    if(a[id][0].lvl != a[id][1].lvl)
        return true;
    if(a[id][4].lvl != a[id][3].lvl)
        return true;
    return false;
}
/**/
int phanloai(int id)
{
    int i;
    int dem,bac,suit,num;
    
    bac = 0;
    dem = 0;
    suit = 0;
    num = 0;
    for(i=0;i<5;i++)
        ss[id][i] = 0;
    for(i=4;i>0;i--)
    {
        if(a[id][i].lvl == a[id][i-1].lvl)
        {
            ss[id][dem] = a[id][i].lvl;
            if(a[id][i].lvl > num)
                num = a[id][i].lvl;
            dem++;
        }
        if(a[id][i].lvl - a[id][i-1].lvl == -1)
        {
            if(a[id][i].kind == a[id][i-1].kind)
                suit++;
            bac++;
        }
    }
    if(bac == 4 && suit == 4)
        return 9;
    if(dem == 3 && kiemtra(id))    
        return 8;
    if(dem == 3)
        return 7;
    if(suit == 4)    
        return 6;
    if(bac == 4)
        return 5;
    bac = 0;
    for(i=0;i<5;i++)
        if(a[id][i].lvl == num)
            bac++;
    if(bac == 3)
        return 4;
    if(bac == 2 && dem == 2)
        return 3;
    if(bac == 2)
        return 2;
    return 1;
}
/**/
int twocard()
{
    int i,j,dem,dem1;
    int b[15],w[15],tb[3],tw[3],ob[5],ow[5];
    
    for(i=2;i<15;i++)
        b[i] = w[i] = 0;
    tb[0] = tw[0] = 0;
    tb[1] = tw[1] = 0;
    for(i=0;i<5;i++)
    {
        b[a[1][i].lvl]++;
        w[a[2][i].lvl]++;
    }
    i = j = 14;
    dem = 0;
    dem1 = 0;
    while(i > 1)
    {
        if(b[i] == 2)
            tb[dem++] = i;
        else if(b[i] == 1)
            ob[dem1++] = i;
        i--;
    }
    dem = dem1 = 0;
    while(j > 1)
    {
        if(w[j] == 2)
            tw[dem++] = j;
        else if(w[j] == 1)
            ow[dem1++] = j;
        j--;
    }
    for(i=0;i<dem;i++)
    {
        if(tb[i] > tw[i])
            return 1;
        if(tb[i] < tw[i])
            return 2;
    }
    
    for(i=0;i<dem1;i++)
    {
        if(ob[i] > ow[i])
            return 1;
        if(ob[i] < ow[i])
            return 2;
    }
    return 0;
}
/**/
void solve(char s[])
{
    int w,b;
    int i,j;
    int l,dem,id,tg;
    char temp[1000];
    l = strlen(s);
    s[l] = ' ';
    id = 1;
    j = dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] == ' ' && j != 0)
        {
            a[id][dem].lvl = getlvl(temp[0]);
            a[id][dem].kind = getkind(temp[1]);
            dem++;
            if(dem == 5)
            {
                dem = 0;
                id++;
            }
            j = 0;
        }
        else
            temp[j++] = s[i];
            
    sapxep(1);
    sapxep(2);
    b = phanloai(1);
    w = phanloai(2);
    //printf("%d %d\n",b,w);
    if(w > b)
        printf("White wins.\n");
    else if(b > w)
        printf("Black wins.\n");
    else
    {
        if(w == 9 || w == 6 || w == 5 || w == 1)    
        {
            for(j=0;j<5;j++)
                if(a[1][j].lvl > a[2][j].lvl)
                {
                    printf("Black wins.\n");
                    return;
                }
                else if(a[2][j].lvl > a[1][j].lvl)
                {
                    printf("White wins.\n");
                    return;
                }
            printf("Tie.\n");
        }
        else if(b == 8)
        {
            if(ss[1][2] > ss[2][2])
            {
                printf("Black wins.\n");
                return;
            }
            else if(ss[2][2] > ss[1][2])
            {
                printf("White wins.\n");
                return;
            }
            printf("Tie.\n");
        }
        else if(w == 7 || b == 4)
        {
            if(ss[1][1] > ss[2][1])
            {
                printf("Black wins.\n");
                return;
            }
            else if(ss[2][1] > ss[1][1])
            {
                printf("White wins.\n");
                return;
            }
            printf("Tie.\n");
        }
        else
        {
            tg = twocard();
            if(tg == 1)
                printf("Black wins.\n");
            else if(tg == 2)
                printf("White wins.\n");
            else
                printf("Tie.\n");
        }
    }
}
/**/
void input()
{
    char temp[1000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        solve(temp);
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

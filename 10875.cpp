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
#include <vector>

#define fi "10875.inp"
#define fo "10875.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
int lbl[15][6],a[10][1000];
long long giatri[1000];
char kq[10][10],lastval[1000];
int col;
/**/
void _init()
{
    lbl[0][0] = 7;            lbl[1][0] = 2;            lbl[2][0] = 7;
    lbl[0][1] = 5;            lbl[1][1] = 2;            lbl[2][1] = 1;
    lbl[0][2] = 5;            lbl[1][2] = 2;            lbl[2][2] = 7;
    lbl[0][3] = 5;            lbl[1][3] = 2;            lbl[2][3] = 4;
    lbl[0][4] = 7;            lbl[1][4] = 2;            lbl[2][4] = 7;
    
    lbl[3][0] = 7;            lbl[4][0] = 5;            lbl[5][0] = 7;
    lbl[3][1] = 1;            lbl[4][1] = 5;            lbl[5][1] = 4;
    lbl[3][2] = 7;            lbl[4][2] = 7;            lbl[5][2] = 7;
    lbl[3][3] = 1;            lbl[4][3] = 1;            lbl[5][3] = 1;
    lbl[3][4] = 7;            lbl[4][4] = 1;            lbl[5][4] = 7;
    
    lbl[6][0] = 4;            lbl[7][0] = 7;            lbl[8][0] = 7;
    lbl[6][1] = 4;            lbl[7][1] = 1;            lbl[8][1] = 5;
    lbl[6][2] = 7;            lbl[7][2] = 1;            lbl[8][2] = 7;
    lbl[6][3] = 5;            lbl[7][3] = 1;            lbl[8][3] = 5;
    lbl[6][4] = 7;            lbl[7][4] = 1;            lbl[8][4] = 7;
    
    lbl[9][0] = 7;            lbl[10][0] = 2;           lbl[11][0] = 0;
    lbl[9][1] = 5;            lbl[10][1] = 2;           lbl[11][1] = 0;
    lbl[9][2] = 7;            lbl[10][2] = 7;           lbl[11][2] = 7;
    lbl[9][3] = 1;            lbl[10][3] = 2;           lbl[11][3] = 0;
    lbl[9][4] = 1;            lbl[10][4] = 2;           lbl[11][4] = 0;
    
    lbl[12][0] = 5;           lbl[13][0] = 2; 
    lbl[12][1] = 5;           lbl[13][1] = 0; 
    lbl[12][2] = 2;           lbl[13][2] = 7; 
    lbl[12][3] = 5;           lbl[13][3] = 0;
    lbl[12][4] = 5;           lbl[13][4] = 2; 
    
    mmap.clear();
    mmap["..."] = 0;
    mmap["..0"] = 1;
    mmap[".0."] = 2;
    mmap["0.."] = 4;
    mmap["0.0"] = 5;
    mmap["000"] = 7;
    
    strcpy(kq[0],"...");
    strcpy(kq[1],"..0");
    strcpy(kq[2],".0.");
    strcpy(kq[4],"0..");
    strcpy(kq[5],"0.0");
    strcpy(kq[7],"000");
}
/**/
void xuly(int row,char s[])
{
    char temp[5];
    int dem;
    int i,j;
    
    j = 0;
    i = dem = 0;
    while(s[i] != 0)
    {
        if(s[i] == ' ')
        {
            temp[dem] = 0;
            a[row][j++] = mmap[temp];
            
            dem = 0;
        }
        else
            temp[dem++] = s[i];
        i++;
    }
    
    temp[dem] = 0;
    a[row][j] = mmap[temp];
    col = j;
}
/**/
int kiemtra(int cot)
{
    int i,j;
    for(i=0;i<14;i++)
    {
        for(j=0;j<5;j++)
            if(lbl[i][j] != a[j][cot])
                break;
        if(j == 5)
            return i;
    }
    return -1;
}
/**/
void donmang(int vitri,int maxlen)
{
    int i;
    for(i=vitri+2;i<maxlen;i++)
        giatri[vitri++] = giatri[i];
}
/**/
int getid(char kt)
{
    int i;
    for(i='0';i<='9';i++)
        if(kt == i)
            return i-48;
    if(kt == '+')
        return 10;
    if(kt == '-')
        return 11;
    if(kt == '*')
        return 12;
    return 13;
}
/**/
void output()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        j = 0;
        while(lastval[j] != 0)
        {
            printf("%s",kq[lbl[getid(lastval[j])][i]]);
            j++;
            if(lastval[j] != 0)
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
/**/
bool solve()
{
    int i,j;
    int temp;
    long long val;
    int dgt;
        
    col++;
    for(i=0;i<5;i++)    
        a[i][col] = 0;

    val = 0;
    dgt = 0;
    for(i=0;i<=col;i++)
    {
        temp = kiemtra(i);
        if(temp >= 0 && temp < 10)
        {
            val *= 10;
            val += temp;
        }
        else
        {
            giatri[dgt++] = val;
            if(temp != -1)
            {
                if(temp == 10)
                    giatri[dgt++] = -1; // +
                else if(temp == 11)
                    giatri[dgt++] = -2; // -
                else if(temp == 12)
                    giatri[dgt++] = -3; // *
                else if(temp == 13)
                    giatri[dgt++] = -4; // /
                val = 0;                   
            }
        }
    }
    
    i = 0;
    while(i < dgt)
    {
        if(giatri[i] == -3)
        {
            giatri[i-1] *= giatri[i+1];
            donmang(i,dgt);
            dgt -= 2;
            i--;
        }
        
        if(giatri[i] == -4)
        {
            giatri[i-1] /= giatri[i+1];
            donmang(i,dgt);
            dgt -= 2;
            i--;
        }
        i++;
    }
    
    if(giatri[0] == 0 && dgt == 1)
        return true;
        
    i = 0;
    while(i < dgt)
    {
        if(giatri[i] == -1)
        {
            giatri[i-1] += giatri[i+1];
            donmang(i,dgt);
            dgt -= 2;
            i--;
        }
        
        if(giatri[i] == -2)
        {
            giatri[i-1] -= giatri[i+1];
            donmang(i,dgt);
            dgt -= 2;
            i--;
        }
        i++;
    }
    
    sprintf(lastval,"%lld",giatri[0]);
    output();
    return false;
}
/**/
void input()
{
    int i;
    _init();
    char s[1000];
    while(true)
    {
        for(i=0;i<5;i++)
        {
            s[0] = 0;
            gets(s);
            xuly(i,s);
        }
        if(solve())
            return;
        gets(s);
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

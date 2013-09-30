/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "464.inp"
#define fo "464.out"
/**/
using namespace std;
/**/
char word[50][20],kq[1000];
int n[50],id[25][10][10],sl[25][10],st[25];
int dem,tmp;
map<string, int > mmap;
/**/
void _init()
{
    int i,j,k;
    mmap.clear();
    mmap["sentence"] = 1; //  lua chon                      1
    n[1] = 2;
    id[1][1][1] = 2; // chi so
    id[1][2][1] = 3;
    sl[1][1] = 1; //  so lua chon
    sl[1][2] = 1;
    mmap["trans-sentence"] = 2;                         //    2
    n[2] = 1;
    sl[2][1] = 4;
    id[2][1][1] = 4;
    id[2][1][2] = 9;
    id[2][1][3] = 5;
    id[2][1][4] = 11;
    mmap["intrans-sentence"] = 3;                       //    3
    n[3] = 1;
    sl[3][1] = 3;
    id[3][1][1] = 4;
    id[3][1][2] = 10;
    id[3][1][3] = 11;
    mmap["subject"] = 4;                               //    4
    n[4] = 1;
    sl[4][1] = 1;
    id[4][1][1] = 6;
    mmap["object"] = 5;                                   //    5
    n[5] = 1;
    sl[5][1] = 1;
    id[5][1][1] = 6;
    mmap["noun-phrase"] = 6;                            //    6
    n[6] = 1;
    sl[6][1] = 2;
    id[6][1][1] = 15;
    id[6][1][2] = 7;
    mmap["modified-noun"] = 7;      //    7
    n[7] = 2;
    sl[7][1] = 1;
    id[7][1][1] = 12;
    sl[7][2] = 2;
    id[7][2][1] = 8;
    id[7][2][2] = 12;
    mmap["modifier"] = 8;           //    8
    n[8] = 2;
    sl[8][1] = 1;
    id[8][1][1] = 16;
    sl[8][2] = 2;
    id[8][2][1] = 17;
    id[8][2][2] = 16;
    mmap["verb-phrase"] = 9;            //    9
    n[9] = 2;
    sl[9][1] = 1;
    id[9][1][1] = 13;
    sl[9][2] = 2;
    id[9][2][1] = 17;
    id[9][2][2] = 13;
    mmap["intrans-verb-phrase"] = 10;        //    10
    n[10] = 2;
    sl[10][1] = 1;
    id[10][1][1] = 14;
    sl[10][2] = 2;
    id[10][2][1] = 17;
    id[10][2][2] = 14;
    mmap["prep-phrase"] = 11;                //    11
    n[11] = 2;
    sl[11][2] = 19;
    id[11][2][1] = 16;
    sl[11][1] = 2;
    id[11][1][1] = 18;
    id[11][1][2] = 6;
    mmap["noun"] = 12;                   //    12
    n[12] = 5;
    // special
    k = 20;
    for(i=1;i<=5;i++)
    {
        sl[12][i] = 1;
        for(j=1;j<=sl[12][i];j++)
            id[12][i][j] = k++;
    }
    mmap["trans-verb"] = 13;             //    13
    n[13] = 4;
    for(i=1;i<=4;i++)
    {
        sl[13][i] = 1;
        for(j=1;j<=sl[13][i];j++)
            id[13][i][j] = k++;
    }
    mmap["intrans-verb"] = 14;           //    14
    n[14] = 4;
    for(i=1;i<=4;i++)
    {
        sl[14][i] = 1;
        for(j=1;j<=sl[14][i];j++)
            id[14][i][j] = k++;
    }
    mmap["article"] = 15;            //    15
    n[15] = 2;
    for(i=1;i<=2;i++)
    {
        sl[15][i] = 1;
        for(j=1;j<=sl[15][i];j++)
            id[15][i][j] = k++;
    }
    mmap["adjective"] = 16;          //    16
    n[16] = 4;
    for(i=1;i<=4;i++)
    {
        sl[16][i] = 1;
        for(j=1;j<=sl[16][i];j++)
            id[16][i][j] = k++;
    }
    mmap["adverb"] = 17;             //    17
    n[17] = 3;
    for(i=1;i<=3;i++)
    {
        sl[17][i] = 1;
        for(j=1;j<=sl[17][i];j++)
            id[17][i][j] = k++;
    }
    mmap["preposition"] = 18;            //    18
    n[18] = 3;
    for(i=1;i<=3;i++)
    {
        sl[18][i] = 1;
        for(j=1;j<=sl[18][i];j++)
            id[18][i][j] = k++;
    }
    mmap["empty"] = 19;                      //    19
    n[19] = 1;
    sl[19][1] = 1;
    id[19][1][1] = k;
    
    strcpy(word[20],"man");
    strcpy(word[21],"dog");
    strcpy(word[22],"fish");
    strcpy(word[23],"computer");
    strcpy(word[24],"waves");
    strcpy(word[25],"struck");
    strcpy(word[26],"saw");
    strcpy(word[27],"bit");
    strcpy(word[28],"took");
    strcpy(word[29],"slept");
    strcpy(word[30],"jumped");
    strcpy(word[31],"walked");
    strcpy(word[32],"swam");
    strcpy(word[33],"the");
    strcpy(word[34],"a");
    strcpy(word[35],"green");
    strcpy(word[36],"small");
    strcpy(word[37],"rapid");
    strcpy(word[38],"quick");
    strcpy(word[39],"nearly");
    strcpy(word[40],"suddenly");
    strcpy(word[41],"restlessly");
    strcpy(word[42],"on");
    strcpy(word[43],"over");
    strcpy(word[44],"through");
    strcpy(word[45],"");
    
    for(i=20;i<=45;i++)
        mmap[word[i]] = i;
    for(i=1;i<20;i++)
        st[i] = 1;
}
/**/
void noichuoi(int xp)
{
    int i;
    i = 0;
    while(word[xp][i])
        kq[dem++] = word[xp][i++];
    kq[dem++] = ' ';
}
/**/
void solve(int xp)
{
    int i;
        
    if(xp >= 20 && xp <= 45)
    {
        noichuoi(xp);
        return;
    }
    
    //st[xp]++;
    //if(st[xp] > n[xp])
    //    st[xp] = 1;
    tmp++;
        
    for(i=1;i<=sl[xp][tmp%n[xp]];i++)
        solve(id[xp][tmp%n[xp]][i]);
}
/**/
void input()
{
    char s[100];
    int xp;
    _init();
    tmp = 0;
    while(gets(s))
    {
        dem = 0;
        xp = mmap[s];
        solve(xp);
        kq[dem] = 0;
        printf("%s\n",kq);
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

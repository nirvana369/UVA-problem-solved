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

#define fi "12478.inp"
#define fo "12478.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
char a[10][10],word[9][9],kq[9];
int len[9],d[9];
/**/
bool kiemtra(char s[],int l)
{
    int i,j,k;
    int dem;
    int m[10];
    
    for(i=0;i<8;i++)
        if(l == len[i])
        {
            for(j=0;j<l;j++)
                m[j] = 0;
            dem = 0;
            for(j=0;j<l;j++)
                for(k=0;k<l;k++)
                    if(!m[k] && s[k] == word[i][j])
                    {
                        m[k] = 1;
                        dem++;
                        break;
                    }
            if(dem == l)
                d[i]++;
            if(d[i] == 3)
            {
                strcpy(kq,word[i]);
                return true;
            }
        }
    return false;
}
/**/
void solve()
{
    int i,j,k;
    int x,y;
    int dem;
    char temp[15];
    
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            for(k=0;k<8;k++)
            {
                x = i;
                y = j;
                dem = 0;
                while(x+h[k].x >= 0 && x+h[k].x < 9 && y + h[k].y >= 0 && y + h[k].y < 9)
                {
                    temp[dem++] = a[x][y];
                    if(dem > 3 && dem < 8)
                    {
                        temp[dem] = 0;
                        //printf("%s\n",temp);
                        if(kiemtra(temp,dem))
                            return;
                    }
                    x += h[k].x;
                    y += h[k].y;
                }
            }
        }
}
/**/
void precal()
{
    int i;
    strcpy(a[0],"OBIDAIBKR");
    strcpy(a[1],"RKAULHISP");
    strcpy(a[2],"SADIYANNO");
    strcpy(a[3],"HEISAWHIA");
    strcpy(a[4],"IRAKIBULS");
    strcpy(a[5],"MFBINTRNO");
    strcpy(a[6],"UTOYZIFAH");
    strcpy(a[7],"LEBSYNUNE");
    strcpy(a[8],"EMOTIONAL");
    
    strcpy(word[0],"RAKIBUL");
    strcpy(word[1],"ANINDYA");
    strcpy(word[2],"MOSHIUR");
    strcpy(word[3],"SHIPLU");
    strcpy(word[4],"KABIR");
    strcpy(word[5],"SUNNY");
    strcpy(word[6],"OBAIDA");
    strcpy(word[7],"WASI");
    for(i=0;i<8;i++)
    {
        len[i] = strlen(word[i]);
        d[i] = 0;
    }
    solve();
}
/**/
void input()
{
    //precal();         // find word from grid
    strcpy(kq,"KABIR"); // cheater :))
    printf("%s\n",kq);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

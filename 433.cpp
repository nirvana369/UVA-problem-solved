/*
                                                Hoang Linh
                                    
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "bank1.inp"
#define fo "bank1.out"
#define maxdong 27
/////////////////////////
using namespace std;
////////////////////////
struct csdl{
                char s[4] , s1[4] , s2[4];
            };
struct data{
                char str[30];
            };
csdl number[10];
int a[10] , d[10][10] , d2[10] ,kq[10];
data strkt[3];
int giaiphap;
////////////////////////
void khoitao()
{
    int i , j ;
    
    strcpy(number[0].s  , "020");   strcpy(number[0].s1 , "101");   strcpy(number[0].s2 , "121");
    strcpy(number[1].s  , "000");   strcpy(number[1].s1 , "001");   strcpy(number[1].s2 , "001");
    strcpy(number[2].s  , "020");   strcpy(number[2].s1 , "021");   strcpy(number[2].s2 , "120");
    strcpy(number[3].s  , "020");   strcpy(number[3].s1 , "021");   strcpy(number[3].s2 , "021");
    strcpy(number[4].s  , "000");   strcpy(number[4].s1 , "121");   strcpy(number[4].s2 , "001");
    strcpy(number[5].s  , "020");   strcpy(number[5].s1 , "120");   strcpy(number[5].s2 , "021");
    strcpy(number[6].s  , "020");   strcpy(number[6].s1 , "120");   strcpy(number[6].s2 , "121");
    strcpy(number[7].s  , "020");   strcpy(number[7].s1 , "001");   strcpy(number[7].s2 , "001");
    strcpy(number[8].s  , "020");   strcpy(number[8].s1 , "121");   strcpy(number[8].s2 , "121");
    strcpy(number[9].s  , "020");   strcpy(number[9].s1 , "121");   strcpy(number[9].s2 , "021");
    
    for(i=0;i<10;i++)    
        for(j=0;j<10;j++)
            d[i][j] = 0;
    
    d[0][8] =  1;          d[2][8] =  1;          d[5][9] =  1;
    d[1][0] =  1;          d[3][8] =  1;          d[6][8] =  1;
    d[1][3] =  1;          d[3][9] =  1;          d[7][0] =  1;
    d[1][4] =  1;          d[4][8] =  1;          d[7][3] =  1;
    d[1][7] =  1;          d[4][9] =  1;          d[7][8] =  1;
    d[1][8] =  1;          d[5][6] =  1;          d[7][9] =  1;
    d[1][9] =  1;          d[5][8] =  1;          d[9][8] =  1;
}
////////////////////////
bool sosanh(int start,int end,char chuoi1[],char chuoi2[])
{
    int i , j ;
    
    for(i=start,j=0;i<end;i++,j++)
        if(chuoi1[i] != chuoi2[j])
            return false;
    return true;
}
////////////////////////
bool timloi(int start,int end,char chuoi1[],char chuoi2[])
{
    int i , j ;
    
    for(i=start,j=0;i<end;i++,j++)
        if((chuoi1[i] == '1' || chuoi1[i] == '2') && chuoi2[j] == '0')
            return false;
    return true;
}
////////////////////////
bool checksum()
{
    int k;
    int tong;
    tong = 0 ;
    for(k=1;k<10;k++)
        tong = tong + a[k] * (10 - k);
    if(tong%11 == 0)
        return true;
    return false;
}
/////////////////////////
void xulyvitriloi(int vitri)
{
    int i , j , id;   
    id = 0;
    
    for(i=0;i<maxdong-1;i=i+3)
    {
        id++;
        if(id == vitri)        
        {
            for(j=0;j<=9;j++)
            {
                d2[j] = 0; 
                if(timloi(i,i+3,strkt[0].str,number[j].s))
                    if(timloi(i,i+3,strkt[1].str,number[j].s1))
                        if(timloi(i,i+3,strkt[2].str,number[j].s2))
                            d2[j] = 1;
            }
            break;
        }
    }
}
///////////////////////
void capnhap()
{
    int i;
    for(i=1;i<10;i++)
        kq[i] = a[i];
}
////////////////////////
void solve()
{
    int i , j , id ;
    bool find;
    int vtsai , temp;
    vtsai = -1;
    id=0;
    for(i=0;i<maxdong-1;i=i+3)
    {
        find=false;
        id++;
        for(j=0;j<=9;j++)
            if(sosanh(i,i+3,strkt[0].str,number[j].s))
                if(sosanh(i,i+3,strkt[1].str,number[j].s1))
                    if(sosanh(i,i+3,strkt[2].str,number[j].s2))
                    {
                        find = true;
                        a[id] = j;
                        break;
                    }
        if(!find)
        {
            a[id] = -1;
            vtsai = id;
        }
    }
    
    if(vtsai == -1)
    {
        if(checksum())
            giaiphap++;
        if(giaiphap == 1)
            capnhap();
        for(i=1;i<=9;i++)
        {
            if(a[i] != 8)
            {
                temp=a[i];
                for(j=0;j<10;j++)
                    if(d[temp][j] == 1)
                    {
                        a[i]=j;
                        if(checksum())
                        {
                            giaiphap++;
                            if(giaiphap == 1)
                                capnhap();
                        }
                    }
                a[i]=temp;
            }
        }
        
    }
    else
    {
        xulyvitriloi(vtsai);
        for(i=0;i<10;i++)
        {
            if(d2[i] == 1)
            {
                a[vtsai]=i;
                if(checksum())
                {
                    giaiphap++;
                    if(giaiphap == 1)
                        capnhap();
                }
            }
        }
    }
}
//////////////////////////
void output()
{
    int i;
    if(giaiphap == 1)
        for(i=1;i<10;i++)
            printf("%d",kq[i]);
    else if(giaiphap == 0)
        printf("failure");
    else
        printf("ambiguous");
    printf("\n");
}
///////////////////////
void mahoa(char chuoi[],int id)
{
    int i ;
    for(i=0;i<maxdong;i++)
        if(chuoi[i] == '|')
            strkt[id].str[i] = '1';
        else if(chuoi[i] == '_')
            strkt[id].str[i] = '2';
        else
            strkt[id].str[i] = '0';
}
////////////////////////
void input()
{
    int ntest ;
    int idong , itest ;
    char temp[30];
    khoitao();
    scanf("%d",&ntest);
    gets(temp);
    
    for(itest=0;itest<ntest;itest++)
    {
        giaiphap=0;
        for(idong=0;idong<3;idong++)
        {
            gets(temp);
            mahoa(temp,idong);
        }
        solve();
        output();
    }
}
////////////////////////
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

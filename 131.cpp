/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "131.inp"
#define fo "131.out"
/**/
using namespace std;
/**/
char card[6][3],org[11][3],kind[10][20];
int val[100],suit[100];

/**/
int solve()
{
    int i,j,k;
    bool full3, full2, conse;
    int suit, dem2,dem;
    char tmp[10];
    // sorting
    k = 0;
    for(i=0;i<5;i++)
        for(j=i+1;j<5;j++)
        {
            if(card[i][1] != card[j][1])
                k = 1;
            if(val[card[i][0]] > val[card[j][0]])
            {
                strcpy(tmp,card[i]);
                strcpy(card[i],card[j]);
                strcpy(card[j],tmp);
            }
        }
    /////////////////////////  straight flush
    conse = false;
    for(i=0;i<4;i++)
        if(val[card[i][0]] + 1 != val[card[i+1][0]])
            break;
            
    if(i == 4)
        conse = true;
            
    if(val[card[0][0]] == 1)
    {
        for(i=4;i>1;i--)
            if(val[card[i][0]] - 1 != val[card[i-1][0]])
                break;
        if(i == 1)
            conse = true;
    }
    
    if(conse && !k)
        return 8;
    ////////////////////////// four a kind
    full3 = full2 = false;
    dem2 = 0;
    for(i=0;i<5;i++)
    {
        dem = 0;
        suit = 0;
        for(j=0;j<5;j++)
        {
            if(card[i][1] == card[j][1])
                suit++;
            if(val[card[i][0]] == val[card[j][0]])
                dem++;
        }
        if(dem == 3)
            full3 = true;
        if(dem == 2)
        {
            dem2++;
            full2 = true;
        }
        if(dem == 4)
            return 7;
    }
    ////////// full house
    if(full3 && full2)
        return 6;
    ////////////// flush
    if(suit == 5)
        return 5;
    //////////////// straight
    if(conse)
        return 4;
    
    if(full3) // three a kind
        return 3;
    
    ///////// two pair
    if(dem2 == 4)
        return 2;
        
    if(full2) // pair
        return 1;
    return 0; // high card
}
/**/
void _init()
{
    int i,j;
    
    suit['C'] = 0;
    suit['D'] = 1;
    suit['S'] = 2;
    suit['H'] = 3;
    
    val['A'] = 1;
    for(i='2';i<='9';i++)
        val[i] = i - 48;
    val['T'] = 10;
    val['J'] = 11;
    val['Q'] = 12;
    val['K'] = 13;
    
	strcpy(kind[0],"highest-card");
	strcpy(kind[1],"one-pair");
	strcpy(kind[2],"two-pairs");
	strcpy(kind[3],"three-of-a-kind");
	strcpy(kind[4],"straight");
	strcpy(kind[5],"flush");
	strcpy(kind[6],"full-house");
	strcpy(kind[7],"four-of-a-kind");
	strcpy(kind[8],"straight-flush");
}
/**/
void output(int flg)
{
    int i;
    printf("Hand:");
    for(i=0;i<5;i++)
        printf(" %s",org[i]);
    printf(" Deck:");
    for(i=5;i<10;i++)
        printf(" %s",org[i]);
    printf(" Best hand: %s\n",kind[flg]);
}
/**/
void input()
{
    int i,j,k,best;
    
    _init();
    while(true)
    {
        org[0][0] = 0;
        scanf("%s",&org[0]);
        if(!org[0][0])
            break;
        for(i=1;i<10;i++)
            scanf("%s",&org[i]);
        
        best = 0;
        for (i=0; i<32; i++) 
        {
			k = 5;
			for(j=0; j<5; j++) 
            {
				if (i & 1 << j)
				{
					strcpy(card[j], org[j]);
                }
                else 
                {
				    strcpy(card[j], org[k++]);
                }
			}
            j = solve();
			
            if(j > best)
			     best = j;
		}
		output(best);
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

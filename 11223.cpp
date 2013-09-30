/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11223.inp"
#define fo "11223.out"
/**/
using namespace std;
/**/
map <string, char> mmap;
/**/
void khoitao()
{
    mmap.clear();
    mmap[".-"] = 'A';	  mmap[".-.-.-"] = '.';     mmap["-..."] = 'B';	    mmap["--..--"] = ',';
	mmap["-.-."] = 'C';	  mmap["..--.."] = '?';     mmap["-.."] = 'D';	    mmap[".----."] = '\'';
	mmap["."] = 'E';	  mmap["-.-.--"] = '!';     mmap["..-."] = 'F';	    mmap["-..-."] = '/';
	mmap["--."] = 'G';	  mmap["-.--."] = '(';      mmap["...."] = 'H';	    mmap["-.--.-"] = ')';
	mmap[".."] = 'I';	  mmap[".-..."] = '&';      mmap[".---"] = 'J';	    mmap["---..."] = ':';
	mmap["-.-"] = 'K';	  mmap["-.-.-."] = ';';     mmap[".-.."] = 'L';	    mmap["-...-"] = '=';
	mmap["--"] = 'M';	  mmap[".-.-."] = '+'; 	    mmap["-."] = 'N';	    mmap["-....-"] = '-';
	mmap["---"] = 'O';	  mmap["..--.-"] = '_';	    mmap[".--."] = 'P';	    mmap[".-..-."] = '"';
	mmap["--.-"] = 'Q';	  mmap[".--.-."] = '@';	    mmap[".-."] = 'R';		mmap["..."] = 'S';	
	mmap["-"] = 'T';	  mmap["..-"] = 'U';		mmap["...-"] = 'V';		mmap[".--"] = 'W';	
	mmap["-..-"] = 'X';	  mmap["-.--"] = 'Y';		mmap["--.."] = 'Z';		mmap["-----"] = '0';	
	mmap[".----"] = '1';  mmap["..---"] = '2';		mmap["...--"] = '3';    mmap["....-"] = '4';	
	mmap["....."] = '5';  mmap["-...."] = '6';		mmap["--..."] = '7';	mmap["---.."] = '8';	
	mmap["----."] = '9';	
}
/**/
void solve(char s[])
{
    int i;
    char temp[10];
    int l,dem,sp;

    l = strlen(s);
    s[l] = ' ';
    dem = sp = 0;
    for(i=0;i<=l;i++)
    {
        if(s[i] == '.' || s[i] == '-')
        {
            temp[dem++] = s[i];
            sp = 0;
        }
        else
        {
            if(dem != 0)
            {
                temp[dem] = 0;
                cout << mmap[temp];
            }
            sp++;
                
            if(sp == 2 && i != l)
            {
                printf(" ");
                sp = 0;
            }
            dem = 0;
        }
    }
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    int ntest,id;
    khoitao();
    scanf("%d",&ntest);
    id = 1;
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        printf("Message #%d\n",id);
        solve(temp);
        if(ntest != 0)
            printf("\n");
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

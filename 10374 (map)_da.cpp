#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;

map<string, string> party;
map<string, string>::iterator ite_party;
map<string, int> demvote;
map<string, int>::iterator ite_demvote;

char s[100], s1[100], s2[100];
int demmax;
int ntest, itest;
int ncan, nvote;
int max1;

int main()
{
    int i,j;
    
	freopen("10374.inp", "r", stdin);
	freopen("10374.out", "w", stdout);
	
	cin >> ntest;
	for (itest = 0; itest < ntest; itest++)
    {
        demvote.clear();
        party.clear();
        
		cin >> ncan;
		cin.getline(s,100);
		
		for (i=0; i< ncan; i++)
		{
			cin.getline(s1,100); // name
			cin.getline(s2,100); // party
			
			party[s1] = s2;
			demvote[s1] = 0;
		}
		
		cin >> nvote;
		cin.getline(s,100);
		
		max1 = 0;
		for (i=0; i<nvote; i++)
        {
			cin.getline(s,100);
			
			demvote[s]++;
			
			//if (max1 < demvote[s])
			  //   max1 = demvote[s];
		}
		
		max1=0;
		for (ite_party = party.begin(); ite_party != party.end(); ite_party++)
		{
            if (max1 <demvote[ite_party->first])
                max1 = demvote[ite_party->first];
        }
		
		map<string, int>::iterator ite_p;     //khai bao ite phu
		string s_p;                           //khai bao chuoi phu kieu string
		
		demmax = 0;
		for (ite_demvote = demvote.begin(); ite_demvote != demvote.end(); ite_demvote++)
        {
			if (max1 == ite_demvote->second)
            {
				demmax++;
				//s_p = party[ite_demvote->first];   //cach 1
				ite_p = ite_demvote;                 //cach 2
			}
		}
		if (demmax > 1 || max1 ==0)
			cout << "tie" << endl;
		else
		{
			//cout << s_p << endl;                   //cach 1
			cout <<  party[ite_p->first] << endl;    //cach 2
		}
		
		if (itest<ntest-1)
			cout << endl;
	}
	
	return 0;
}


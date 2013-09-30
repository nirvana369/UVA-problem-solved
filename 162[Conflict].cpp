#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#define fi "162.inp"
#define fo "162.out"
using namespace std;


vector<string> split(string str){
	stringstream ss(str);
	string buf;
	vector<string> tokens;

	while(ss>>buf){
		tokens.push_back(buf);
	}
	return tokens;
}

int main(){

    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
	
    map<char,int> cards;
	cards['2'] = 2;
	cards['3'] = 3;
	cards['4'] = 4;
	cards['5'] = 5;
	cards['6'] = 6;
	cards['7'] = 7;
	cards['8'] = 8;
	cards['9'] = 9;
	cards['T'] = 10;
	cards['J'] = 11;
	cards['Q'] = 12;
	cards['K'] = 13;
	cards['A'] = 14;


	int cases=0,i,next;
	string buffer;

	stack<int> deck;

	vector<string> v;
	vector<string>::iterator vit;

	stack<int> heap;

	bool turn;

	while(getline(cin,buffer)){
		turn = false;

		if(buffer == "#"){
			break;
		}else{

			vector<queue<int> > players(2);


			v = split(buffer);

			for(vit=v.begin(); vit!=v.end(); vit++){
				deck.push(cards[(*vit)[1]]);
			}
			for(i=0;i<3;i++){

				getline(cin,buffer);
				v = split(buffer);
				for(vit=v.begin(); vit!=v.end(); vit++){
					deck.push( cards[(*vit)[1]]);
				}
			}

			while(!deck.empty()){
				players[0].push(deck.top());
				deck.pop();
				players[1].push(deck.top());
				deck.pop();
			}

			while(true){
				if(players[0].empty()){
					printf("2 %3d",players[1].size());
					break;
				}
				if(players[1].empty()){
					printf("1 %3d",players[0].size());
					break;
				}

				next = players[turn].front();

				heap.push(next);
				turn = !turn;
				if(next > 10){
					for(i=0;i<next-10;i++){
						players[turn].front();
					}
				}
			}

		}
	}

	return 0;
}

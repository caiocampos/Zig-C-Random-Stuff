#include <iostream>
#include <cstdio>
#include <vector>

#define DECK_SIZE 52

using namespace std;

string intToString(int);
void generateDeck(vector<string>&);
void applyShuffle(vector<int>&, vector<string>&);

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<string> deck;
	vector<vector<int> > shuffles;
	int testCases, numOfShuffles, i, j, n;
	string aux;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		shuffles.clear();
		deck.clear();
		generateDeck(deck);
		if(!(cin >> numOfShuffles)) return 0;
		if(numOfShuffles > 100) return 0;

		for(i = 0; i < numOfShuffles; i++){
			vector<int> shuffle;
			for(j = 0; j < DECK_SIZE; j++){
				cin >> n;
				shuffle.push_back(n);
			}
			shuffles.push_back(shuffle);
		}
		cin.ignore(160, '\n');
		while(cin.peek() != '\n' && cin.peek() != -1){
			cin >> n;
			cin.ignore(160, '\n');
			if(!(n <= 0 || n > numOfShuffles)){
				applyShuffle(shuffles[n-1],deck);
			}
		}
		for(i = 0; i < DECK_SIZE; i++){
			cout << deck[i] << endl;
		}
		if(testCases) cout << endl;
	}
	return 0;
}

string intToString(int n){
	char aux[12];
	sprintf(aux, "%d", n);
	return string(aux);
}

void generateDeck(vector<string> & deck){
	int i, j;
	string aux;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 13; j++){
			aux = "";
			if(j < 9){
				aux += intToString(j+2);
			}if(j == 9){
				aux += "Jack";
			}if(j == 10){
				aux += "Queen";
			}if(j == 11){
				aux += "King";
			}if(j == 12){
				aux += "Ace";
			}
			aux += " of ";
			if(i == 0){
				aux += "Clubs";
			}if(i == 1){
				aux += "Diamonds";
			}if(i == 2){
				aux += "Hearts";
			}if(i == 3){
				aux += "Spades";
			}
			deck.push_back(aux);
		}
	}
}

void applyShuffle(vector<int> & shuffle, vector<string> & deck){
	vector<string> auxdeck;
	for(int i = 0; i < DECK_SIZE; i++){
		auxdeck.push_back(deck[shuffle[i]-1]);
	}
	deck = auxdeck;
}

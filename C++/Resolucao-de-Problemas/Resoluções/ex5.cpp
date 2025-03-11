#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void mapper(map<char,char>&);

int main(int argc , char *argv[]){

	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	map<char,char> map;
	mapper(map);
	string entrada, saida;
	while(cin.peek() != -1){
		entrada.clear();
		saida.clear();
		int i;
		getline(cin,entrada);

		for(i = 0; i < entrada.size(); i++){
			saida.push_back(map[entrada[i]]);
		}
		cout << saida << endl;
	}
	return 0;
}

void mapper(map<char,char> & map){
	map.insert(pair<char,char>(' ',' '));

	map.insert(pair<char,char>('1','`'));
	map.insert(pair<char,char>('2','1'));
	map.insert(pair<char,char>('3','2'));
	map.insert(pair<char,char>('4','3'));
	map.insert(pair<char,char>('5','4'));
	map.insert(pair<char,char>('6','5'));
	map.insert(pair<char,char>('7','6'));
	map.insert(pair<char,char>('8','7'));
	map.insert(pair<char,char>('9','8'));
	map.insert(pair<char,char>('0','9'));
	map.insert(pair<char,char>('-','0'));
	map.insert(pair<char,char>('=','-'));

	map.insert(pair<char,char>('Q','Q'));
	map.insert(pair<char,char>('W','Q'));
	map.insert(pair<char,char>('E','W'));
	map.insert(pair<char,char>('R','E'));
	map.insert(pair<char,char>('T','R'));
	map.insert(pair<char,char>('Y','T'));
	map.insert(pair<char,char>('U','Y'));
	map.insert(pair<char,char>('I','U'));
	map.insert(pair<char,char>('O','I'));
	map.insert(pair<char,char>('P','O'));
	map.insert(pair<char,char>('[','P'));
	map.insert(pair<char,char>(']','['));
	map.insert(pair<char,char>('\\',']'));

	map.insert(pair<char,char>('A','A'));
	map.insert(pair<char,char>('S','A'));
	map.insert(pair<char,char>('D','S'));
	map.insert(pair<char,char>('F','D'));
	map.insert(pair<char,char>('G','F'));
	map.insert(pair<char,char>('H','G'));
	map.insert(pair<char,char>('J','H'));
	map.insert(pair<char,char>('L','K'));
	map.insert(pair<char,char>('K','J'));
	map.insert(pair<char,char>('L','K'));
	map.insert(pair<char,char>(';','L'));
	map.insert(pair<char,char>('\'', ';'));
	
	map.insert(pair<char,char>('Z','Z'));
	map.insert(pair<char,char>('X','Z'));
	map.insert(pair<char,char>('C','X'));
	map.insert(pair<char,char>('V','C'));
	map.insert(pair<char,char>('B','V'));
	map.insert(pair<char,char>('N','B'));
	map.insert(pair<char,char>('M','N'));
	map.insert(pair<char,char>(',','M'));
	map.insert(pair<char,char>('.',','));
	map.insert(pair<char,char>('/','.'));
}

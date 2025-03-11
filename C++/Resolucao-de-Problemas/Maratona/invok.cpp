#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc , char *argv[]){
	//#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<char*> trocas;
	vector<char*> remocoes;
	string invocados, result, aux;
	int testCases, numTrocas, numRemocoes, numInvocados, i, j;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		trocas.clear();
		remocoes.clear();

		cin >> numTrocas;
		for(i = 0; i < numTrocas; i++){
			char aux[3];
			for(j = 0; j < 3; j++) cin >> aux[j];
			trocas.push_back(aux);
		}

		cin >> numRemocoes;
		for(i = 0; i < numRemocoes; i++){
			char aux[2];
			for(j = 0; j < 2; j++) cin >> aux[j];
			remocoes.push_back(aux);
		}

		cin >> numInvocados >> invocados;
	}
	return 0;
}

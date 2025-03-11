#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

struct trabalho{
	int referencia;
	int duracao;
	int custo;
	trabalho(int ref, int dur, int cus){
		referencia = ref;
		duracao = dur;
		custo = cus;
	}
	bool operator<(const trabalho t) const {
		int val1 = duracao * t.custo;
		int val2 = custo * t.duracao;
		if(val1 == val2){
			return referencia < t.referencia;
		}
		return (val1 < val2);
	}
};

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<trabalho> trabalhos;
	int testCases, n1, n2, trabqtd, i;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		trabalhos.clear();
		cin.ignore(80, '\n');
		cin >> trabqtd;
		for(i = 0; i < trabqtd; i++){
			cin >> n1 >> n2;
			trabalhos.push_back(trabalho(i+1,n1,n2));
		}
		sort(trabalhos.begin(), trabalhos.end());
		for(i = 0; i < trabqtd; i++){
			if(i) cout << " ";
			cout << trabalhos[i].referencia;
		}
		cout << endl;
		if(testCases) cout << endl;
	}
}

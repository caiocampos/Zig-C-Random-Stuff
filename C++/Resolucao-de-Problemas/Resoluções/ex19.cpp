#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct elefante {
	int pos;
	int peso;
	int qi;
	elefante() {
		pos = peso = qi = 0;
	}
	elefante(int npos, int npeso, int nqi) {
		pos = npos;
		peso = npeso;
		qi = nqi;
	}
};

bool test(elefante e1, elefante e2) {
	return e1.qi >= e2.qi;
}

vector<int> exec(vector<elefante> vEl) {
	vector<int> melhor(1010,1);
	vector<int> anterior(1010,-1);
	int i, j, pos, max = 0;
	vector<int> result;
	for(i = 1; i < vEl.size(); i++) {
		for(j = 0; j < i; j++) {
			if(vEl[i].peso > vEl[j].peso && melhor[i] < melhor[j] + 1) {
				melhor[i] = melhor[j] + 1;
				anterior[i] = j;
			}
		}
	}
	for(i = 0; i < vEl.size(); i++) {
		if(melhor[i] > max) {
			max = melhor[i];
			pos = i;
		}
	}
	result.clear();
	while(anterior[pos] != -1) {
		result.push_back(vEl[pos].pos);
		pos = anterior[pos];
	}
	result.push_back(vEl[pos].pos);
	reverse(result.begin(), result.end());
	return result;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<elefante> vEl;
	vEl.clear();
	int i, peso, qi;
	for(i = 0; ; i++) {
		if(!(cin >> peso >> qi)) break;
		elefante aux(i + 1, peso, qi);
		vEl.push_back(aux);
	}
	sort(vEl.begin(), vEl.end(), test);
	vector<int> result = exec(vEl);
	cout << result.size() << endl;
	for(i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct tartaruga {
	int peso;
	int forca;
	tartaruga() {
		peso = forca = 0;
	}
	tartaruga(int p, int f) {
		peso = p;
		forca = f - p;
	}
};

bool test(tartaruga t1, tartaruga t2) {
	if(t1.forca < t2.forca) return true;
	if(t1.forca == t2.forca && t1.peso < t2.peso) {
		return true;
	}
	return false;
}

int exec(vector<tartaruga> vT) {
	int i, j, maior, tam = vT.size();
	vector<vector<int> > m(tam+1,vector<int>(tam+1,0));
	for(i = 0; i < tam + 1; i++) {
		for(j = 1; j < tam + 1; j++)
			m[i][j] = INT_MAX;
	}
	for(i = 1; i < tam + 1; i++) {
		for(j = 1; j < i + 1; j++) {
			m[i][j] = m[i][j] < m[i-1][j] ? m[i][j] : m[i-1][j];
			if(m[i-1][j-1] <= vT[i-1].forca) {
				int forca = m[i-1][j-1] + vT[i-1].peso;
				m[i][j] = m[i][j] < forca ? m[i][j] : forca;
			}
		}
	}
	for(i = tam; i >= 1; i--) {
		if(m[tam][i] < INT_MAX) {
			maior = i;
			break;
		}
	}
	return maior;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<tartaruga> vT;
	vT.clear();
	int i, peso, forca;
	for(i = 0; ; i++) {
		if(!(cin >> peso >> forca)) break;
		tartaruga aux(peso, forca);
		vT.push_back(aux);
	}
	sort(vT.begin(), vT.end(), test);
	int result = exec(vT);
	cout << result << endl;
}

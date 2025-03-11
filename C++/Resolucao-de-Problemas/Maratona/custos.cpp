#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc , char *argv[]){
	//#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<int> empregados;
	int testCases, i, n, caso = 1;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		empregados.clear();
		for(i = 0; i < 3; i++){
			cin >> n;
			empregados.push_back(n);
		}
		sort(empregados.begin(),empregados.end());
		cout << "Caso " << caso << ": " << empregados[1] << endl;
		caso++;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<int> rua;
	int testCases, n, i, mediana, result, tamFamilia;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		rua.clear();
		result = 0;
		cin >> tamFamilia;
		for(i = 0; i < tamFamilia; i++){
			cin >> n;
			rua.push_back(n);
		}
		sort(rua.begin(),rua.end());
		mediana = rua[int(tamFamilia/2)];
		for(i = 0; i < tamFamilia; i++){
			result += abs(mediana-rua[i]);
		}
		cout << result << endl;
	}
	return 0;
}

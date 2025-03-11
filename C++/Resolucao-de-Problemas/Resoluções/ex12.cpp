#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> sequence;

void f(){
	long long i, j, val;
	sequence.push_back(1);
	sequence.push_back(2);
	sequence.push_back(4);
	for(i = 0; sequence[sequence[i]-1] < 2000000000; i++){
		for(j = sequence[i]; j < sequence[i+1]; j++){
			if(j == sequence.size()) sequence.push_back(0);
			sequence[j] = sequence[j-1] + i + 1;
		}
	}
}

long long get(long long val){
	long long ini, mei, fim;
	ini = 0;
	fim = sequence.size() - 1;
	while (ini <= fim){
		mei = (ini + fim) / 2;
		if (val > sequence[mei]){
			ini = mei + 1;
		}
		else{
			if (val < sequence[mei]){
				fim = mei - 1;
			}
			else return mei + 1;
		}
	}
	return ini;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	long long n;
	f();
	while(true){
		if(!(cin >> n)) return 0;
		if(n > 0) cout << get(n) << endl;
	}
}

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	while(true){
		int n, i, val;
		bool jolly = true;
		if(!(cin >> n)) return 0;
		if(n <= 0 || n > 3000) return 0;
		int sequencia[n];
		bool res[n-1];
		for(i = 0; i < n-1; i++){
			cin >> sequencia[i];
			res[i] = false;
		}cin >> sequencia[n-1];
		for(i = 0; i < n-1; i++){
			val = abs(sequencia[i]-sequencia[i+1]);
			if(val > n-1 || val == 0){
				jolly = false;
				break;
			}else if(res[val-1]){
				jolly = false;
				break;
			}else res[val-1] = true;
		}
		if(jolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
}

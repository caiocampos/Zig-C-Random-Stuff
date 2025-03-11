#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	int count = 1;
	while(true){
		int n, m, i, j;
		if(!(cin >> n >> m)) return 0;
		if(n <= 0 || m <= 0 || n > 100 || m > 100) return 0;
		if(count != 1) cout << endl;
		int matriz[n+2][m+2];
		char campo[n][m];
		for(i = 0; i < n+2; i++){
			for(j = 0; j < m+2; j++) matriz[i][j] = 0;
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(!(cin >> campo[i][j])) return 0;
				if(campo[i][j] == '*'){
					matriz[i][j]++;
					matriz[i+1][j]++;
					matriz[i+2][j]++;
					matriz[i][j+1]++;
					matriz[i+2][j+1]++;
					matriz[i][j+2]++;
					matriz[i+1][j+2]++;
					matriz[i+2][j+2]++;
				}
			}
		}
		cout << "Field #" << count << ':' << endl;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(campo[i][j] == '*') cout << '*';
				else cout << matriz[i+1][j+1];
			}
			cout << endl;
		}
		count++;
	}
}

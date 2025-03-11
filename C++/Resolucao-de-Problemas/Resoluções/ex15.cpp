#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long bishops(int,int);

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int n, m;
	while(true){
		if(!(cin >> n >> m)) return 0;
		if(n == 0 && m == 0) return 0;
		cout << bishops(n, m) << endl;
	}
}

long long bishops(int n, int m){
	int i,j;
	long long res, v1[9], v2[9];
	long long m1[9][65] = {{0}};
	long long m2[9][65] = {{0}};

	for(i = 1; i <= n; i++){
		if(i % 2 == 0) v1[i] = v1[i-1];
		else v1[i] = i;
	}
	for(i = 1; i <= n-1; i++){
		if(i % 2 == 0) v2[i] = v2[i-1];
		else v2[i] = i+1;
	}
	m1[n][0] = 1;
	for(i = 0; i <= n-1; i++) m1[i][0] = m2[i][0] = 1;
	for(i = 1; i <= m; i++) m1[0][i] = m2[0][i] = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m && j <= i; j++){
			m1[i][j] = m1[i-1][j] + m1[i-1][j-1]*(v1[i] - j + 1);
		}
	}
	for(i = 1; i <= n-1; i++){
		for(j = 1; j <= m && j <= i; j++){
			m2[i][j] = m2[i-1][j] + m2[i-1][j-1]*(v2[i] - j + 1);
		}
	}
	for(i = 0, res = 0; i <= m; i++){
		res += m1[n][i] * m2[n-1][m-i];
	}
	return res;
}

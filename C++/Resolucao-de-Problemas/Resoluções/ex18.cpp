#include <iostream>
#include <cstdio>

using namespace std;

struct Pos{int lin; int col;} vm[501][501];
int fm[501][501], am[501][501];
string lado[6] = {"front","back","left","right","top","bottom"};
int testCase, n;

void imprimir_lado(int,int);
void exec();

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int i, j;
	testCase = 1;
	while((cin >> n) && n){
		for(i = 1; i <= n; i++){
			for(j = 0; j < 6; j++) cin >> am[i][j];
		}
		if(testCase > 1) cout << endl;
		exec();
	}
}

void imprimir_lado(int lin, int col){
	int g;
	if(vm[lin][col].lin == -1){
		g = col + 1;
		if(col % 2) g = col - 1;
		cout << lin << " " << lado[g] << endl;
		return;
	}
	imprimir_lado(vm[lin][col].lin,vm[lin][col].col);
	g = col + 1;
	if(col % 2) g = col - 1;
	cout << lin << " " << lado[g] << endl;
}

void exec(){
	int max, rp, cp, rst, cst;
	int i, j, k, l, m;
	int  maior = 0;
	for(i = 1; i <= n; i++){
		for(j = 0; j < 6; j++){
			rp = cp = -1;
			max = 0;
			for(k = i - 1; k >= 0; k--){
				for(l = 0; l < 6; l ++){
					if(fm[k][l] > max){
						if(am[i][j] == am[k][l]){
							rp = k;
							cp = l;
							max = fm[k][l];
						}
					}
				}
			}
			m = j + 1;
			if(j % 2) m = j - 1;
			fm[i][m] = max + 1;
			vm[i][m].lin = rp;
			vm[i][m].col = cp;
			if(fm[i][m] > maior){
				maior = fm[i][m];
				rst = i;
				cst = m;
			}
		}
	}
	cout << "Case #" << testCase << endl;
	testCase++;
	cout << maior << endl;
	imprimir_lado(rst,cst);
}

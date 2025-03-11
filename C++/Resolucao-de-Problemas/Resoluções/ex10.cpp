#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
double lb(double);

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int num, ind, pot;
	while(cin >> num){
		ind = 1;
		while(ind++){
			pot = ind * log10(2) - log10(num);
			if(pot <= log10(num) + 1){
				continue;
			}
			else if(ind >= lb(num) + pot * lb(10) && ind < lb(num + 1) + pot * lb(10)){
				cout << ind << endl;
				break;
			}
		}
	}
	return 0;
}

double lb(double val){
	return log(val) / log(2);
}

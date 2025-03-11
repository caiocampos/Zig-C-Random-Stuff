#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	int n;
	int cn[] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
	while(true){
		if(!(cin >> n)) return 0;
		if(n == 0) break;
		else if(binary_search(cn,cn + sizeof(cn)/sizeof(int), n)){
			cout << "The number " << n << " is a Carmichael number." << endl;
		}
		else cout << n << " is normal." << endl;
	}
}

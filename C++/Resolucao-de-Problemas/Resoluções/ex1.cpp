#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	while(true){
		int64_t i, j, n, r, c, cr = 0, v1, v2;
		if(!(cin >> v1 >> v2)) return 0;
		if(v1 < v2){
			i = v1;
			j = v2;
		}else{
			i = v2;
			j = v1;
		}
		for(n = i; n <= j; n++){
			r = n;
			for(c = 1; r != 1 ; c++){
				if(r % 2 == 0) r /= 2;
				else r = 3 * r + 1;
			}
			if(cr < c) cr = c;
		}
		cout << v1 << ' ' << v2 << ' ' << cr << endl;
	}
}

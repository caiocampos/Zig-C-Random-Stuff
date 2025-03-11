#include <iostream>
#include <cstdio>

using namespace std;

unsigned int inverte(unsigned int val){
	unsigned int res = 0, aux = val%10;
	while(val){
		res = res * 10 + aux;
		val /= 10;
		aux = val%10;
	}
	return res;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	unsigned int testCases, i, num, result;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		cin >> num;
		for(i = 0, result = num, num = inverte(result); num != result; i++){
			result += num;
			num = inverte(result);
		}
		cout << i << " " << result << endl;
	}
}

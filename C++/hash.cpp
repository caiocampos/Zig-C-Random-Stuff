#include <iostream>

using namespace std;

int main(){
	string palavra;

	cin >> palavra;

	unsigned long long val = palavra[0];

	for(int i = 1; i <= palavra.size(); i++){
		val += palavra[i] * palavra[i-1];
	}

	cout << val << endl;
	return 0;
}

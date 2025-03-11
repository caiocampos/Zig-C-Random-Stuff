#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc , char *argv[]){
	const char back = '\b';
	const int pausa = int(3.5E7), mod(4), max(49);
	int i, j, m;
	cout << ' ';
	for(i = 0; i < max; i++) {
		m = i % mod;
		switch(m) {
			case 0: cout << back << '|';
					break;
			case 1:	cout << back << '/';
					break;
			case 2:	cout << back << '-';
					break;
			case 3: cout << back << '\\';
		}
		for(j = 0; j < pausa; j++);
	}
	cout << endl << "Pressione Enter" << endl;
    getchar();
	return 0;
}

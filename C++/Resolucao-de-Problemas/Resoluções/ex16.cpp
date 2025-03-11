#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

bool tGofE(int);
bool t(int);

char b[40];
int a[40],f[10],A[40],n;
int d[10][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};


int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int s;
	while(true){
		if(!(cin >> s >> n >> b+1)) return 0;
		if(tGofE(s)) cout << "GARDEN OF EDEN" << endl;
		else cout << "REACHABLE" << endl;
	}
}

bool tGofE(int k){
	int i;
	bool res;
	for(i = 1; i <= n; i++) a[i] = b[i] - '0';
	for(i = 0; i < 8; i++){
		f[i] = k % 2;
		k /= 2;
	}
	res = true;
	for(i = 0; i < 8; i++){
		if(a[1] == f[i]){
			A[0] = d[i][0];
			A[1] = d[i][1];
			A[2] = d[i][2];
			A[n] = A[0];
			A[n+1] = A[1];
			if(t(2)){
				res = false;
				break;
			}
		}
	}
	return res;
}

bool t(int val){
	int i, j;
	if(val == n - 1 || val == n){
		for(i = 0; i < 8; i++){
			if(f[i] == a[val] && d[i][0] == A[val-1] && d[i][1] == A[val] && d[i][2] == A[val+1]){
				if(val == n - 1 && !t(val + 1)) return false;
				else return true;
			}
		}
	}else{
		for(i = 0; i < 8; i++){
			if(f[i] == a[val] && d[i][0] == A[val-1] && d[i][1] == A[val]){
				A[val+1] = d[i][2];
				if(t(val + 1)) return true;
            }
		}
    }
    return 0;
}

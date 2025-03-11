#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int inicial[4];
int final[4];
vector<int> proibidos;

bool ivals(int[]);
bool ovals(int[]);
int join(int[]);
void split(int,int[]);
int get_pro(int);
int get_ant(int);
vector<int> adj(int[]);
int exec();

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int testCases, n, i, *aux;
	if(!(cin >> testCases)) return -1;
	while(testCases--){
		cin.ignore(160, '\n');
		if(!ivals(inicial)) return -1;
		if(!ivals(final)) return -1;
		if(!(cin >> n)) return -1;
		proibidos.clear();
		for(i = 0; i < n; i++){
			aux = new int[4];
			if(!ivals(aux)) return -1;
			proibidos.push_back(join(aux));
		}
		cout << exec() << endl;
	}
	return 0;
}

bool ivals(int n[4]){
	return cin >> n[0] >> n[1] >> n[2] >> n[3];
}

bool ovals(int n[4]){
	return cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
}

int join(int n[4]){
	int v = 0;
	v += n[0] * 1000;
	v += n[1] * 100;
	v += n[2] * 10;
	v += n[3];
	return v;
}

void split(int v, int n[4]){
	n[0] = v / 1000;
	v %= 1000;
    n[1] = v / 100;
    v %= 100;
    n[2] = v / 10;
    v %= 10;
    n[3] = v;
}

int get_pro(int n){
	n++;
	if(n > 9) n = 0;
	return n;
}

int get_ant(int n){
	n--;
	if(n < 0) n = 9;
	return n;
}

vector<int> adj(int v[4]){
	vector<int> adj;
	int i, *aux1, *aux2;
	for(i = 0; i < 4; i++){
		aux1 = new int[4];
		aux2 = new int[4];
		for(int j = 0; j < 4; j++) aux1[j] = aux2[j] = v[j];
		aux1[i] = get_ant(v[i]);
		aux2[i] = get_pro(v[i]);
		adj.push_back(join(aux1));
		adj.push_back(join(aux2));
	}
	return adj;
}

int exec(){
	int i;
    queue<int> fila;
    int ini = join(inicial);
    int fin = join(final);
    int visitados[10000];
    memset(visitados,-1,sizeof(visitados));
    fila.push(ini);
    visitados[ini] = 0;
    for(i = 0; i < proibidos.size(); i++){
		visitados[proibidos[i]] = 0;
    }
    while(!fila.empty()){
        int v = fila.front();
        int aux[4];
        split(v,aux);
        vector<int> adjs = adj(aux);
        fila.pop();
        if(v == fin) return visitados[fin];
        for(i = 0; i < adjs.size(); i++) {
            if(visitados[adjs[i]] != -1) continue;
            visitados[adjs[i]] = visitados[v] + 1;
            fila.push(adjs[i]);
        }
    }
	return -1;
}

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct point {
    double x;
    double y;
    point() {
		x = y = 0;
    }
    point(double nx, double ny) {
    	x = nx;
    	y = ny;
	}
};

bool verify(int a, int b, vector<point> c) {
    int lc, lcPos, lcNeg, i;
    for(i = 0, lcPos = lcNeg = 0; i < c.size(); i++) {
        lc = c[i].x * a + c[i].y * b;
        if(lc < 0) lcNeg++;
        else if(lc > 0) lcPos++;
        else return false;
    }
    return lcPos == lcNeg;
}

pair<int,int> test(vector<point> c) {
    double aux;
	int a, b, max = 500;
	for(a = -max; a <= max; a++) {
        for(b = -max; b <= max; b++) {
            if(verify(a,b,c)) return pair<int,int>(a,b);
        }
    }
    return pair<int,int>(501,501);
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    int nCherries, i;
	vector<point> cherries;
	double auxX, auxY;
    while(cin >> nCherries) {
        if(!nCherries) return 0;
		cherries.clear();
		for(i = nCherries * 2; i > 0; i--) {
			cin >> auxX >> auxY;
			cherries.push_back(point(auxX,auxY));
		}
		pair<int,int> res = test(cherries);
		if(res.first > 500 && res.second > 500) continue;
		else cout << res.first << " " << res.second << endl;
    }
    return 0;
}

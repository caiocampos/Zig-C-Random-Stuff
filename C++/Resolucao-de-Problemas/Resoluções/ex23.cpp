#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <cmath>

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

bool escape(point g, point d, point h) {
	double dGopher = sqrt(pow(g.x - h.x, 2) + pow(g.y - h.y, 2));
	double dDog = sqrt(pow(d.x - h.x, 2) + pow(d.y - h.y, 2));
	return 2.0 * dGopher - dDog <= 0;
}

int test(point g, point d, vector<point> h) {
	double aux;
	int i;
	for(i = 0; i < h.size(); i++) {
		if(escape(g,d,h[i])) return i;
	}
	return -1;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    int nHoles, i, res;
	point dogPos, gopherPos;
	vector<point> holes;
	double dogPosX, dogPosY, gopherPosX, gopherPosY, auxX, auxY;
    while(cin >> nHoles >> gopherPosX >> gopherPosY >> dogPosX >> dogPosY) {
		holes.clear();
		for(i = nHoles; i > 0; i--) {
			cin >> auxX >> auxY;
			holes.push_back(point(auxX,auxY));
		}
		res = test(point(gopherPosX,gopherPosY), point(dogPosX,dogPosY), holes);
		if(res == -1) cout << "The gopher cannot escape." << endl;
		else cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << holes[res].x << "," << holes[res].y << ")." << endl;
    }
    return 0;
}

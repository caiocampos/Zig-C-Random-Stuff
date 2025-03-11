#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double sq3 = sqrt(3);

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

point find_point(long long n){
    long long sqrtN, rest;
	point p;
	n++;
    sqrtN = sqrt(n);
	if(pow(sqrtN,2) < n) sqrtN++;
    rest = n - pow(sqrtN - 1, 2);
    p.x = (rest - sqrtN) / 2.0;
    p.y = (sq3/2) * (sqrtN - 1) + ((rest & 1) ? (sq3 / 3) : (sq3 / 6));
	return p;
}

double get_distance(long long n1, long long n2) {
	point p1 = find_point(n1);
	point p2 = find_point(n2);
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    long long n1, n2;
    while(cin >> n1 >> n2){
        cout << fixed << setprecision(3) << get_distance(n1,n2) << endl;
    }
    return 0;
}

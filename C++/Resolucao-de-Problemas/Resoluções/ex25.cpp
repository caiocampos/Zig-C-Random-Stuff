#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

struct point {
    double x;
    double y;
    point() {
		x = y = 0.0;
    }
    point(double nx, double ny) {
    	x = nx;
    	y = ny;
	}
};
typedef vector<point> polygon;

double get_distance(point p1, point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double get_cross_product(point p1, point p2, point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double perimeter(polygon frosh) {
	double length = 0.0;
	int i, j;
	for(i = 0; i < frosh.size(); i++) {
		j = (i + 1) % frosh.size();
		length += get_distance(frosh[i], frosh[j]);
	}
	return length;
}

bool comp_pos(point p1, point p2) {
	if(p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}

bool comp_angle(point p1, point p2) {
	if(p1.y == 0 && p2.y == 0 && p1.x * p2.x <= 0) return p1.x > p2.x;
	if(p1.y == 0 && p1.x >= 0 && p2.y != 0) return true;
	if(p2.y == 0 && p2.x >= 0 && p1.y != 0) return false;
	if(p1.y * p2.y < 0) return p1.y > p2.y;
	double cp = get_cross_product(point(), p1, p2);
	return cp > 0 || (cp == 0 && fabs(p1.x) < fabs(p2.x));
}

double min_perimeter(polygon in) {
	double length = 1e20;
	int i, top, cur, pos = 0;
	sort(in.begin(), in.end(), comp_pos);
	for(i = 0; i < in.size(); i++) {
		if (in[i].x == 0 && in[i].y == 0) continue;
		if(pos == 0) in[pos++] = in[i];
		else if(in[pos - 1].x == in[i].x && in[pos - 1].y == in[i].y) continue;
		else in[pos++] = in[i];
	}
	in = polygon(in.begin(), in.begin() + pos);
	sort(in.begin(), in.end(), comp_angle);
	point out[1010];
	for(i = 0; i < in.size(); i++) {
		top = 1;
		cur = i + 1;
		out[0] = point();
		out[1] = in[i];
		while(cur < (i + in.size())) {
			if(top >= 1 && get_cross_product(out[top - 1], out[top], in[cur % in.size()]) <= 0) top--;
			else {
				top++;
				out[top] = in[cur % in.size()];
				cur++;
			}
		}
		top++;
		out[top] = in[(i - 1 + in.size()) % in.size()];
		length = min(length, perimeter(polygon(out,out+top)));
	}
	return length;
}

polygon convex_polygon(polygon frosh) {
	if(frosh.size() <= 3) return frosh;
	sort(frosh.begin(), frosh.end(), comp_pos);
	point upPoints[1010], lowPoints[1010];
	int i, top;
	upPoints[0] = frosh[0];
	upPoints[1] = frosh[1];
	for(i = 2, top = 2; i < frosh.size(); i++, top++) {
		upPoints[top] = frosh[i];
		while (top >= 2 && get_cross_product(upPoints[top-2],upPoints[top-1],upPoints[top]) >= 0) {
			upPoints[top-1] = upPoints[top];
			top--;
		}
	}
	polygon res;
	for(i = 0; i < top; i++) res.push_back(upPoints[i]);
	lowPoints[0] = frosh[frosh.size()-1];
	lowPoints[1] = frosh[frosh.size()-2];
	for(i = frosh.size() - 3, top = 2; i >= 0; i--, top++) {
		lowPoints[top] = frosh[i];
		while(top >= 2 && get_cross_product(lowPoints[top-2], lowPoints[top - 1], lowPoints[top]) >= 0) {
			lowPoints[top-1] = lowPoints[top];
			top--;
		}
	}
	for(i = 1; i < top - 1; i++) res.push_back(lowPoints[i]);
	return res;
}

double test(polygon frosh) {
    polygon cpFrosh = convex_polygon(frosh);
    int i, j;
    for(i = 0; i < cpFrosh.size(); i++) {
        j = (i + 1) % cpFrosh.size();
        if(fabs(get_cross_product(point(), cpFrosh[i], cpFrosh[j])) <= (1e-9)) {
            return perimeter(cpFrosh) + 2.0;
        }
    }
    return min_perimeter(frosh) + 2.0;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    polygon frosh;
    double xAux,yAux, tCases, n;
    int i;
    cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
    cin >> tCases;
    while(tCases--) {
        cin.ignore(80, '\n');
        if(!(cin >> n)) return 0;
    	frosh.clear();
        frosh.push_back(point());
		for(i = n; i > 0; i--) {
			cin >> xAux >> yAux;
			frosh.push_back(point(xAux,yAux));
		}
		cout << test(frosh) << endl;
		if(tCases) cout << endl;
    }
    return 0;
}

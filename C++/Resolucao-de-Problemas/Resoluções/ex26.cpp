#include <iostream>
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

double get_distance(point p1, point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double get_cross_product(point p1, point p2, point p3) {
	return (p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x);
}

point foot_line(point p1, point p2, point p3) {
	return point(p1.x - p3.y + p2.y, p1.y + p3.x - p2.x);
}

point l2l_inst_p(point p1, point p2, point p3, point p4) {
	double t(((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x)));
	return point(p1.x + (p2.x - p1.x) * t,p1.y + (p2.y - p1.y) * t);
}

double area_polygon(vector<point> v) {
	int i, j;
	double s(0.0);
	for(i = 0; i < v.size()-1; i++) {
		j = (i + 1) % v.size()-1;
		s += v[j].y * v[i].x - v[j].x * v[i].y;
	}
	return fabs(s / 2.0);
}

vector<point> cut_hp(point p1, point p2, vector<point> s) {
	int i, j;
	vector<point> res;
	for(i = 0; i < s.size(); i++) {
		if(get_cross_product(p1,p2,s[i]) <= 0.0) res.push_back(s[i]);
		if(get_cross_product(p1,p2,s[i]) * get_cross_product(p1,p2,s[i+1]) < 0.0) {
			res.push_back(l2l_inst_p(p1,p2,s[i],s[i+1]));
		}
	}
	res.push_back(res[0]);
	return res;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    vector<point> points;
	point p1, p2, p3, p4;
    double area(1.0);
	string status;
    int i;
    cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	points.push_back(point(00.0,00.0));
	points.push_back(point(10.0,00.0));
	points.push_back(point(10.0,10.0));
	points.push_back(point(00.0,10.0));
	points.push_back(point(00.0,00.0));
    while(cin >> p1.x >> p1.y >> status) {
		p2.x = (p3.x + p1.x) / 2.0;
		p2.y = (p3.y + p1.y) / 2.0;
		if(!status.compare("Same")) area = 0.0;
		if(!area) {
			cout << 0.0 << endl;
			p3 = p1;
			continue;
		}
		if(!status.compare("Colder")) {
			p4 = foot_line(p2,p3,p1);
		}
		if(!status.compare("Hotter")) {
			p4 = p2;
			p2 = foot_line(p4,p3,p1);
		}
		p3 = p1;
		points = cut_hp(p2,p4,points);
		if(points.size() < 2) {
			cout << 0.0 << endl;
			continue;
		}
		area = area_polygon(points);
		cout << area << endl;
	}
    return 0;
}

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dirY[] = {-1,0,1,0};
int dirX[] = {0,-1,0,1};
int sizeY, sizeX;
string cMap[30];
int vMap[30][30][5];

struct position {
    int x;
    int y;
    int cost;
    int color;
    int dir;
	position() {
		cost = dir = x = y = color = 0;
	}
    position(int nx, int ny, int c, int col, int d) {
        x = nx;
        y = ny;
        cost = c;
        color = col;
        dir = d;
    }
	bool operator>(position p) const {
        return p.cost > cost;
    }
    bool operator<(position p) const {
        return p.cost < cost;
    }
};

int calc_cost(int v1,int v2) {
    int res = v1 - v2;
	res = res >= 0 ? res : -res;
	res = res == 3 ? 1 : res;
    return res;
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

    int i,j;
	for(int count = 1;; count++) {
		if(!(cin >> sizeY >> sizeX)) return 0;
		if(sizeY == 0 && sizeX == 0) return 0;
		if(count != 1) cout << endl;
		cout << "Case #" << count << endl;
        memset(vMap,0,sizeof(vMap));
        cin.ignore(80, '\n');
		for(i = 0; i < sizeY; i++) getline(cin,cMap[i]);
        int startX = -1, startY = -1;
        for(i = 0; startY == -1 && i < sizeY; i++) {
        	for(j = 0; startX == -1 && j < sizeX; j++) {
        		if(cMap[i][j] == 'S') {
        			startX = i;
        			startY = j;
				}
        	}
        }
        int finalCost = -1;
        priority_queue<position> posQueue;
        posQueue.push(position(startX,startY,0,0,1));
        while(!posQueue.empty()) {
            position p = posQueue.top();
			posQueue.pop();
            if(vMap[p.x][p.y][p.color] && p.cost > vMap[p.x][p.y][p.color]) continue;
            vMap[p.x][p.y][p.color] = p.cost;
            if(cMap[p.x][p.y] == 'T' && p.color == 0) {
				finalCost = p.cost;
				break;
			}
            for(i = 0; i < 4; i++) {
                int nx = p.x + dirX[i], ny = p.y + dirY[i];
                if(nx >= sizeY || nx < 0 || ny >= sizeX || ny < 0) continue;
                if(cMap[nx][ny] == '#') continue;
                posQueue.push(position(nx, ny, p.cost + 1 + calc_cost(i,p.dir), (p.color + 1) % 5, i));
            }
        }
        if(finalCost == -1) cout << "destination not reachable" << endl;
        else cout << "minimum time = " << finalCost << " sec" << endl;
	}
    return 0;
}


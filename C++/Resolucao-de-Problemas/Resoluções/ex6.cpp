#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

void find(vector<string>, string, pair<int,int>&);
bool compare_str(string, string);
bool compare_str(char, char);
vector<string> cut_str(vector<string>, pair<int,int>);

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	vector<string> linhas;
	vector<pair<int,int> > positions;
	pair<int,int> pos;
	int testCases, num_linhas, num_palavras, num_colunas;
	string linha;
	if(!(cin >> testCases)) return 0;
	while(testCases--){
		int i;
		linhas.clear();
		positions.clear();
		if(!(cin >> num_linhas)) return 0;
		if(!(cin >> num_colunas)) return 0;

		for(i = 0; i < num_linhas; i++){
			cin >> linha;
			linhas.push_back(linha);
		}
		cin >> num_palavras;
		for(i = 0; i < num_palavras; i++){
			cin >> linha;
			find(linhas,linha,pos);
			positions.push_back(pos);
		}
		for(i = 0; i < num_palavras; i++){
			cout << positions[i].first + 1 << " " << positions[i].second + 1 << endl;
		}
		if(testCases) cout << endl;
	}
	return 0;
}

void find(vector<string> linhas, string base, pair<int,int>& pos){
	int i, j, k;
	string linha;
	vector<string> tests;
	for(i = 0; i < linhas.size(); i++){
		linha = linhas[i];
		for(j = 0; j < linha.size(); j++){
			if(compare_str(base[0], linha[j])){
				pos = pair<int, int>(i,j);
				tests = cut_str(linhas, pos);
				for(k = 0; k < tests.size(); k++){
					if(compare_str(base, tests[k])) return;
				}
			}
		}
	}
}

vector<string> cut_str(vector<string> linhas, pair<int,int> pos){
	string test;
	vector<string> generated;
	int pos_x, pos_y;

	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != 0){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y--;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != 0 && pos_x != linhas[pos_y].size()){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y--;
		pos_x++;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_x != linhas[pos_y].size()){
		test.push_back(linhas[pos_y][pos_x]);
		pos_x++;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != linhas.size() && pos_x != linhas[pos_y].size()){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y++;
		pos_x++;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != linhas.size()){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y++;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != linhas.size() && pos_x != 0){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y++;
		pos_x--;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_x != 0){
		test.push_back(linhas[pos_y][pos_x]);
		pos_x--;
	}
	generated.push_back(test);

	test.clear();
	pos_y = pos.first;
	pos_x = pos.second;
	while(pos_y != 0 && pos_x != 0){
		test.push_back(linhas[pos_y][pos_x]);
		pos_y--;
		pos_x--;
	}
	generated.push_back(test);

	return generated;
}

bool compare_str(string base, string test){
	int i;
	if(base.size() > test.size()) return false;
	for(i = 0; i < base.size(); i++){
		if(!compare_str(base[i],test[i])) return false;
	}
	return true;
}

bool compare_str(char base_char, char test_char){
	if(isupper(base_char)) base_char = tolower(base_char);
	if(isupper(test_char)) test_char = tolower(test_char);
	return base_char == test_char;
}

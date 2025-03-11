#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>

#define max 50000

using namespace std;

struct factor {
    int prime, count;
    factor(int p, int c){
		prime = p;
		count = c;
	}
};

vector<int> primos;
bool divides_factorial(int,int);
bool test_primo(int);
void gerar_primos();
int get_powers(unsigned long,int);

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif

	int n, m;
	gerar_primos();
	while(true){
		if(!(cin >> n >> m)) return 0;
		if(divides_factorial(n,m)){
			cout << m << " divides " << n << "!" << endl;
        }
        else cout << m << " does not divide " << n << "!" << endl;
	}
}

bool divides_factorial(int n, int m){
    if(m == 0) return false;
    else if(n >= m) return true;
    else{
        int k = m;
        vector<factor> factors;
        for(int i = 0; i < primos.size(); i++) {
            if (primos[i] > k) break;
            else{
                factor f(primos[i],0);
                while(k % primos[i] == 0){
                    f.count += 1;
                    k = k / primos[i];
                }
                if(f.count){
                    factors.push_back(f);
                }
            }
        }
        if(k > 1){
            if(n < k) return false;
            else factors.push_back(factor(k,1));
        }
        for(int i = 0; i < factors.size(); i++){
            if(factors[i].count - get_powers(n,factors[i].prime) > 0){
                return false;
            }
        }
        return true;
    }
}

bool test_primo(int n){
    for(int i = 2; i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

void gerar_primos(){
    for(int i = 2; i < max; i++){
        if(test_primo(i)){
            primos.push_back(i);
        }
    }
}

int get_powers(unsigned long n, int p)
{
    int res = 0;
    for(int power = p ; power <= n ; power *= p){
        res += n/power;
    }
    return res;
}

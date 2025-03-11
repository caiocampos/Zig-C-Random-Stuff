#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void rand(int seed, int n) {
    int i, aux;
    div_t res;
    string s;
    cout << "gerando..." << endl;
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        cout << "progresso: " << i * 100.0 / (double)n << "%..." << endl;
        seed = rand() % (seed + 100);
        Sleep(seed);
        srand(time(NULL));
        res = div(rand(), seed);
        aux = res.rem % 94 + 33;
        seed = res.quot;
        s += char(aux);
    }
    cout << "progresso: 100%!!!" << endl;
    cout << "resultado: " << s << endl;
}

int main() {
    int n, seed;
    cout << "Numero de elementos: ";
    cin >> n;
    cout << "Numero semente: ";
    cin >> seed;
    rand(seed, n);
    system("pause");
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	vector<unsigned int> val;
	unsigned int i;
    for(i = 0, srand(time(NULL)); i < 32; i++)
	{
		val.push_back(rand());
    	srand(val.back());
    }
    cout << "random numbers:" << endl;
    for(i = 0; i < val.size(); i++)
		cout << i + 1 << ": " << val[i] << endl;
}

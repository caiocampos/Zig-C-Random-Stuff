#include <iostream>
#include <Python.h>

using namespace std;

int main(int argc, char *argv[])
{
	Py_Initialize();
	string s;
	while(true)
	{
		cout << ">> ";
		getline(cin,s);
		PyRun_SimpleString(s.c_str());
	}
	Py_Finalize();
	return 0;
}

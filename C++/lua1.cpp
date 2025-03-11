#include <iostream>
#include <lua.hpp>

using namespace std;

int main(int argc, char *argv[])
{
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	string s;
	while(true)
	{
		cout << ">> ";
		getline(cin,s);
		luaL_dostring(L, s.c_str());
		lua_tostring(L, -1);
	}
	lua_close(L);
	return 0;
}

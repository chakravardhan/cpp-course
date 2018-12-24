#include <iostream>
#include "Server.h"
using namespace std;
int main()
{
	string a;
	cin>>a;
	Server s;
	folder f1;
	f1.pushFile();
	s.searchFile(a);
	

}
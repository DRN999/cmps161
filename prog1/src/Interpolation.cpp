#include <iostream>
#include <string>
#include "file_input.h" 
using namespace std;

int main()
{
	string s;
	cout << "type in the name of the file you want to convert to vtk with interpolation: ";
	cin >> s; 
	file_input* file = new file_input(s);
	file->close_file();
	delete(file);
	return 0;
}


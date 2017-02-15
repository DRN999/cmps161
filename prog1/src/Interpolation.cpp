#include <iostream>
#include <string>
#include "file_input.h" 
#include "cell_grid.h"

using namespace std;

int main()
{
	string s;
	cout << "type in the name of the file you want to convert to vtk with interpolation: ";
	cin >> s; 
	file_input* file = new file_input(s);
	cell_grid* grid = file->create_vtk();
	file->close_file();
	delete(file);
	return 0;
}


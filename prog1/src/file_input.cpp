#include <iostream>
#include "file_input.h"

file_input::file_input()
{
	
}

file_input::file_input(string name)
{
	file = new fstream();
	file->open(name, ios::in);
	parse_file();
}

void file_input::parse_file()
{
	if(file->is_open())
	{
		*file >> dimension;
		*file >> n;
		*file >> m;
		float temp_f = 0;
		for(int i = 0; i < n + 1; ++i)
		{
			if(i == n)
			{
				for(int j = 0; j < dimension; ++j)
				{
					*file >> temp_f;
					res.push_back((int)temp_f);
				}
			}
			else 
			{
				for(int j = 0; j < m + dimension; ++j)
				{
					*file >> temp_f;
					if(j < m)
						values.push_back(temp_f);
					else
						coordinates.push_back((int)temp_f);
									
				}
			}
		}
	} // end if file.is_open() 
	cout << endl << "dimension: " << dimension << endl;
	cout << endl << "n: " << n << " m: " << m << endl;
	cout << endl << "values :" << endl;
	for(vector<float>::const_iterator i = values.begin(); i != values.end(); ++i)
		cout << *i << endl;
	
	cout << endl << "coordinates: " << endl;
	int check = 0;
	for(vector<int>::const_iterator i = coordinates.begin(); i != coordinates.end(); ++i)
	{
		++check;
		cout << *i << " ";
		if(check%dimension == 0)
			cout << endl;
	}
	cout << endl << "res: " << endl;
	for(vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
		cout << *i << endl;
	cout << endl;
	
}// End parse_file 

void file_input::close_file()
{
	if(file->is_open())
	{
		file->close();
		delete(file);
	}
}

void file_input::open_file(string name)
{
	file = new fstream();
	file->open(name, ios::in);
	parse_file();
}

void file_input::create_vtk()
{
	if(file->is_open())
	{
		cout << "i dunno what to do LUL" << endl;
	}
}


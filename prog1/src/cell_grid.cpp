#include <iostream> 
#include "cell_grid.h"
#include <cstdarg>

cell_grid::cell_grid(int d, int* r)
{
	dimension = d;
	res = r;
	size = res[0];
	for(int i = 1; i < dimension; ++i)
	{
		size *= res[i];
	}
	grid = new cell*[size];
	for(int i = 0; i < size; i++)
		grid[i] = new cell();
}

int cell_grid::index(int x, int y)
{ // returns the proper index of the table for 2d 
	return x + res[0] * y;
}

int cell_grid::index(int x, int y, int z)
{ // returns the proper index of the table for 3d 
	return x + res[0] * y + res[0] * res[1] * z;
}

void cell_grid::interpolate_grid()
{
	
}

cell* cell_grid::get_cell(int x, int y) 
{// returns the cell of the index for 2d 
	return grid[index(x, y)];
}// End get_cell 

cell* cell_grid::get_cell(int x, int y, int z)
{// returns the cell of the index for 3d 
	return grid[index(x, y, z)];
}// End get_cell 

vector<double>* cell_grid::get_cell_value(int x, int y)
{// returns the value inside the cell for 2d
	return grid[index(x,y)]->get_value();
}// get_cell_value 

vector<double>* cell_grid::get_cell_value(int x, int y, int z)
{// returns the value inside the cell for 3d
	return grid[index(x, y, z)]->get_value();
}// End get_cell_value 

void cell_grid::set_cell(int x, int y, int num, ...)
{// sets cell value of index for 2d 
	va_list ap;
	va_start(ap, num);
	vector<double> a;
	for(int i = 0; i < num; ++i)
	{
		a.push_back(va_arg(ap, double));
	}
	va_end(ap);
	set_cell(x, y, &a);
}// End set_cell 

void cell_grid::set_cell(int x, int y, vector<double>* val)
{// .. 
	grid[index(x, y)]->set_value(val);
}// End set_cell 

void cell_grid::set_cell(int x, int y, int z, int num, ...)
{// sets cell value of index for 3d 
	va_list ap;
	va_start(ap, num);
	vector<double> a;
	for(int i = 0; i < num; ++i)
	{
		a.push_back(va_arg(ap, double));
	}
	va_end(ap);
	set_cell(x, y, z, &a);
}// End set_cell 

void cell_grid::set_cell(int x, int y, int z, vector<double>* val)
{// .. 
	grid[index(x, y, z)]->set_value(val);
}// End set_cell 

#include <vector> 
#include "cell.h"

#ifndef CELL_GRID 
#define CELL_GRID


class cell_grid
{
	private:
		cell* grid; // array of grid 
		int dimension; // the dimension of the array
		int size; // size of grid 
		int* res; // the resolution of each axis 
		int index(int x, int y); // returns the proper index of the table for 2d 
		int index(int x, int y, int z); // returns the proper index of the table for 3d 
		
	public: 
		cell_grid(int d, int* r); //creates a grid with the following dimension and resolution 
		cell* get_cell(int x, int y); // returns the cell of the index for 2d 
		cell* get_cell(int x, int y, int z); // returns the cell of the index for 3d 
		vector<float>* get_cell_value(int x, int y); // returns the value inside the cell for 2d
		vector<float>* get_cell_value(int x, int y, int z); // returns the value inside the cell for 3d
		void interpolate_grid(); // interpolates grid according to the orginal inputs 
		void set_cell(int x, int y, int num, ...); // sets cell value of index for 2d 
		void set_cell(int x, int y, vector<float>* val); // .. 
		void set_cell(int x, int y, int z, int num, ...); // sets cell value of index for 3d 
		void set_cell(int x, int y, int z, vector<float>* val); // .. 
};


#endif
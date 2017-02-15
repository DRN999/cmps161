#include <iostream> 
#include "cell.h" 
#include <cstdarg>

cell::cell()
{// creates empty cell 
	cell_size = 0;
	orig = 0;
}// End empty Constructor 

cell::cell(int o, int num, ...)
{// creates cell with some number of arguments 
	orig = o;
	va_list ap;
	va_start(ap, num);
	cell_size = 0;
	for(int i = 0; i < num; ++i)
	{
		value->push_back(va_arg(ap, double));
		++cell_size;
	}
	va_end(ap);
}// End Constructor 

vector<double>* cell::get_value()
{// returns vector
	return value;
}// End get_value 

int cell::get_size()
{// returns the size 
	return cell_size;
}// End get_size 

int cell::is_empty()
{// returns if the value vector is empty 
	return ((cell_size == 0) ? 1:0);
}// End is_empty 

int cell::is_orig()
{// returns if the cell is one of the original points that are to be interpolated 
	return orig;
}// End is_orig

void cell::add_value(vector<double>* a)
{// concatnates the input vector with current vector
	value->insert(value->end(), a->begin(), a->end());
}// End add_value 

void cell::set_value(vector<double>* a)
{// sets the current vector to input vector  
	value = a;
}// End set_value 

void cell::set_orig()
{// set orig to true 
	orig = 1;
}// End set_orig 



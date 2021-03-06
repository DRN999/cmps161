#include <vector>
using namespace std; 

#ifndef CELL
#define CELL

class cell
{
	private: 
		vector<double>* value;
		int cell_size;
		int orig;
		
	public:
		cell(); // creates empty cell 
		cell(int o, int num, ...); // creates cell with some number of arguments 
		vector<double>* get_value();// returns vector
		int get_size(); // returns the size 
		int is_empty(); // returns if the value vector is empty 
		int is_orig(); // returns if orig 
		void set_orig(); // change to orig 
		void add_value(vector<double>* a); // concatenates the input vector with current vector 
		void set_value(vector<double>* a); // sets the current vector to input vector  
		
};


#endif 

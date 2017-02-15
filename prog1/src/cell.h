#include <vector>
using namespace std; 

#ifndef CELL
#define CELL

class cell
{
	private: 
		vector<float> value;
		int cell_size;
		int orig;
		
	public:
		cell(); // creates empty cell 
		cell(int o, int num, ...); // creates cell with some number of arguments 
		vector<float>* get_value();// returns vector
		int get_size(); // returns the size 
		int is_empty(); // returns if the value vector is empty 
		int is_orig();
		void add_value(vector<float>* a); // concatenates the input vector with current vector 
		void set_value(vector<float>* a); // sets the current vector to input vector  
		
};


#endif 

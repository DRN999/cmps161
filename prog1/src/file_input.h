#include <fstream> 
#include <string>
#include <vector>

#ifndef FILE_INPUT
#define FILE_INPUT 

using namespace std;

class file_input 
{
	private: 
		fstream file; // the input file itself 
		int dimension; // dimensions of the data  
		int n, m; // the number of components and the number of coordinates per component 
		vector<float> values; // values of the coordinate(s) 
		vector<int> coordinates; // the coordinate values 
		vector<int> res;
		void parse_file();
		
	public:
		file_input(); // default constructor, does nothing 
		file_input(string name); // constructor with input file name 
		void close_file(); // close the file 
		void open_file(string name); // open the file with the same name 
		void create_vtk(); // exports a output vtk file 
}



#endif 
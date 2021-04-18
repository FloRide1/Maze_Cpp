#include "Color.hpp"
#include "Maze.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Maze maze(5);
	maze.genMazeByMergerMethod();

	// cout << maze.getprintableBeautifyContent();
	vector<unsigned int> my_path;
	my_path.push_back(13);
	my_path.push_back(12);
	my_path.push_back(23);

	string maze_print = maze.getcorrectedprintableBeautifyContent();
	cout << maze_print << endl;
	
	string maze_path_print = maze.getprintablePath(my_path);
	cout << maze_path_print;

	return 0;
}

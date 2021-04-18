#include "Maze.hpp"
#include <string>
#include <vector>


/**
 * Create an Null Maze (it mean nothing, just for avoiding bug)
 *
 */
Maze::Maze()
{
	type = Null;
}
/**
 * Create an Square Maze with a "size" columns and "size" rows
 *
 * @param size The size you want for your square maze (in height or width)
 */
Maze::Maze(unsigned int size)
{
	if (size == 0)
	{
		type = Null;
		return;
	}
	type = Square;
	width = size;
	height = size;
	makeBorder();
}

/**
 * Create an Rectangle Maze with a specified numbers of columns and rows
 *
 * @param width_size The numbers of columns you want for your maze
 * @param height_size The numbers of rows you want for your maze
 */
Maze::Maze(unsigned int width_size, unsigned int height_size)
{
	if (width_size == 0 || height_size == 0)
	{
		type = Null;
		return;
	}

	if (width_size == height_size)
	{
		type = Square;
	} 
	else 
	{
		type = Rectangle;
	}

	width = width_size;
	height = height_size;
	makeBorder();
}


/**
 * Fill your Maze with wall
 */
void Maze::fillMaze()
{
	if (type == Null)
	{
		return;
	}
	
	content = std::vector<bool> ((2 * height + 1) * (2 * width + 1));
	std::fill(content.begin(), content.end(), true);
}

void Maze::makeGrid()
{
	if (type == Null)
	{
		return;		
	}
	content = std::vector<bool> ((2 * height + 1) * (2 * width + 1));

	std::fill(content.begin(), content.end(), false);
	unsigned int i;
	for (i = 0; i < height + 1; i++)
	{
		std::fill(content.begin() + (2 * i) * (2 * width + 1), content.begin() + (2 * i + 1) * (2 * width + 1), true);
	}

	for (i = 0; i < width + 1; i++)
	{
		unsigned int j;
		for (j = 0; j < 2 * height + 1; j++)
		{
			content[2 * i + j * (2 * width + 1)] = true;
		}
 	}
}

void Maze::makeBorder()
{
	if (type == Null)
	{
		return;
	}

	content = std::vector<bool> ((2 * height + 1) * (2 * width + 1));
	std::fill(content.begin(), content.end(), false);

	// Top Border
	std::fill(content.begin(), content.begin() + (2 * width + 1), true);

	// Bottom Right:
	std::fill(content.end() - (2 * width + 1), content.end(), true);

	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		// Left Border
		if (i % (2 * width + 1) == 0)
		{
			content[i] = true;
		}
	
		// Right Border
		if (i % (2 * width + 1) == (2 * width))
		{
			content[i] = true;
		}
	}
}

void Maze::setWall(unsigned int index)
{
	if (type == Null)
	{
		return;
	}
	if (index >= content.size())
	{
		return;	
	}

	content[index] = true;
}

void Maze::setAir(unsigned int index)
{
	if (type == Null)
	{
		return;
	}
	if (index >= content.size())
	{
		return;	
	}

	content[index] = false;
}

/**
 * Return the width of the Maze
 */
unsigned int Maze::getWidth()
{
	return width;
}

/**
 * Return the height of the Maze
 */
unsigned int Maze::getHeight()
{
	return height;
}

/**
 * Return the type of te Maze
 */
MazeType Maze::getTypeOfMaze()
{
	return type;
}

/**
 * Return the content of te Maze
 */
std::vector<bool> Maze::getContent()
{
	return content;
}

unsigned char Maze::getConnectedEdge(unsigned int element_index)
{
	/// [Top, Bottom, Left, Right] -> 8 * Top + 4 * Bottom 2 + * Left + 1 * Right
	unsigned char total = 0;

	// Check Top:
	if (element_index >= (2 * width + 1))
	{
		if (content[element_index - (2 * width + 1)])
		{
			total += 1 * 8;
		}
	}

	// Check Bottom:
	if (element_index < (2 * height) * (2 * width + 1))
	{
		if (content[element_index + (2 * width + 1)])
		{
			total += 1 * 4;
		}
	}

	// Check Left:
	if (element_index % (2 * width + 1) != 0)
	{
		if (content[element_index - 1])
		{
			total += 1 * 2;
		}
	}

	// Check Right:
	if (element_index % (2 * width + 1) != (2 * width))
	{
		if (content[element_index + 1])
		{
			total += 1 * 1;
		}
	}
	return total;
}

unsigned char Maze::getPathConnectedEdge(unsigned int element_index, std::vector<unsigned int> path)
{
	unsigned char total = 0;

	if (element_index >= (2 * width + 1))
	{
		if (std::find(path.begin(), path.end(), element_index - (2 * width + 1)) != path.end())
		{
			total += 1 * 8;
		}
	}

	// Check Bottom:
	if (element_index < (2 * height) * (2 * width + 1))
	{
		if (std::find(path.begin(), path.end(), element_index + (2 * width + 1)) != path.end())
		{
			total += 1 * 4;
		}
	}

	// Check Left:
	if (element_index % (2 * width + 1) != 0)
	{
		if (std::find(path.begin(), path.end(), element_index - 1) != path.end())
		{
			total += 1 * 2;
		}
	}

	// Check Right:
	if (element_index % (2 * width + 1) != (2 * width))
	{
		if (std::find(path.begin(), path.end(), element_index + 1) != path.end())
		{
			total += 1 * 1;
		}
	}

	return total;
}

std::string Maze::getUnicodeEdge(unsigned char edge)
{
	switch (edge)
	{
		case 15: // [T,B,L,R]
			return "┼";
		case 14: // [T,B,L,0]
			return "┤";
		case 13: // [T,B,0,R]
			return "├";
		case 12: // [T,B,0,0]
			return "│";
		case 11: // [T,0,L,R]
			return "┴";
		case 10: // [T,0,L,0]
			return "┘";
		case  9: // [T,0,0,R]
			return "└";
		case  8: // [T,0,0,0]
			return "╵";
		case  7: // [0,B,L,R]
			return "┬";
		case  6: // [0,B,L,0]
			return "┐";
		case  5: // [0,B,0,R]
			return "┌";
		case  4: // [0,B,0,0]
			return "╷";
		case  3: // [0,0,L,R]
			return "─";
		case  2: // [0,0,L,0]
			return "╴";
		case  1: // [0,0,0,R]
			return "╶";
		case  0: // No Wall Around
			return "·";
		default:
			return " ";
	}
}

// ┌───┐ 5  1 1 1
// │   │    1 0 1 
// └───┘    1 1 1
// 3
// ┌───┬───┐ 9
// │   │   │
// ├───┼───┤
// │   │   │
// └───┴───┘
// 5
// ┌─┬─┐
// │   │
// └─┴─┘

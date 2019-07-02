#include <iostream>
#include "Pyramid.h"


using namespace std;


Pyramid::Pyramid() : Shape()
{
	// create the new shape according to the inherit class 
	this->size = PYRAMID_SIZE;
	this->appearance = BLOCK_APPEARANCE;
	updateShapeValues(this->shape);
}

// this function decide where to place the tetris shape points according to the initial place of the board.
void Pyramid::updateShapeValues(vector<Point>& shape)
{
	Point one, two, three, four;

	one.setXY(4, 1 + (ROWSFORMENU - 1));
	two.setXY(5, 0 + (ROWSFORMENU - 1));
	three.setXY(5, 1 + (ROWSFORMENU - 1));
	four.setXY(6, 1 + (ROWSFORMENU - 1));

	// put the Point class in the vector of point
	shape.push_back(one);
	shape.push_back(two);
	shape.push_back(three);
	shape.push_back(four);
}

// this function responsible to rotate the shape. if the shape is not rotateble, do nothing.
bool Pyramid::rotateShape(const char rotateAxis, const char horizontal, const int**const matOfGame)
{
	int i, x, y;
	bool canMove = true;

	x = shape[2].getX();
	y = shape[2].getY();

	if (rotateAxis == 'R' && horizontal == 'T')
	{
		if (matOfGame[y + 1][x] == 1) 
			canMove = false;
		if (canMove)
		{
			shape[0].draw(' ');
			shape[0].setXY(x, y + 1);
			shape[0].draw(appearance);
		}
	}
	else if (rotateAxis == 'L' && horizontal == 'T')
	{
		if (matOfGame[y - 1][x] == 1) 
			canMove = false;
		if (canMove)
		{
			shape[3].draw(' ');
			shape[3].setXY(x, y - 1);
			shape[3].draw(appearance);
		}
	}
	else if (rotateAxis == 'R' && horizontal == 'F')
	{
		if (matOfGame[y][x - 1] == 1)
			canMove = false;
		if (canMove)
		{
			shape[1].draw(' ');
			shape[1].setXY(x - 1, y);
			shape[1].draw(appearance);
		}   
	}
	else if (rotateAxis == 'L' && horizontal == 'F')
	{

		if (matOfGame[y][x - 1] == 1 || matOfGame[y][x + 1] == 1 || matOfGame[y - 1][x] == 1)
			canMove = false;
		if (canMove)
		{
			for (i = 0; i < size; i++)
				shape[i].draw(' ');

			shape[0].setXY(x - 1, y);
			shape[1].setXY(x, y - 1);
			shape[3].setXY(x + 1, y);

			for (i = 0; i < size; i++)
			{
				shape[i].draw(appearance);
			}
		}
		
	}
	return canMove;
}

//checks if game is over because of the current shape that got in the game.
bool Pyramid::checkIfGameOver(const int**const matOfGame)const
{
	int col; 

	for (col = 4; col < 4 + (size - 1); col++)
	{
		if (matOfGame[ROWSFORMENU][col] == 1)
			return true;
	}
	return false;
}

// checks if we can rotate our current shape.
bool Pyramid::checkIfShapeRotate()const
{
	return true;
}
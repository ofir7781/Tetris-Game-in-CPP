#ifndef CUBE_H
#define CUBE_H

#include"Shape.h"


class Cube : public Shape
{
public:
	Cube();//constructor
	Cube(const Cube& other) :Shape(other) {} // copy constructor
	~Cube() {} // destructor

	// this function decide where to place the tetris shape points according to the initial place of the board.
	virtual void updateShapeValues(vector<Point>& shape) override;
	virtual bool rotateShape(const char rotateAxis, const char horizontal, const int**const matOfGame) override;
	virtual bool checkIfGameOver(const int**const matOfGame) const override;
	virtual bool checkIfShapeRotate()const override; // checks if we can rotate our current shape.
};


#endif // !CUBE_H


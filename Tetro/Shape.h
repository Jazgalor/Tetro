#pragma once

#include "Const.h"

struct Position
{
	char x;
	char y;
};

class Shape
{
	//variables
	Position squarePosition[4];
	unsigned char rotateState;

	//initialization of variables
	void initVariables();

public:
	//variables
	unsigned char shapeNumber;

	//constructor, destructor
	Shape();
	virtual ~Shape();

	//functions
	void pickShape(unsigned char shapeNumber);
	void rotateShape(unsigned char shapeNumber);
	void moveUp();
	void moveDown(unsigned char (&grid)[ROWS][COLUMNS]);
	void moveHorizontal(char dir);
	void updateGrid(unsigned char(&grid)[ROWS][COLUMNS]);
	bool collisionCheckV(unsigned char(&grid)[ROWS][COLUMNS]);
	bool collisionCheckH(unsigned char(&grid)[ROWS][COLUMNS],char dir);
	bool collisionCheckS(unsigned char(&grid)[ROWS][COLUMNS]);
	bool collisionSpawn(unsigned char(&grid)[ROWS][COLUMNS]);
};


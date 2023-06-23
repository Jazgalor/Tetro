#include "Shape.h"

void Shape::initVariables()
{
	//i need to do something about it (make random shape generator)
	srand(time(NULL));
	shapeNumber = rand() % 7 + 1;
	this->pickShape(shapeNumber);
	this->rotateState = 0;
}

Shape::Shape()
{
	this->initVariables();
}

Shape::~Shape()
{

}

void Shape::pickShape(unsigned char shapeNumber)
{
	//all shapes starting positions
	switch (shapeNumber)
	{
		case 1:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 0;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 0;
			this->squarePosition[2].x = (COLUMNS / 2) - 1;
			this->squarePosition[2].y = 1;
			this->squarePosition[3].x = (COLUMNS / 2);
			this->squarePosition[3].y = 1;
			break;
		case 2:
			this->squarePosition[0].x = (COLUMNS / 2);
			this->squarePosition[0].y = 0;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 1;
			this->squarePosition[2].x = (COLUMNS / 2);
			this->squarePosition[2].y = 2;
			this->squarePosition[3].x = (COLUMNS / 2);
			this->squarePosition[3].y = 3;
			break;
		case 3:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 1;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 1;
			this->squarePosition[2].x = (COLUMNS / 2);
			this->squarePosition[2].y = 0;
			this->squarePosition[3].x = (COLUMNS / 2) + 1;
			this->squarePosition[3].y = 0;
			break;
		case 4:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 0;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 0;
			this->squarePosition[2].x = (COLUMNS / 2);
			this->squarePosition[2].y = 1;
			this->squarePosition[3].x = (COLUMNS / 2) + 1;
			this->squarePosition[3].y = 1;
			break;
		case 5:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 0;
			this->squarePosition[1].x = (COLUMNS / 2) - 1;
			this->squarePosition[1].y = 1;
			this->squarePosition[2].x = (COLUMNS / 2) - 1;
			this->squarePosition[2].y = 2;
			this->squarePosition[3].x = (COLUMNS / 2);
			this->squarePosition[3].y = 2;
			break;
		case 6:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 2;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 2;
			this->squarePosition[2].x = (COLUMNS / 2);
			this->squarePosition[2].y = 1;
			this->squarePosition[3].x = (COLUMNS / 2);
			this->squarePosition[3].y = 0;
			break;
		case 7:
			this->squarePosition[0].x = (COLUMNS / 2) - 1;
			this->squarePosition[0].y = 0;
			this->squarePosition[1].x = (COLUMNS / 2);
			this->squarePosition[1].y = 0;
			this->squarePosition[2].x = (COLUMNS / 2) + 1 ;
			this->squarePosition[2].y = 0;
			this->squarePosition[3].x = (COLUMNS / 2);
			this->squarePosition[3].y = 1;
			break;
		default:
			break;

	}
}

void Shape::rotateShape(unsigned char shapeNumber)
{
	//rotate state nothing much to explain 
	rotateState++;
	if (rotateState > 3)rotateState = 0;

	//warning huge mess ahead (or beneath) just skip to #400 (it basically return next rotate position based on previous one (for all shapes)) 
	switch (shapeNumber)
	{
		case 1:
			break;
		case 2:
			switch (rotateState)
			{
				case 0:
					this->squarePosition[0].x += 2;
					this->squarePosition[0].y -= 1;
					this->squarePosition[1].x += 1;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x += 0;
					this->squarePosition[2].y += 1;
					this->squarePosition[3].x -= 1;
					this->squarePosition[3].y += 2;
					break;
				case 1:
					this->squarePosition[0].x += 1;
					this->squarePosition[0].y += 2;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y += 1;
					this->squarePosition[2].x -= 1;
					this->squarePosition[2].y += 0;
					this->squarePosition[3].x -= 2;
					this->squarePosition[3].y -= 1;
					break;
				case 2:
					this->squarePosition[0].x -= 2;
					this->squarePosition[0].y += 1;
					this->squarePosition[1].x -= 1;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x += 0;
					this->squarePosition[2].y -= 1;
					this->squarePosition[3].x += 1;
					this->squarePosition[3].y -= 2;
					break;
				case 3:
					this->squarePosition[0].x -= 1;
					this->squarePosition[0].y -= 2;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y -= 1;
					this->squarePosition[2].x += 1;
					this->squarePosition[2].y += 0;
					this->squarePosition[3].x += 2;
					this->squarePosition[3].y += 1;
					break;
				default:
					break;
			}
			break;
		case 3:
			switch (rotateState)
			{
				case 0:
					this->squarePosition[0].x -= 1;
					this->squarePosition[0].y -= 1;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x += 1;
					this->squarePosition[2].y -= 1;
					this->squarePosition[3].x += 2;
					this->squarePosition[3].y += 0;
					break;
				case 1:
					this->squarePosition[0].x += 1;
					this->squarePosition[0].y -= 1;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x += 1;
					this->squarePosition[2].y += 1;
					this->squarePosition[3].x += 0;
					this->squarePosition[3].y += 2;
					break;
				case 2:
					this->squarePosition[0].x += 1;
					this->squarePosition[0].y += 1;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x -= 1;
					this->squarePosition[2].y += 1;
					this->squarePosition[3].x -= 2;
					this->squarePosition[3].y += 0;
					break;
				case 3:
					this->squarePosition[0].x -= 1;
					this->squarePosition[0].y += 1;
					this->squarePosition[1].x += 0;
					this->squarePosition[1].y += 0;
					this->squarePosition[2].x -= 1;
					this->squarePosition[2].y -= 1;
					this->squarePosition[3].x += 0;
					this->squarePosition[3].y -= 2;
					break;
				default:
					break;
			}
			break;
		case 4:
			switch (rotateState)
			{
			case 0:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y -= 2;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y += 1;
				break;
			case 1:
				this->squarePosition[0].x += 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y += 1;
				break;
			case 2:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y += 2;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y -= 1;
				break;
			case 3:
				this->squarePosition[0].x -= 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y -= 1;
				break;
			default:
				break;
			}
			break;
			//yo what ya doing here, you weren't supposed to be here m8
		case 5:
			switch (rotateState)
			{
			case 0:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y -= 2;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x -= 2;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y += 1;
				break;
			case 1:
				this->squarePosition[0].x += 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y -= 2;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y -= 1;
				break;
			case 2:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y += 2;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 2;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y -= 1;
				break;
			case 3:
				this->squarePosition[0].x -= 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 2;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y += 1;
				break;
			default:
				break;
			}
			break;
		case 6:
			switch (rotateState)
			{
			case 0:
				this->squarePosition[0].x -= 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y -= 1;
				break;
			case 1:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y -= 2;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 1;
				this->squarePosition[3].y += 1;
				break;
			case 2:
				this->squarePosition[0].x += 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y += 1;
				break;
			case 3:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y += 2;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x -= 1;
				this->squarePosition[3].y -= 1;
				break;
			default:
				break;
			}
			break;
		case 7:
			switch (rotateState)
			{
			case 0:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y -= 2;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 2;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 0;
				this->squarePosition[3].y += 0;
				break;
			case 1:
				this->squarePosition[0].x += 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x += 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y += 2;
				this->squarePosition[3].x += 0;
				this->squarePosition[3].y += 0;
				break;
			case 2:
				this->squarePosition[0].x += 0;
				this->squarePosition[0].y += 2;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y += 1;
				this->squarePosition[2].x -= 2;
				this->squarePosition[2].y += 0;
				this->squarePosition[3].x += 0;
				this->squarePosition[3].y += 0;
				break;
			case 3:
				this->squarePosition[0].x -= 2;
				this->squarePosition[0].y += 0;
				this->squarePosition[1].x -= 1;
				this->squarePosition[1].y -= 1;
				this->squarePosition[2].x += 0;
				this->squarePosition[2].y -= 2;
				this->squarePosition[3].x += 0;
				this->squarePosition[3].y += 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
	}
	//this checks if shape exceed the boundaries (left / right) and fix it
	for (Position& shape : this->squarePosition)
	{
		for (int i = shape.x - (COLUMNS - 1); i > 0; i--)
		{
			for (Position& shape : this->squarePosition)
			{
				shape.x -= 1;
			}
		}
		for (int i = shape.x ; i < 0; i++)
		{
			for (Position& shape : this->squarePosition)
			{
				shape.x += 1;
			}
		}
	}
}

//move shape up
void Shape::moveUp()
{
	for (Position& shape : this->squarePosition)
	{
		shape.y-=2;
	}
}

void Shape::moveDown(unsigned char (&grid)[ROWS][COLUMNS])
{
	//check if shape collides with lower border and other shapes then proceed to move the shape down
	if (collisionCheckV(grid)) {
		for (Position& shape : this->squarePosition)
		{
			shape.y++;
		}
	}
	//otherwise move the shape to stationary state and generate new shape
	else
	{
		for (Position& shape : this->squarePosition)
		{
			grid[shape.y][shape.x]=this->shapeNumber;
		}
		//create new shape
		this->initVariables();
	}
	
}

void Shape::moveHorizontal(char dir)
{
	for (Position& shape : this->squarePosition)
	{
		shape.x+=dir;
	}
}

void Shape::updateGrid(unsigned char(&grid)[ROWS][COLUMNS])
{
	//removing all old moving shape trails
	for (unsigned char i = 0; i < ROWS; i++)
	{
		for (unsigned char j = 0; j < COLUMNS; j++)
		{
			if (grid[i][j] > 7) grid[i][j] = 0;
		}
	}
	//then mark the current state of shape (moving state)
	if (!(this->collisionSpawn(grid)))
	{
		for (Position& shape : this->squarePosition)
		{
			grid[shape.y][shape.x] = shapeNumber + 7;
		}
	}
	else
	{
		this->initVariables();
	}
}

//checks if touches lower border and other shapes from bottom
bool Shape::collisionCheckV(unsigned char(&grid)[ROWS][COLUMNS])
{
	for (Position& shape : this->squarePosition)
	{
		if (shape.y == ROWS-1 || (grid[shape.y+1][shape.x]!=0 && grid[shape.y+1][shape.x] <= 7)) return false;
		else continue;
	}
	return true;
}

//horizontal movement needs different type of checks, so i came up with this (btw it needed a variable do predict movement)
bool Shape::collisionCheckH(unsigned char(&grid)[ROWS][COLUMNS],char dir)
{
	for (Position& shape : this->squarePosition)
	{
		if (((shape.x+dir > (COLUMNS-1) )||(shape.x+dir < 0))||(grid[shape.y][shape.x+dir] != 0 && grid[shape.y][shape.x+dir] <= 7)) return false;
		else continue;
	}
	return true;
}

//checking if shape is colliding with static shape after rotate
bool Shape::collisionCheckS(unsigned char(&grid)[ROWS][COLUMNS])
{
	for (Position& shape : this->squarePosition)
	{
		if (grid[shape.y][shape.x] <= 7 && grid[shape.y][shape.x] != 0) return true;
		else if (shape.y >= ROWS) return true;
	}
	return false;
}

bool Shape::collisionSpawn(unsigned char(&grid)[ROWS][COLUMNS])
{
	for (Position& shape : this->squarePosition)
	{
		if (grid[shape.y][shape.x] <= 7 && grid[shape.y][shape.x] != 0) return true;
	}
	return false;
}

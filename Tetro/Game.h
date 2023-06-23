#pragma once


#include "Shape.h"
#include "Const.h"


class Game
{
	//variables
	unsigned int delay;

	//functions
	bool isFilled(int row);
	void moveRowBeg(int row);
	void removeFilled();

	//sfml window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//grid
	unsigned char grid[ROWS][COLUMNS];

	//booleans
	bool isLeftClickHold;

	//shape
	Shape shape;

	//initialization of variables
	void initVariables();


public:
	//constructor, destructor
	Game();
	virtual ~Game();

	//is game running?
	const bool running() const;

	//functions
	void update();
	void render();
};

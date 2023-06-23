#include "Game.h"

bool Game::isFilled(int row)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		if (this->grid[row][i] == 0 || this->grid[row][i] > 7) return false;
	}
	return true;
}

void Game::moveRowBeg(int row)
{
	for (int i = row; i > 0; i--)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			unsigned char tmp = grid[i-1][j];
			grid[i - 1][j] = grid[i][j];
			grid[i][j] = tmp;
		}
	}
}

void Game::removeFilled()
{
	int i = ROWS - 1;
	while (i >= 0)
	{
		if (this->isFilled(i))
		{
			this->moveRowBeg(i);
			for (int j = 0; j < COLUMNS; j++)
			{
				grid[0][j] = 0;
			}
		}
		else
		{
			i--;
		}
	}
}

//initialize all variables
void Game::initVariables()
{
	delay = 0;
	//sfml window
	this->videoMode.height = CELL_SIZE * ROWS;
	this->videoMode.width = CELL_SIZE * COLUMNS;
	this->window = new sf::RenderWindow(this->videoMode, "Tetro", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);

	//grid
	for (int i{}; i < ROWS; i++)
	{
		for (int j{}; j < COLUMNS; j++)
		{
			this->grid[i][j] = 0;
		}
	}

	//booleans
	this->isLeftClickHold = false;

	//shape
	this->shape;
	this->shape.updateGrid(this->grid);
}

Game::Game()
{
	this->initVariables();
}

Game::~Game()
{
	delete this->window;
}

//is game running?
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
	//events
	while (this->window->pollEvent(this->event)) 
	{
		switch (this->event.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				switch (this->event.key.code)
				{
					case sf::Keyboard::Escape:
						this->window->close();
						break;
					case sf::Keyboard::Left: //move shape to left by 1
						if(this->shape.collisionCheckH(this->grid,-1)) this->shape.moveHorizontal(-1);
						this->shape.updateGrid(this->grid);
						break;
					case sf::Keyboard::Right: //move shape to right by 1
						if (this->shape.collisionCheckH(this->grid, 1)) this->shape.moveHorizontal(1);
						this->shape.updateGrid(this->grid);
						break;
					case sf::Keyboard::Up: //rotate shape clockwise by 1
						this->shape.rotateShape(this->shape.shapeNumber);
						//if collides with something move it up
						while (this->shape.collisionCheckS(this->grid))
						{
							this->shape.moveUp();
						}
						this->shape.updateGrid(this->grid);
						break;
					case sf::Keyboard::Down: //block will move faster
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}

	//grid control with mouse left
	/*
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (!(this->isLeftClickHold))
		{
			this->isLeftClickHold = 1;
			int x = sf::Mouse::getPosition(*(this->window)).x / CELL_SIZE;
			int y = sf::Mouse::getPosition(*(this->window)).y / CELL_SIZE;
			if ((y >= 0 && y <= ROWS) && (x >= 0 && x <= COLUMNS))this->grid[y][x] = 1 - this->grid[y][x];
		}

	}
	else this->isLeftClickHold = 0;
	*/

	//how often move down function is made
	if (delay == 15)
	{
		
		delay = 0;
		this->shape.moveDown(this->grid);
		this->shape.updateGrid(this->grid);
		if (this->shape.collisionSpawn(this->grid))
		{
			for (int i{}; i < ROWS; i++)
			{
				for (int j{}; j < COLUMNS; j++)
				{
					this->grid[i][j] = 0;
				}
			}
		}
		this->removeFilled();
	}
	else delay++;

	//output for mouse position (for tests)
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) std::cout << sf::Mouse::getPosition(*(this->window)).y << " " << sf::Mouse::getPosition(*(this->window)).x << std::endl;
	
}

void Game::render()
{
	//flush
	this->window->clear(sf::Color::Black);

	//drawing objects grid
	sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 4, CELL_SIZE - 4));
	//cell.setFillColor(sf::Color(0, 255, 0, 255));
	for (unsigned char i = 0; i < ROWS; i++)
	{
		for (unsigned char j = 0; j < COLUMNS; j++)
		{
			cell.setPosition((CELL_SIZE * j)+2,( CELL_SIZE * i)+2);

			//coloring with grid
			if (grid[i][j] == 1 || grid[i][j] == 8) cell.setFillColor(sf::Color(240, 240, 0, 255));
			else if (grid[i][j] == 2 || grid[i][j] == 9) cell.setFillColor(sf::Color(0, 240, 240, 255));
			else if (grid[i][j] == 3 || grid[i][j] == 10) cell.setFillColor(sf::Color(0, 240, 0, 255));
			else if (grid[i][j] == 4 || grid[i][j] == 11) cell.setFillColor(sf::Color(240, 0, 0, 255));
			else if (grid[i][j] == 5 || grid[i][j] == 12) cell.setFillColor(sf::Color(240, 160, 0, 255));
			else if (grid[i][j] == 6 || grid[i][j] == 13) cell.setFillColor(sf::Color(0, 0, 240, 255));
			else if (grid[i][j] == 7 || grid[i][j] == 14) cell.setFillColor(sf::Color(160, 0, 240, 255));
			else cell.setFillColor(sf::Color(0, 0, 100, 255));
			this->window->draw(cell);		
		}
	}

	//display new frame
	this->window->display();
}

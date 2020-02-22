#include "LabMap.h"



LabMap::LabMap()
{
	int cellSize = 64;
	int gridWidth = 20;
	int gridHeight = 15;

	InitSprites();

	// Declare and create a new render-window
	window = new RenderWindow(sf::VideoMode(cellSize*gridWidth, cellSize*gridHeight), "LabHero Game");
}


LabMap::~LabMap()
{
}


void LabMap::CheckWindowForCloseBtnPressed()
{
	// Event processing
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Request for closing the window
		if (event.type == sf::Event::Closed)
			window->close();
	}
}


void LabMap::DrawFrame()
{
	sprGreenFloor->setPosition(Vector2f(0, 0));
	window->draw(*sprGreenFloor);


	window->display();
}



void LabMap::InitSprites()
{
	imgAtlas1 = new Image();
	imgAtlas1->loadFromFile("images/Hero/tilea2.png");

	texAtlas1 = new Texture();
	texAtlas1->loadFromImage(*imgAtlas1);

	sprGreenFloor = new Sprite();
	sprGreenFloor->setTexture(*texAtlas1);
	sprGreenFloor->setTextureRect( IntRect(129, 33, 64, 64) );
}



void LabMap::Run()
{
	// Limit the framerate to 60 frames per second (this step is optional)
	window->setFramerateLimit(60);

	// The main loop - ends as soon as the window is closed
	while (window->isOpen())
	{
		DrawFrame();

		CheckWindowForCloseBtnPressed();
	}
}

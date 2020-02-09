#include "SFML/Graphics.hpp"
#include "LabHero.h"
#include "helpers.h"

using namespace sf;



LabHeroGame::LabHeroGame()
{
	tiles_tex = new Texture();
	tile = new Sprite();

	hero_tex = new Texture();
	hero_sprite = new Sprite();


	//tile
	tiles_tex->loadFromFile("images/Hero/tilearea.png");
	tile->setTexture(*tiles_tex);
	tile->setTextureRect(IntRect(0, 224, 64, 64));

	//hero sprite
	hero_tex->loadFromFile("images/Hero/remakertp01.png", IntRect(6 * 32, 0, 3 * 32, 4 * 48));
	hero_sprite->setTexture(*hero_tex);


	// Declare and create a new render-window
	window = new RenderWindow(sf::VideoMode(cellSize*gridWidth, cellSize*gridHeight), "SFML window");
}


LabHeroGame::~LabHeroGame()
{
}


void LabHeroGame::Draw()
{
	window->clear();

	DrawMap();
	DrawHero();


	// End the current frame and display its contents on screen
	window->display();
}


void LabHeroGame::DrawMap()
{
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			tile->setPosition(i * cellSize, j * cellSize);
			window->draw(*tile);
		}
	}
		
}


void LabHeroGame::DrawHero()
{
	//draw char
	hero_sprite->setPosition(PixelCoords.x + 16, PixelCoords.y + 6 );
	hero_sprite->setTextureRect(IntRect((frame_counter / 6 % 3) * 32, 0, 32, 48));
	window->draw(*hero_sprite);
}


void LabHeroGame::GetInput()
{

	if (Keyboard::isKeyPressed(Keyboard::Right) && state == EHeroState::idle)
	{
		state = EHeroState::run;
		SetNewDestination(CellCoords(1, 0) );
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && state == EHeroState::idle)
	{
		state = EHeroState::run;
		SetNewDestination(CellCoords(-1, 0));
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && state == EHeroState::idle)
	{
		state = EHeroState::run;
		SetNewDestination(CellCoords(0, -1));
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && state == EHeroState::idle)
	{
		state = EHeroState::run;
		SetNewDestination(CellCoords(0, 1));
	}
		

	if (Keyboard::isKeyPressed(Keyboard::Escape))
		window->close();
}


void LabHeroGame::SetNewDestination(CellCoords dir)
{
	next_cell = current_cell + dir;
	path = cellSize;
}


V2 LabHeroGame::GetMoveDirection()
{
	return (next_cell - current_cell).NormalAsV2();
}


void LabHeroGame::MoveHero()
{
	if (state == EHeroState::run)
	{
		PixelCoords = PixelCoords + GetMoveDirection() * moveSpeed * deltaTime;

		path -= moveSpeed * deltaTime;

		if (path <= 0)
		{
			current_cell = next_cell;
			PixelCoords = V2(current_cell.i*cellSize, current_cell.j*cellSize);
			state = EHeroState::idle;
		}
	}
}


void LabHeroGame::Tick()
{
	MoveHero();
}


void LabHeroGame::Run()
{
	Clock clock;

	float oldTime = clock.getElapsedTime().asSeconds();


	// Limit the framerate to 60 frames per second (this step is optional)
	window->setFramerateLimit(60);

	// The main loop - ends as soon as the window is closed
	while (window->isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds() - oldTime;
		oldTime = clock.getElapsedTime().asSeconds();


		// Event processing
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed)
				window->close();
		}


		frame_counter++;
		
		GetInput();
		Tick();
		Draw();
	}
}

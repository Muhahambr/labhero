#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;



class LabMap
{
private:
	int cellSize;
	int gridWidth;
	int gridHeight;

	RenderWindow * window;

	void CheckWindowForCloseBtnPressed();

	void DrawFrame();

private:
	Image * imgAtlas1;
	Texture * texAtlas1;
	
	Sprite * sprGreenFloor;

	Image * imgHeroPing;
	Texture * texHeroPink;
	Sprite * Hero;

	void InitSprites();



public:
	void Run();

	LabMap();
	~LabMap();
};


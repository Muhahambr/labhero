#include "SFML/Graphics.hpp"
#include "Core.h"
#include "helpers.h"


using namespace sf;


enum EHeroState {idle=0, run=1};




class LabHeroGame
{

//moving & coords
private:
	CellCoords current_cell = CellCoords();
	CellCoords next_cell = CellCoords();;

	V2 PixelCoords = V2();

	const float moveSpeed = 64;
	float path = 0;

	EHeroState state = EHeroState::idle;


	void SetNewDestination(CellCoords dir);
	V2 GetMoveDirection();

private:
	RenderWindow * window;

	int frame_counter = 0;
	float deltaTime = 0;


//drawing
private:
	int cellSize = 64;
	int gridWidth = 20;
	int gridHeight = 15;

	


	Texture * tiles_tex;
	Texture * hero_tex;

	Sprite * tile;
	Sprite * hero_sprite;


	void DrawMap();
	void DrawHero();
	void Draw();

	void GetInput();
	

	void MoveHero();
	void Tick();
	

public:
	LabHeroGame();
	~LabHeroGame();

	void Run();
};


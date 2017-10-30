#pragma once

#include <SDL.h>
#include <GL\glew.h>

#include "Grid.h"

enum class GameState{PLAY, EXIT};

class QuadTree
{
public:
	QuadTree();
	~QuadTree();

	void Start();

private:
	void InitializeSystem();
	void GameLoop();
	void ProcessInput();
	void Draw();


	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;
	Grid _grid;
};


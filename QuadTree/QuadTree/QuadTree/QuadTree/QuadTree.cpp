#include <iostream>
#include <string>

#include "QuadTree.h"


//Check for any errors in the program allowing user to quit out
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter and key to quit ..." << std::endl;
	int temp;
	std::cin >> temp;
	SDL_QUIT;
}

QuadTree::QuadTree()
{
	_window = nullptr; //Make sure window is initialised
	_screenHeight = 780;
	_screenWidth = 840;

	_gameState = GameState::PLAY;
}


QuadTree::~QuadTree()
{

}

void QuadTree::Start()
{
	InitializeSystem();
	_grid.Initialize(-1, -1, 1, 1);
	GameLoop();
}

void QuadTree::InitializeSystem()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Quad Tree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	if (_window == nullptr)
		fatalError("SDL Window could not be created!");

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
		fatalError("SDL_GL context could not be created!");

	GLenum error = glewInit();
	if (error != GLEW_OK)
		fatalError("Could not initialize GLEW");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	//Initialize OpenGL

}

void QuadTree::GameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		ProcessInput();
		Draw();
	}
}
void QuadTree::ProcessInput()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << " " << event.motion.y << std::endl;
			break;
		}
	}
}

void QuadTree::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	_grid.Draw();


	/*
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 1.f, 0.f);
	glVertex3f(-.5, -.5, 0);
	glVertex3f(-.5, .5, 0);
	glVertex3f(.5, .5, 0);
	glEnd();*/



	SDL_GL_SwapWindow(_window);
}




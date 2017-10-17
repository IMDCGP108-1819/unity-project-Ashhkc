#include "SDL.h"
#include <GL/glew.h>

void StartDisplay()
{
	bool exit = false;  // Variable to control when to exit application
	SDL_Event event;    // Create an event handler. This is used to react to any user events within the SDL window

						////////////////////////////////////////////////////////////////////////////
						// SDL Initialisation START         (could be placed in a seperate function)
						////////////////////////////////////////////////////////////////////////////
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)  // Initialize ALL features of SDL and get return value to check if this worked
	{
		cout << "Error Intialising SDL: " << SDL_GetError() << "\n"; // Output message if there was an error
	}
	else    // If there was no error, proceed to initialising SDL and OpneGL
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);   // Restrict maximum version of opengGL to v4
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);   // Restrict minimum version of opengGL to v4

		window = SDL_CreateWindow("Hello Triangle", xpos, ypos, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);   // Create an SDL window

		if (window == NULL) // Output a message if the window was not created properly
		{
			cout << "Error Creating Window: " << SDL_GetError() << "\n";
		}
		else
		{
			context = SDL_GL_CreateContext(window);     // Create the context, this tells SDL which graphics library it is working with

			if (context == NULL)    // Output a message if there was an error with the context
			{
				cout << "Error Creating Context: " << SDL_GetError() << "\n";
			}
			////////////////////////////////////////////////////////////////////////////
			// SDL Initialisation END
			////////////////////////////////////////////////////////////////////////////
			else
			{
				////////////////////////////////////////////////////////////////////////////
				// opengGL Initialise START          (could be placed in a seperate function)
				////////////////////////////////////////////////////////////////////////////
				GLenum error = GL_NO_ERROR;     // Create an error handler

				glMatrixMode(GL_PROJECTION);    // Make the Projection matrix active. The projection matrix defines the properties of the camera that views the objects in 3D space (zoom, aspect ratio etc)
				glLoadIdentity();               // Load the identity matrix. Because the projection matrix is currently loaded, this resets the projection matrix settings to defaults (ie clears it)

				error = glGetError();           // Check if any errors were generated by previous steps
				if (error != GL_NO_ERROR)
				{
					cout << "Error initializing opengGL";
				}

				glMatrixMode(GL_MODELVIEW);     // Make the Model View matrix active. The modelview matrix defines how your objects are transformed
				glLoadIdentity();               // Load the identity matrix.  Because the model view matrix is currently loaded, this resets the model view matrix settings to defaults (ie clears it)

				error = glGetError();           // Check if any errors were generated by previous steps
				if (error != GL_NO_ERROR)
				{
					cout << "Error initializing opengGL";
				}
				////////////////////////////////////////////////////////////////////////////
				// opengGL Initialise END
				////////////////////////////////////////////////////////////////////////////
			}
		}
	}

	SDL_StartTextInput();   // Enable text input through SDL

							////////////////////////////////////////////////////////////////////////////
							// Main game Loop START
							// Now that all initialisation has taken place, the main game loop can start
							////////////////////////////////////////////////////////////////////////////   
	while (!exit)   // Continue until the 'exit' variable has been changed to true
	{
		while (SDL_PollEvent(&event) != 0)  // Check if there are any events to process
		{
			if (event.type == SDL_QUIT)     // If the current event is a quit (exit) action, change the 'exit' variable to true
			{
				exit = true;
			}
			else if (event.type == SDL_TEXTINPUT)   // If the current event is a text input event
			{
				if (event.text.text[0] == 't')  // If use pressed the 't' key toggle draw state of the triangle
				{
					drawTriangle = !drawTriangle;
				}
			}
		}
		SDL_GL_SwapWindow(window);  // Refresh the window to show any changes made in the previous display() function
	}
	////////////////////////////////////////////////////////////////////////////
	// Main game Loop END
	////////////////////////////////////////////////////////////////////////////   

	// The main game loop has now been exited, so we need to clean up

	SDL_StopTextInput();    // Stop text input

	SDL_DestroyWindow(window);  // Destroy the window
	window = NULL;              // Free up the memory used by the window

	SDL_Quit();             // Shutdown SDL

}

void display()
{
	bool drawLine = true;

	glClear(GL_COLOR_BUFFER_BIT);   // clear colour buffer

	if (drawLine) // draw lines when required
	{
		GLfloat xCords = 0.9f;
		//GLfloat yCords;

		bool drawX = true;
		bool drawY = false;

		glBegin(GL_LINES);      // start define data for the lines
		glColor3f(1, 1, 1);     // sefine colour of lines

		while (xCords)
		{
			glVertex2f(xCords, 1);
			glVertex2f(xCords, -1);

			xCords =+ 0.1f;

			if (xCords == 1)
				break;
		}
		glEnd();
/*

		// create loop here
		

		// create loop here
		glVertex2f(xCords, 1);
		glVertex2f(xCords, -1);
		*/

	}
}

void DrawXLine()
{
	
}
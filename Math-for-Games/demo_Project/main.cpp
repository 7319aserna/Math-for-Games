#include <iostream>
#include "raylib.h"
#include "tank.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	float screenWidth = 1000.0f;
	float screenHeight = 1000.0f;

	InitWindow(screenWidth, screenHeight, "demo_Project");

	SetTargetFPS(60);

	tank tankObject;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		tankObject.update(GetFrameTime());
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		tankObject.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
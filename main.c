#include "raylib.h"

int main(void)
{
	Camera2D cam = {
		0
	};
	cam.zoom = 1.f;
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Gearhaven");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if ( IsKeyPressed( KEY_F5 ) )
			ToggleFullscreen();

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode2D(cam);
			DrawText( "Test text", 100, 100, 20, BLACK );

		EndMode2D();
		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

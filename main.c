#include "raylib.h"
#include <stdio.h>

int main(void)
{
	Camera2D cam = {
		0
	};
	cam.zoom = 1.f;
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Gearhaven");
	//SetTargetFPS(60);

	RenderTexture2D canvas = LoadRenderTexture(screenWidth, screenHeight);

	while (!WindowShouldClose())
	{
		if ( IsKeyPressed( KEY_F5 ) ) {
			ToggleFullscreen();
		}

		int width = screenWidth;
		int height = screenHeight;

		if ( IsWindowFullscreen() ) {
			int monitor = GetCurrentMonitor();
			width = GetMonitorWidth(monitor);
			height = GetMonitorHeight(monitor);
		};

		BeginTextureMode(canvas);
		ClearBackground(RAYWHITE);
		BeginMode2D(cam);
		DrawText( "Test text", 100, 100, 20, BLACK );

		EndMode2D();
		EndTextureMode();

		char debug[50] = { 0 };
		sprintf( debug, "FPS: %d", GetFPS() );
		BeginDrawing();
		DrawTexturePro(canvas.texture, (Rectangle){0, 0, screenWidth, -screenHeight}, (Rectangle){0, 0, width, height}, (Vector2){0, 0}, 0, WHITE);
		DrawText( debug, 0, 0, 11, BLACK );
		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

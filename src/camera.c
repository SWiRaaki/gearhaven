#include "camera.h"

#include <raymath.h>

#include "gearhaven.h"
#include "controls.h"

Camera2D gh_camera = { 0 };

void gh_initCamera( void ) {
	// Set default zoom to 100%
	gh_camera.zoom = 1.f;
	// Set offset to focus the target position in the center of the camera
	gh_camera.offset = (Vector2) { gh_getResolutionWidth() / 2.f, gh_getResolutionHeight() / 2.f };
}

void gh_updateCamera( void ) {
	// Create a movement delta with initial 0 
	Vector2 mov = { .x = .0f, .y = .0f };

	// Check for the keys pressed and modify the movement delta accordingly
	if ( IsKeyDown( gh_controls.cameraMoveUp ) || IsKeyDown( gh_controls_alt.cameraMoveUp ) )
		mov.y += 2.f;
	if ( IsKeyDown( gh_controls.cameraMoveDown ) || IsKeyDown( gh_controls_alt.cameraMoveDown ) )
		mov.y -= 2.f;
	if ( IsKeyDown( gh_controls.cameraMoveLeft ) || IsKeyDown( gh_controls_alt.cameraMoveLeft ) )
		mov.x -= 2.f;
	if ( IsKeyDown( gh_controls.cameraMoveRight ) || IsKeyDown( gh_controls_alt.cameraMoveRight ) )
		mov.x += 2.f;

	// Add the movement delta to the cameras current target
	gh_camera.target = Vector2Add( gh_camera.target, mov );
}

void gh_drawCamera( void ) {
	// The camera itself should not draw anything except for some camera gui
}

void gh_closeCamera( void ) {
	// The camera has no resources to release or functionalities that are needed pre dying
}

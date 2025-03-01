#include "controls.h"
#include <raylib.h>

KeyBinds gh_controls = { 0 };
KeyBinds gh_controls_alt = { 0 };

void gh_initControls() {
	// Default camera movement keys: ↑ ↓ ← → 
	gh_controls.cameraMoveUp    = KEY_UP;
	gh_controls.cameraMoveDown  = KEY_DOWN;
	gh_controls.cameraMoveLeft  = KEY_LEFT;
	gh_controls.cameraMoveRight = KEY_RIGHT;

	// Alternative camera movement keys: w s a d 
	gh_controls_alt.cameraMoveUp    = KEY_W;
	gh_controls_alt.cameraMoveDown  = KEY_S;
	gh_controls_alt.cameraMoveLeft  = KEY_A;
	gh_controls_alt.cameraMoveRight = KEY_D;
}

void gh_updateControls( void ) {
	// Controls generally dont need any updates
}

void gh_drawControls( void ) {
	// Controls generally dont need any drawings
}

void gh_closeControls( void ) {
	// Controls generally dont need any cleanup
}

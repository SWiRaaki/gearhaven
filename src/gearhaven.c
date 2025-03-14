#include "gearhaven.h"
#include "camera.h"
#include "controls.h"

#include <raylib.h>
#include <raymath.h>

/// @brief Maximum length the debug string can be
#define _DBG_MAX_LENGTH 50
/// @brief Maximum number of debug strings can be drawn at a time
#define _DBG_MAX_LINES 10

/// @brief Array of strings for debug prints
char _dbg[_DBG_MAX_LINES][_DBG_MAX_LENGTH];
/// @brief Current cursor of the debug lines
i32  _dbg_line          = 0;

/// @brief Internal flag to indicate that the game is running
bool _running           = false;

/// @brief Rectangle representing the current game's resolution
Rectangle _resolution   = { .x = .0f, .y = .0f, .width = .0f, .height = .0f };
/// @brief Rectangle representing the current game's window
Rectangle _window       = { .x = .0f, .y = .0f, .width = .0f, .height = .0f };
/// @brief Resolution texture
RenderTexture2D _canvas = { 0 };

/**
 * @brief Add a debug string to the resolution independant post-draw screen
 * @param p_fmt Format string
 * @param ... List of variables to format
 */
static void _addDebugInfo( char const * p_fmt, ... ) {
	// If all debug lines are filled, ignore the debug text
	if ( _dbg_line >= _DBG_MAX_LINES )
		return;

	// Create a list of all parameters used for this call
	va_list args;
	va_start( args, p_fmt );
	
	// Format the values into the debug string
	vsnprintf( _dbg[_dbg_line++], _DBG_MAX_LENGTH, p_fmt, args ); 

	// Close the list of parameters
	va_end( args );
}

/**
 * @brief Toggle fullscreen mode with respect to resolution
 */
static void _toggleFullscreen( void ) {
	// Toggle fullscreen mode
	ToggleFullscreen();

	if ( IsWindowFullscreen() ) { // Set window size to the monitor size in fullscreen
		// get the current monitor handle
		int mtr = GetCurrentMonitor();
		_window.width  = (float)GetMonitorWidth( mtr );
		_window.height = (float)GetMonitorHeight( mtr );
	} else {                      // Set window size to the resolution size in non-fullscreen
		_window.width  = _resolution.width;
		_window.height = _resolution.height;
	}
}

void gh_init( void ) {
	// Set target resolution
	_resolution.width  = 800;
	_resolution.height = 600;
	
	// Set window width to the resolution
	_window.width  = _resolution.width;
	_window.height = _resolution.height;

	// Initialize the game window
	InitWindow( (i32)_window.width, (i32)_window.height, "Gearhaven" );

	// Initialize target canvas for resolution specific rendering
	_canvas = LoadRenderTexture( (i32)_window.width, (i32)_window.height );

	// Initialize component modules
	gh_initCamera();
	gh_initControls();

	// Toggle to fullscreen at the start of the game
	_toggleFullscreen();

	_running = true;
}

void gh_update( void ) {
	// Add some basic debug info
	_addDebugInfo( "FPS: %d", GetFPS() );
	_addDebugInfo( "Resolution: %.0f:%.0f", _resolution.width, _resolution.height );
	_addDebugInfo( "Screen: %.0f:%.0f", _window.width, _window.height );

	// Update component modules
	gh_updateCamera();
	gh_updateControls();

	// After logic check for WindowShouldClose, and if true set _running to false to exit the game after the last draw
	if ( WindowShouldClose() )
		_running = false;
}

void gh_draw( void ) {
	// Open the context for the content
	BeginTextureMode( _canvas );
		// Clear the background to a uniform color
		ClearBackground( RAYWHITE );
		// Start camera mode for the context using the games current camera
		BeginMode2D( gh_camera );
			// Draw component modules
			gh_drawCamera();
			gh_drawControls();
		// Stop camera mode for the context
		EndMode2D();
	// Close the context
	EndTextureMode();

	// Open the context for post-draw Debugging
	BeginDrawing();
		// Draw the canvas used for the game content to the full window
		DrawTexturePro( _canvas.texture, _resolution, _window, Vector2Zero(), .0f, WHITE );

		// Draw debug text lines on top of the game content
		for ( i32 i = 0; i < _dbg_line; ++i )
			DrawText( _dbg[i], 10, 10 + i * 12, 11, BLACK );
	// Close the context
	EndDrawing();
	// Reset the debug line curser
	_dbg_line = 0;
}

void gh_close( void ) {
	CloseWindow();
}

bool gh_running( void ) {
	return _running;
}

f32 gh_getResolutionWidth( void ) {
	return _resolution.width;
}

f32 gh_getResolutionHeight( void ) {
	return _resolution.height;
}

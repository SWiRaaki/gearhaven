/********************************************************************
	Author           : raki 
	Email            : siwiraki@gmail.com 
	Editor           : raki 
	Created at       : 2025/03/01 
	Last modified at : 2025/03/01 18:40 by raki 
********************************************************************/

#ifndef CONTROLS_H
#define CONTROLS_H

#include "gearhaven.h"

/// @brief Structure holding all keyboard bindings neccessary to play the game
typedef struct keybinds_s {
	/// @brief Key that moves the camera north while being pressed
	i32 cameraMoveUp;
	/// @brief Key that moves the camera south while being pressed
	i32 cameraMoveDown;
	/// @brief Key that moves the camera west while being pressed
	i32 cameraMoveLeft;
	/// @brief Key that moves the camera east while being pressed
	i32 cameraMoveRight;
} KeyBinds;

/// Current control keybinds used by the game
extern KeyBinds gh_controls;
/// Current alternative / secondary control keybinds used by the game
extern KeyBinds gh_controls_alt;

// -------- Component Interface -------- \\

/**
 * @brief Initialization function that prepares the pre-loop resources
 */
void gh_initControls( void );

/**
 * @brief Update function that is called at the start of the loop
 */
void gh_updateControls( void );

/**
 * @brief Draw function that is called after update is finished
 */
void gh_drawControls(  void );

/**
 * @brief Close function that marks the end of the lifecycle
 */
void gh_closeControls( void );

#endif // CONTROLS_H 

#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>

/// @brief 2D Topdown camera of the game
extern Camera2D gh_camera;

// -------- Component Interface -------- \\

/**
 * @brief Initialization function that prepares the pre-loop resources
 */
void gh_initCamera( void );

/**
 * @brief Update function that is called at the start of the loop
 */
void gh_updateCamera( void );

/**
 * @brief Draw function that is called after update is finished
 */
void gh_drawCamera(  void );

/**
 * @brief Close function that marks the end of the lifecycle
 */
void gh_closeCamera( void );

#endif // CAMERA_H

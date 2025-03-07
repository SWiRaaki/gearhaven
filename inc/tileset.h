/********************************************************************
	Author           : raki 
	Email            : siwiraki@gmail.com 
	Editor           : raki 
	Created at       : 2025/03/02 
	Last modified at : 2025/03/02 01:43 by raki 
********************************************************************/

#ifndef TILESET_H
#define TILESET_H

#include <raylib.h>
#include "gearhaven.h"

/**
 * @brief Structure wrapping simple tileset images
 */
typedef struct tileset_s {
	/// @brief Original texture of the tileset
	Texture2D texture;
	/// @brief Width of a single tile
	i32 width;
	/// @brief Height of a single tile
	i32 height;
} TileSet;

/**
 * @brief Load a tileset into GPU VRAM from a source image file
 * @param path Path to the source image file
 * @param tile_width Width of a single tile segment in the tileset
 * @param tile_height Height of a single tile segment in the tileset
 * @return Tileset object with the tileset metadata
 */
TileSet gh_loadTileSet( char const * path, i32 tile_width, i32 tile_height );

/**
 * @brief Releases a tileset from GPU VRAM and invalidates the tileset
 * @param tileset Pointer to the tileset object
 */
void gh_unloadTileSet( TileSet * tileset );

/**
 * @brief Draws a tile from the tileset to fill the destination rectangle
 * @paran x X-Index of the tile
 * @param y Y-Index of the tile
 * @param destination Rectangle with the world x|y position and the widht and height to draw the tile
 */
void gh_drawTile( TileSet * tileset, i32 x, i32 y, Rectangle destination );

#endif // TILESET_H 

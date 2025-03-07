#include "tileset.h"
#include <raylib.h>
#include <raymath.h>

TileSet gh_loadTileSet( char const * p_path, i32 p_tile_width, i32 p_tile_height ) {
	TileSet ret = {
		.texture = LoadTexture( p_path ),
		.width = p_tile_width,
		.height = p_tile_height
	};
	if ( ret.texture.id <= 0 )
		return (TileSet) { 0 };
	return ret;
}

void gh_unloadTileSet( TileSet * p_tileset ) {
	UnloadTexture( p_tileset->texture );
}

void gh_drawTile( TileSet * p_tileset, i32 p_x, i32 p_y, Rectangle p_destination ) {
	DrawTexturePro(
		p_tileset->texture,
		(Rectangle) { (f32)(p_x * p_tileset->width), (f32)(p_y * p_tileset->height), (f32)p_tileset->width, (f32)p_tileset->height },
		p_destination,
		Vector2Zero(),
		.0f,
		WHITE
	);
}

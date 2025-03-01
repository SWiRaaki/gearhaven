#ifndef GEARHAVEN_H
#define GEARHAVEN_H

// General includes relevant for practically everywhere //
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Better typedefs for signed integers

/// @brief Signed 8-bit integer
typedef int8_t Int8, SByte, i8;
/// @brief Signed 16-bit integer
typedef int16_t Int16, Short, i16;
/// @brief Signed 32-bit integer
typedef int32_t Int32, Integer, i32;
/// @brief Signed 64-bit integer
typedef int64_t Int64, Long, i64;
/// @brief Signed biggest common integer
typedef intmax_t CommonInt, imx;

// Better typedefs for unsigned integers

/// @brief Unsigned 8-bit integer
typedef uint8_t UInt8, Byte, u8;
/// @brief Unsigned 16-bit integer
typedef uint16_t UInt16, Word, UShort, u16;
/// @brief Unsigned 32-bit integer
typedef uint32_t UInt32, DWord, UInteger, u32;
/// @brief Unsigned 64-bit integer
typedef uint64_t UInt64, QWord, ULong, u64;
/// @brief Unsigned biggest common integer
typedef uintmax_t UIntMax, CommonUInt, umx;

/// @brief Single precision float
typedef float Single, f32;
/// @brief Double precision float
typedef double Double, f64;
/// @brief Extented precission float
typedef long double LongDouble, LDouble, fld;

// Global variables that may be relevant for other parts of the code
// none

// All exposed funcions relevant to run the game

// -------- Component Interface -------- \\

/**
 * @brief Initialization function that prepares the pre-loop resources
 */
void gh_init( void );

/**
 * @brief Update function that is called at the start of the loop
 */
void gh_update( void );

/**
 * @brief Draw function that is called after update is finished
 */
void gh_draw(  void );

/**
 * @brief Close function that marks the end of the lifecycle
 */
void gh_close( void );

// -------- Game Instance -------- \\

/**
 * @brief flag indicating if the game should keep running
 */
bool gh_running( void );

/**
 * @brief Retrieve the currently used resolution width of the game
 */
f32 gh_getResolutionWidth( void );

/**
 * @brief Retrieve the currently used Resolution height of the game
 */
f32 gh_getResolutionHeight( void );

#endif // GEARHAVEN_H

#pragma once

enum class Background {
	BLACK = 0,
	DARKBLUE = BACKGROUND_BLUE,
	DARKGREEN = BACKGROUND_GREEN,
	DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
	DARKRED = BACKGROUND_RED,
	DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
	DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
	DARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	GRAY = BACKGROUND_INTENSITY,
	BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
	GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
	RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
	MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
	YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
	WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
};
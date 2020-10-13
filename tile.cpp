#include <map>
#include <cassert>
#include "tile.h"
#include <iostream>

// An anonymous namespace just here so you cannot access there from somewhere
// else.
namespace {

	// Map of the local space.
	std::string local_world = 
		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";

	// Local player stuff.
	Player local_player{};

	// Map that map space to enemies.
	std::map<std::pair<int, int>, Enemy> local_enemy;

	int xy_local(int x, int y)
	{
		// We want the local array to be bound to the borders.
		if (x < 0) x = 0;
		if (x > 23) x = 23;
		if (y < 0) y = 0;
		if (y > 7) y = 7;
		// Return the position within the local world of the cursor.
		// As the array is singular dimention we use the largest value to
		// split it.
		return x + y * 24;
	}

} // End of namespace.


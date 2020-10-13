#include <vector>
#include "command.h"
#include "tile.h"
#include <iostream>
#include "character.h"
#include "player.h"
#include "world.h"
#include <stdio.h>
#include <math.h>   /* Unused header */
#include <stdlib.h> /* For `rand` and `srand` */
#include <time.h>   /* For `time` */

void Command::North()
{
	Player player = world.Get_player();

	if (world.Get_tile_at_position(player.GetX(), player.GetY() - 1) != '.')
		return;
	else
		player.SetY(player.GetY() - 1);
	world.Set_player(player);

}
void Command::South()
{
	Player player = world.Get_player();

	if (world.Get_tile_at_position(player.GetX(), player.GetY() + 1) != '.')
		return;
	else
		player.SetY(player.GetY() + 1);
	world.Set_player(player);

}

void Command::East()
{
	Player player = world.Get_player();

	if (world.Get_tile_at_position(player.GetX() + 1, player.GetY()) != '.')
		return;
	else
		player.SetX(player.GetX() + 1);
	world.Set_player(player);

}

void Command::West()
{
	Player player = world.Get_player();

	if (world.Get_tile_at_position(player.GetX() - 1, player.GetY()) != '.')
		return;
	else
		player.SetX(player.GetX() - 1);
	world.Set_player(player);

}

void Command::Attack()
{
	Player player = world.Get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX(), player.GetY() - 1))
		enemy_vec.push_back(world.Get_enemy(player.GetX(), player.GetY() - 1));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX(), player.GetY() + 1))
		enemy_vec.push_back(world.Get_enemy(player.GetX(), player.GetY() + 1));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX() - 1, player.GetY()))
		enemy_vec.push_back(world.Get_enemy(player.GetX() - 1, player.GetY()));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX() + 1, player.GetY()))
		enemy_vec.push_back(world.Get_enemy(player.GetX() + 1, player.GetY()));
	for (const auto& enemy : enemy_vec)
	{
		enemy.Set_health(enemy.Get_health() - player.Get_attack() + enemy.Get_defense());
	}
}

void Command::Tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = world.Get_player();
	player.Get_health() += player.Get_health_regen();
	player.Get_health() = 
		std::min(player.Get_health(), player.Get_max_health();


	std::vector<Enemy> enemy_vec;
	srand(time(NULL)); /* Seed `rand` with the current time */
	int i;
	for (int i = 0; i < 5; i++)
	{
		i = rand() % 4;
		return i;
	}
	switch (i)
	{
	case 1: i = 1;
		world.Get_enemy(enemy.GetX(), enemy.GetY())
		enemy_vec.push_back(world.Set_enemy(enemy.SetX(), enemy.SetY() + 1));
		break;

	case 2: i = 2;
		world.Get_enemy(enemy.GetX(), enemy.GetY())
		enemy_vec.push_back(world.Set_enemy(enemy.SetX(), enemy.SetY() - 1))
		break;

	case 3: i = 3;
		world.Get_enemy(enemy.GetX(), enemy.GetY())
		enemy_vec.push_back(world.Set_enemy(enemy.SetX() + 1, enemy.SetY()))
		break;

	case 4: i = 4
		world.Get_enemy(enemy.GetX(), enemy.GetY())
		enemy_vec.push_back(world.Set_enemy(enemy.SetX() - 1, enemy.SetY()))
		break;
	}

	Player player = world.Get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX(), player.GetY() - 1))
		enemy_vec.push_back(world.Get_enemy(player.GetX(), player.GetY() - 1));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX(), player.GetY() + 1))
		enemy_vec.push_back(world.Get_enemy(player.GetX(), player.GetY() + 1));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX() - 1, player.GetY()))
		enemy_vec.push_back(world.Get_enemy(player.GetX() - 1, player.GetY()));
	if (TileType::ENEMY == world.Get_tile_at_position(player.GetX() + 1, player.GetY()))
		enemy_vec.push_back(world.Get_enemy(player.GetX() + 1, player.GetY()));
	for (const auto& enemy : enemy_vec)
	{
		player.Set_health(player.Get_health() - enemy.Get_attack() + player.Get_defense());
	}

	
}

void Command::Show_state()
{
	Player player = world.Get_player();
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			std::cout
				<< " | "
				<< (char)world.Get_tile_at_position(player.GetX() + j, player.GetY() + i);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
	std::cout << "Player(" << player.GetX() << ", " << player.GetY() << ") :\n";
	std::cout << "\tname       : " << player.name << "\n";    //faire avec print
	std::cout << "\thit points : " << player.Get_health() << "\n";
	std::cout << "\n";
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			if (TileType::ENEMY ==
				world.Get_tile_at_position(player.GetX() + i, player.GetY() + j))
			{
				Enemy enemy = world.Get_enemy(player.GetX() + i, player.GetY() + j);
				std::cout
					<< "Enemy(" << player.GetX() + i
					<< ", " << player.GetY() + j
					<< ")\n";
				std::cout << "\tname       : " << enemy.name << "\n";
				std::cout << "\thit points : " << enemy.Get_health() << "\n";
				std::cout << "\n";
			}
		}
	}
}

char Command::Get_command()
{

	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	switch (command_str[0])
	{
	case 'q':
		return Command::Quit;
	case 'n':
		return Command::North;
	case 's':
		return Command::South;
	case 'e':
		return Command::East;
	case 'w':
		return Command::West;
	case 'a':
		return Command::Attack;
	case 'h':
	default:
		Show_help();
		return Command::Help;
	}
}
void Command::Show_description(Enemy enemy)
{
	std::cout << "Gob" << "\nHealth points : " << enemy.Get_health() << "\nattack : " << enemy.Get_attack() << "\ndefense : " << enemy.Get_defense();
}

void Command::Show_help()
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit  -> quit the game.\n";
	std::cout << "\t[n]orth -> move north.\n";
	std::cout << "\t[s]outh -> move south.\n";
	std::cout << "\t[e]ast  -> move east.\n";
	std::cout << "\t[w]est  -> move west.\n";
	std::cout << "\t[a]ttack-> attack an enemy\n";
	// TODO fill up the rest!
	// See the list of command in the tile.h.
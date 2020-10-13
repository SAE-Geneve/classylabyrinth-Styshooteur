#include <iostream>
#include "tile.h"
#include "command.h"


	int main()
	{
		std::cout << "Welcome in the Maze!\n";
		Command::Show_help();
		while (true)
		{
			Command::Show_state();
			Command command_str = Command::Get_command();
			switch (command_str)
			{
			case Command::Quit:
				std::cout << "bye!\n";
				return 0;
			case Command::North:
				North();
				Tick();
				break;
			case Command::South:
				South();
				Tick();
				break;
			case Command::East:
				East();
				Tick();
				break;
			case Command::West:
				West();
				Tick();
				break;
			case Command::Attack:
				Attack();
				Tick();
				break;
			case Command::Help:
			default:
				Tick();
				break;
			}
		}
		return 0;
	};


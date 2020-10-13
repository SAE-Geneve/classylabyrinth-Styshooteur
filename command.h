#pragma once
#include "world.h"
#include "tile.h"
class Command {
public:
    void Quit();
    void Help();
    void North();
    void South();
    void East();
    void West();
    void Attack();
    void Tick();
    void Show_state();
    void Show_description();
    void Show_help();
    void Get_command();
private:
    World world;
};
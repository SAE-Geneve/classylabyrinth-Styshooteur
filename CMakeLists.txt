cmake_minimum_required(VERSION 3.14)

if(WIN32)
	add_compile_options("/std:c++latest")
endif(WIN32)

set(CMAKE_CXX_STANDARD 17)

project(BasicLabyrinth)

add_executable(BasicLabyrinth
	${PROJECT_SOURCE_DIR}/command.cpp
	${PROJECT_SOURCE_DIR}/command.h
	${PROJECT_SOURCE_DIR}/tile.cpp
	${PROJECT_SOURCE_DIR}/tile.h
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/character.h
	${PROJECT_SOURCE_DIR}/character.cpp
	${PROJECT_SOURCE_DIR}/world.h
	${PROJECT_SOURCE_DIR}/world.cpp
	${PROJECT_SOURCE_DIR}/player.h
	${PROJECT_SOURCE_DIR}/player.cpp
	${PROJECT_SOURCE_DIR}/enemy.h
	${PROJECT_SOURCE_DIR}/enemy.cpp
)

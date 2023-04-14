cmake_minimum_required(VERSION 3.23)
project(CastleSmasher)

set(CMAKE_CXX_STANDARD 14)

add_executable(CastleSmasher main.cpp Node.h LinkedList.cpp LinkedList.h Background.cpp Background.h SandCastle.cpp SandCastle.h Charlie.cpp Charlie.h CastleAndCharlie.cpp CastleAndCharlie.h Dave.cpp Dave.h Play.cpp Play.h)

target_link_libraries(CastleSmasher sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

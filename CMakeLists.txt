cmake_minimum_required(VERSION 3.20)
project(PrisonersDilemma)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrisonersDilemma main.cpp ClassMatrix.h ClassMatrix.cpp ClassGame.h ClassGame.cpp
        Strtegies/ClassStrategy.h Strtegies/ClassStrategy.cpp Strtegies/Strategy_1.h Strtegies/Strategy_2.h
        Strtegies/Strategy_3.h Strtegies/Strategy_4.h Strtegies/Strategy_1.cpp Strtegies/Strategy_2.cpp
        Strtegies/Strategy_3.cpp Strtegies/Strategy_4.cpp Strtegies/TheStrategyFactory.h Strtegies/TheStrategyFactory.cpp
        Strtegies/StrategyFactoryRegistration.h Strtegies/HistoryOfMoves.h Strtegies/HistoryOfMoves.cpp Parser/Parser.h
        Parser/Parser.cpp Detailed.h Detailed.cpp Fast.h Fast.cpp)

set(Boost_INCLUDE_DIR C:/MinGW/include/)
set(Boost_LIBRARY_DIR C:/MinGW/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(PrisonersDilemma PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(PrisonersDilemma ${Boost_LIBRARIES})
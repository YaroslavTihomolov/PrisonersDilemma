cmake_minimum_required(VERSION 3.20)
project(PrisonersDilemma)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(PrisonersDilemma Matrix/ClassMatrix.h
        Matrix/ClassMatrix.cpp GameModes/ClassGame.h GameModes/ClassGame.cpp
        Strtegies/ClassStrategy.h Strtegies/ClassStrategy.cpp Strtegies/Strategy_1/Strategy_1.h Strtegies/Strategy_2/Strategy_2.h
        Strtegies/Strategy_3/Strategy_3.h Strtegies/Strategy_4/Strategy_4.h Strtegies/Strategy_1/Strategy_1.cpp Strtegies/Strategy_2/Strategy_2.cpp
        Strtegies/Strategy_3/Strategy_3.cpp Strtegies/Strategy_4/Strategy_4.cpp Strtegies/StrategyFactory/TheStrategyFactory.h
        Strtegies/StrategyFactory/TheStrategyFactory.cpp
        Strtegies/StrategyFactory/StrategyFactoryRegistration.h Strtegies/Moves_History/HistoryOfMoves.h
        Strtegies/Moves_History/HistoryOfMoves.cpp Parser/Parser.h
        Parser/Parser.cpp GameModes/Detailed/Detailed.h GameModes/Detailed/Detailed.cpp GameModes/Fast/Fast.h GameModes/Fast/Fast.cpp GameModes/Tournament/Tournament.h
        GameModes/Tournament/Tournament.cpp Strtegies/Strategy_5/Strategy_5.h Strtegies/Strategy_5/Strategy_5.cpp Test.cpp
        Strtegies/InputInformation/Input.h Strtegies/InputInformation/Input.cpp Strtegies/Strategy_6/Strategy_6.h Strtegies/Strategy_6/Strategy_6.cpp)

target_link_libraries(PrisonersDilemma gtest_main)

set(Boost_INCLUDE_DIR C:/MinGW/include/)
set(Boost_LIBRARY_DIR C:/MinGW/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(PrisonersDilemma PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(PrisonersDilemma ${Boost_LIBRARIES})
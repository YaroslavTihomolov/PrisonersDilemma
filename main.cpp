#include "ClassGame.h"
#include <iostream>

int main() {
    std::string mode;
    std::cout << "Print type of mode (detailed|fast|tournament)"<< std::endl;
    while (std::cin >> mode && mode != "detailed" && mode != "fast" && mode != "tournament")
        cout << "Choose between detailed|fast|tournament" << "\n";
    int s_1 = 1, s_2 = 2, s_3 = 3;
    if (mode != "tournament") {
        std::cout << "Choose first strategy:" << std::endl;
        cin >> s_1;
        std::cout << "Choose second strategy:" << std::endl;
        cin >> s_2;
        std::cout << "Choose third strategy:" << std::endl;
        cin >> s_3;
    }
    Game game(s_1, s_2, s_3);
    int count_of_moves = 0;
    if (mode == "detailed")
        game.Detailed();
    else  {
        std::cout << "Print count of moves"<< std::endl;
        cin >> count_of_moves;
    }
    if (mode == "fast") {
        game.Fast(count_of_moves);
    }
    if (mode == "tournament") {
        game.Tournament(count_of_moves);
    }
    return 0;
}

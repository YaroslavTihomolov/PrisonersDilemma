#include "HPrisoners.h"

int main() {
    std::string mode;
    std::cout << "Print type of mode (detailed|fast|tournament)"<< std::endl;
    while (std::cin >> mode && mode != "detailed" && mode != "fast" && mode != "tournament")
        cout << "Choose between detailed|fast|tournament" << "\n";
    Strategy_1 strat_1;
    Strategy_2 strat_2;
    Strategy_3 strat_3;
    Game game(strat_1, strat_2, strat_3);
    if (mode == "detailed") game.Detailed();
    return 0;
}

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
    int count_of_moves = 0;
    if (mode == "fast") {
        std::cout << "Print count of moves"<< std::endl;
        cin >> count_of_moves;
        game.Fast(count_of_moves);
    }
    if (mode == "tournament") {
        for (int i = 0; i < 3; i + 3) {
            Game gam(game.ChooseStrategy(i + 1), game.ChooseStrategy(i + 2), game.ChooseStrategy(i + 3));
            std::cout << "Print count of moves"<< std::endl;
            cin >> count_of_moves;
            game.Fast(count_of_moves);
        }
    }
    return 0;
}

#include "ClassGame.h"
#include "Detailed/Detailed.h"
#include "Fast/Fast.h"
#include "Tournament/Tournament.h"

Game::Game(int argc, char** argv) {
    Parser input(argc, argv);
    InputInf::Instance().AddInfo(input);
    if (input.mode == "detailed")
        Detailed(input.name[0],std::string(input.name[1]),
                 std::string(input.name[2]), input.matrix_file);

    if (input.mode == "fast")
        Fast(std::string(input.name[0]), std::string(input.name[1]),
             std::string(input.name[2]), input.matrix_file, input.count_of_steps);

    if (input.mode == "tournament")
        Tournament(input.matrix_file, input.count_of_steps);
}


int Game::NumberOfVariant () {
    return (cur_step3 - 'C') * 4 + (cur_step2 - 'C') * 2 + (cur_step1 - 'C') * 1;
}

void Game::AddPointsAndAddMove(int number_of_variant) {
    MovesHistory::Instance().AddMoves(cur_step1, cur_step2, cur_step3);
    participant_1->points += matrix.game_matrix[number_of_variant][0];
    participant_2->points += matrix.game_matrix[number_of_variant][1];
    participant_3->points += matrix.game_matrix[number_of_variant][2];
}


void Game::OutputResult() {
    cout << participant_1->GetName() << " points:" << participant_1->points << '\n';
    cout << participant_2->GetName() << " points:" << participant_2->points << '\n';
    cout << participant_3->GetName() << " points:" << participant_3->points << '\n';
}

void Game::OutputCurMove(int number) {
    cout << participant_1->GetName() << " "<< participant_2->GetName() <<" "<< participant_3->GetName() <<"\n";
    cout << cur_step1 << "  " << cur_step2 << "  " << cur_step3 << '\n';
    cout << matrix.game_matrix[number][0]<< "  " << matrix.game_matrix[number][1] << "  " << matrix.game_matrix[number][2] << '\n';
}

void Game::ChooseStrategy(std::string s_1, std::string s_2, std::string s_3) {
    participant_1 = TheStrategyFactory::Instance().CreateStrategy(s_1);
    participant_2 = TheStrategyFactory::Instance().CreateStrategy(s_2);
    participant_3 = TheStrategyFactory::Instance().CreateStrategy(s_3);
    participant_1->AddNum(1);
    participant_2->AddNum(2);
    participant_3->AddNum(3);
}

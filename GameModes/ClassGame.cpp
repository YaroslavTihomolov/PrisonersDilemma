#include "ClassGame.h"
#include "Detailed/Detailed.h"
#include "Fast/Fast.h"
#include "Tournament/Tournament.h"

Game::Game(int argc, char** argv) {
    Parser input(argc, argv);
    if (input.mode == "detailed")
        Detailed(NameFromStringToChar(input.name[0]),
                 NameFromStringToChar(input.name[1]),
                 NameFromStringToChar(input.name[2]),
                 input.matrix_file);

    if (input.mode == "fast")
        Fast(NameFromStringToChar(input.name[0]),
             NameFromStringToChar(input.name[1]),
             NameFromStringToChar(input.name[2]),
             input.matrix_file, input.count_of_steps);

    if (input.mode == "tournament")
        Tournament(input.matrix_file, input.count_of_steps);
}

int Game::NameFromStringToChar(std::string tmp) {
    if (tmp == "ALWAYS_C") return 1;
    if (tmp == "ALWAYS_D") return 2;
    if (tmp == "RANDOM_MOVE") return 3;
    if (tmp == "TIT_FOR_TAT") return 4;
    if (tmp == "GRIM_TRIGGER") return 5;
    throw("Wrong input");
}

int Game::NumberOfVariant () {
    if (cur_step1 == 'C' && cur_step2 == 'C' && cur_step3 == 'C') return 0;
    if (cur_step1 == 'C' && cur_step2 == 'C' && cur_step3 == 'D') return 1;
    if (cur_step1 == 'C' && cur_step2 == 'D' && cur_step3 == 'C') return 2;
    if (cur_step1 == 'D' && cur_step2 == 'C' && cur_step3 == 'C') return 3;
    if (cur_step1 == 'C' && cur_step2 == 'D' && cur_step3 == 'D') return 4;
    if (cur_step1 == 'D' && cur_step2 == 'C' && cur_step3 == 'D') return 5;
    if (cur_step1 == 'D' && cur_step2 == 'D' && cur_step3 == 'C') return 6;
    return 7;
}

void Game::AddPointsAndAddMove(int number_of_variant) {
    MovesHistory::Instance().AddMoves(cur_step1, cur_step2, cur_step3);
    participant_1->points += matrix.game_matrix[number_of_variant][0];
    participant_2->points += matrix.game_matrix[number_of_variant][1];
    participant_3->points += matrix.game_matrix[number_of_variant][2];
}

void Game::ChooseWinner(int &max_points, int &num_of_winner, int i, int j, int h) {
    int cur_max, num_of_cur_winner;
    if (participant_1->points > participant_2->points && participant_1->points > participant_3->points) {
        cur_max = participant_1->points;
        num_of_cur_winner = i;
    } else if (participant_2->points > participant_3->points) {
        cur_max = participant_2->points;
        num_of_cur_winner = j;
    } else {
        cur_max = participant_3->points;
        num_of_cur_winner = h;
    }
    if (cur_max > max_points) {
        max_points = cur_max;
        num_of_winner = num_of_cur_winner;
    }
}


void Game::OutputResult() {
    cout << "s" << participant_1->GetNum() << " points:" << participant_1->points << '\n';
    cout << "s" << participant_2->GetNum() << " points:" << participant_2->points << '\n';
    cout << "s" << participant_3->GetNum() << " points:" << participant_3->points << '\n';
}

void Game::OutputCurMove(int number) {
    cout << "s" << participant_1->GetNum() << " s"<< participant_2->GetNum() <<" s"<< participant_3->GetNum() <<"\n";
    cout << cur_step1 << "  " << cur_step2 << "  " << cur_step3 << '\n';
    cout << matrix.game_matrix[number][0]<< "  " << matrix.game_matrix[number][1] << "  " << matrix.game_matrix[number][2] << '\n';
}

void Game::ChooseStrategy(int s_1, int s_2, int s_3) {
    participant_1 = TheStrategyFactory::Instance().CreateStrategy(s_1);
    participant_2 = TheStrategyFactory::Instance().CreateStrategy(s_2);
    participant_3 = TheStrategyFactory::Instance().CreateStrategy(s_3);
    participant_1->AddNum(1);
    participant_2->AddNum(2);
    participant_3->AddNum(3);
}


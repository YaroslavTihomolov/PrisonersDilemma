//
// Created by я on 22.10.2022.
//
#include "HPrisoners.h"

char Strategy_1::Move() {
    return 'C';
}

char Strategy_2::Move() {
    return 'D';
}

char Strategy_3::Move() {
    srand(time(NULL));
    int number = (rand() % 100000) % 2;
    if (number == 0) return 'C';
    else return 'D';
}

Matrix::Matrix() {
    ifstream fin;
    fin.open("Matrix.txt");
    char symbol;
    int count_of_digit = 0;
    while (fin >> symbol && symbol != EOF) {
        if (count_of_digit >= 6 && isdigit(symbol))
            game_matrix[(count_of_digit - 6) / 3][count_of_digit % 3] = symbol - '0';
        if (isdigit(symbol)) count_of_digit++;
    }
}

char Strategy::Move() {
    return 0;
}

void Game::Detailed(){
    string flag;
    while (true) {
        std::cout << "Press any button for next step or 'quit' for end game"<< std::endl;
        cin >> flag;
        if (flag == "quit") break;
        cur_step1 = strat_1.Move();
        cur_step2 = strat_2.Move();
        cur_step3 = strat_3.Move();
        AddPoints(NumberOfVariant());
        Output(NumberOfVariant());
    }
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

Game::Game(Strategy & s_1, Strategy & s_2, Strategy & s_3):
    strat_1(s_1), strat_2(s_2), strat_3(s_3) {}

void Game::AddPoints(int number_of_variant) {
    strat_1.points += matrix.game_matrix[number_of_variant][0];
    strat_2.points += matrix.game_matrix[number_of_variant][1];
    strat_3.points += matrix.game_matrix[number_of_variant][2];
}

void Game::Output(int number) {
    cout << "s1 " << "s2 "<<"s3\n";
    cout << cur_step1 << "  " << cur_step2 << "  " << cur_step3 << '\n';
    cout << matrix.game_matrix[number][0]<< "  " << matrix.game_matrix[number][1] << "  " << matrix.game_matrix[number][2] << '\n';
    cout << "s1 points:" << strat_1.points << '\n';
    cout << "s2 points:" << strat_2.points << '\n';
    cout << "s3 points:" << strat_3.points << '\n';
}

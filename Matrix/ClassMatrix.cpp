//
// Created by я on 22.10.2022.
//
#include "ClassMatrix.h"

void Matrix::ReadMatrix(std::string file_name) {
    std::ifstream fin;
    fin.open(file_name);
    char symbol;
    int count_of_digit = 0;
    while (fin >> symbol && symbol != EOF) {
        if (count_of_digit >= 6 && isdigit(symbol))
            game_matrix[(count_of_digit - 6) / 3][count_of_digit % 3] = symbol - '0';
        if (isdigit(symbol)) count_of_digit++;
    }
}
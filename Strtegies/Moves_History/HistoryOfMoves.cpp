//
// Created by я on 05.11.2022.
//
#include "HistoryOfMoves.h"

void MovesHistory::AddMoves(char m_1, char m_2, char m_3) {
    matrix.push_back(m_1);
    matrix.push_back(m_2);
    matrix.push_back(m_3);
}

void MovesHistory::Clear() {
    matrix.clear();
}

std::vector<char> MovesHistory::Last_3_Moves() {
    std::vector<char> tmp;
    for (auto it = matrix.end() - 3; it < matrix.end(); it++)
        tmp.push_back(*it);
    return tmp;
}

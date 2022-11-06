//
// Created by я on 04.11.2022.
//
#include "Strategy_4.h"

char Strategy_4::Move() {
    std::ifstream conf("conf4.txt", std::ifstream::in);
    if (!conf)
        throw ("File \"conf4.txt\" not open");
    char FirstMove;
    conf.get(FirstMove);
    char NumOfRepeatStrategy;
    conf.get(NumOfRepeatStrategy);
    if (count_of_moves++ == 0)
        return FirstMove;
    std::vector<char> tmp = MovesHistory::Instance().Last_3_Moves();
    int index = (num_in_cur_game + NumOfRepeatStrategy - '0' - 1) % 3;
    return tmp[index];
}

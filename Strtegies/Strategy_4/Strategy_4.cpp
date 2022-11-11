//
// Created by я on 04.11.2022.
//
#include "Strategy_4.h"

Strategy_4::Strategy_4() {
    num_of_strategy = 4;
    conf.open("conf4.txt");
    if (!conf) throw ("File \"conf4.txt\" not open");
    conf.get(FirstMove);
    conf.get(NumOfRepeatStrategy);
}

char Strategy_4::Move() {
    if (count_of_moves++ == 0)
        return FirstMove;
    std::vector<char> tmp = MovesHistory::Instance().Last_3_Moves();
    int index = (num_in_cur_game + NumOfRepeatStrategy - '0' - 1) % 3;
    return tmp[index];
}

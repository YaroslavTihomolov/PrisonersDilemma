//
// Created by я on 10.11.2022.
//
#include "Strategy_5.h"

Strategy_5::Strategy_5() {
    name_of_strategy = "GRIM_TRIGGER";
    count_of_moves = 0;
    conf.open(InputInf::Instance().GetName(5));
    if (!conf) throw ("File \"conf5.txt\" not open");
    conf.get(NumOfStrategy);
    flag = 0;
}

char Strategy_5::Move() {
    if (count_of_moves++ == 0) return 'C';
    if (flag == 0) {
        std::vector<char> tmp = MovesHistory::Instance().Last_3_Moves();
        int index = (num_in_cur_game + NumOfStrategy - '0' - 1) % 3;
        flag = (tmp[index] == 'D')? 1: 0;
    }
    if (flag == 1) return 'D';
    return 'C';
}

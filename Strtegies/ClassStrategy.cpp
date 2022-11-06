#include "ClassStrategy.h"

char Strategy::Move() {
    return 0;
}

void Strategy::AddNum(int num) {
    num_in_cur_game = num;
}

int Strategy::GetNum() {
    return num_of_strategy;
}

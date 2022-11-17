#include "ClassStrategy.h"

char Strategy::Move() {
    return 0;
}

void Strategy::AddNum(int num) {
    num_in_cur_game = num;
}

std::string Strategy::GetName() {
    return name_of_strategy;
}

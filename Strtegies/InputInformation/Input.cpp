//
// Created by я on 15.11.2022.
//
#include "Input.h"

void InputInf::AddInfo(Parser copy) {
    input = copy;
}

std::string InputInf::GetName(int num) {
    return input.conf_files[num - 4];
}

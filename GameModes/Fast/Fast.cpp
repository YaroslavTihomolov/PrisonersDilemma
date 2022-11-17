//
// Created by я on 10.11.2022.
//
#include "Fast.h"

Fast::Fast(std::string s_1, std::string s_2, std::string s_3, std::string matrix_file, int count_of_moves){
    ChooseStrategy(s_1, s_2, s_3);
    matrix.ReadMatrix(matrix_file);
    string flag;
    for (int i = 0; i < count_of_moves; i++) {
        cur_step1 = participant_1->Move();
        cur_step2 = participant_2->Move();
        cur_step3 = participant_3->Move();
        AddPointsAndAddMove(NumberOfVariant());
    }
    OutputResult();
}

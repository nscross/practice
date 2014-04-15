#include <stdio.h>
#include <stdlib.h>
#include "puzzle_cube.h"

PuzzleCubeSide::PuzzleCubeSide()
{
    u_ = NULL;
    d_ = NULL;
    l_ = NULL;
    r_ = NULL;
    f_ = NULL;
    b_ = NULL;
}

void PuzzleCubeSide::Rotate(const int direction, const int deg)
{
    if (direction == 1)
    {
        char temp = f_->side[0][0];
        f_side[0][0] = f_->side[1][0];
        f_side[1][0] = f_->side[2][0];
        f_side[2][0] = f_->side[2][1];
        f_side[2][1] = f_->side[2][2];
        f_side[2][2] = f_->side[1][2];
        f_side[1][2] = f_->side[0][2];
        f_side[0][2] = f_->side[0][1];
        f_side[0][1] = temp;
        
        char temp_right_1 = r_->side[0][0];
        char temp_right_2 = r_->side[1][0];
        char temp_right_3 = r_->side[2][0];
        
        r_->side[0][0] = u_->side[2][0];
        r_->side[1][0] = u_->side[2][1];
        r_->side[2][0] = u_->side[2][2];
        
        u_->side[2][0] = l_->side[0][2];
        u_->side[2][1] = l_->side[1][2];
        u_->side[2][2] = l_->side[2][2];
        
        l_->side[0][2] = d_->side[0][0];
        l_->side[1][2] = d_->side[0][1];
        l_->side[2][2] = d_->side[0][2];
        
        d_->side[0][0] = temp_right_1;
        d_->side[0][1] = temp_right_2;
        d_->side[0][2] = temp_right_3;
    }
}

void PuzzleCubeSide::SetSides(PuzzleCubeSide* u, PuzzleCubeSide* d, PuzzleCubeSide* l,
        PuzzleCubeSide* r, PuzzleCubeSide* f, PuzzleCubeSide* b)
{
    u_ = u;
    d_ = d;
    l_ = l;
    r_ = r;
    f_ = f;
    b_ = b;
}
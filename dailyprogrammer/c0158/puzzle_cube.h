#ifndef DAILYPROGRAMMER_C0158_PUZZLE_CUBE_H_
#define DAILYPROGRAMMER_C0158_PUZZLE_CUBE_H_

class PuzzleCubeSide
{
 public:
    static const int kNumberOfRows = 3;
    static const int kNumberOfColumns = 3;    
    PuzzleCubeSide();
    void Rotate(const int direction, const int deg);
    void SetSides(PuzzleCubeSide* u, PuzzleCubeSide* d, PuzzleCubeSide* l,
        PuzzleCubeSide* r, PuzzleCubeSide* f, PuzzleCubeSide* b);
    char side_[kNumberOfRows][kNumberOfColumns];
    PuzzleCubeSide* u_;
    PuzzleCubeSide* d_;
    PuzzleCubeSide* l_;
    PuzzleCubeSide* r_;
    PuzzleCubeSide* f_;
    PuzzleCubeSide* b_;

    
};

class PuzzleCube
{
 public:
    
    static const int kNumberOfSides = 6;
    PuzzleCube();
    
 private:
    PuzzleCubeSide u_;
    PuzzleCubeSide d_;
    PuzzleCubeSide l_;
    PuzzleCubeSide r_;
    PuzzleCubeSide f_;
    PuzzleCubeSide b_;
};

#endif
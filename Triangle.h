#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(int x, int y, int height);
    void draw(char** board, int boardWidth, int boardHeight) const override;

private:
    int x, y, height;
};

#endif // TRIANGLE_H
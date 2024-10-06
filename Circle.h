#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int centerX, int centerY, int radius);
    void draw(char** board, int boardWidth, int boardHeight) const override;

private:
    int centerX, centerY, radius;
};

#endif // CIRCLE_H
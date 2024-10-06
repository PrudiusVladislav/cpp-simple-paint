#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height);
    void draw(char** board, int boardWidth, int boardHeight) const override;

private:
    int x, y, width, height;
};

#endif // RECTANGLE_H
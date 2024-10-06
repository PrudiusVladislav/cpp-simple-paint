#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
public:
    Line(int x1, int y1, int x2, int y2);
    void draw(char** board, int boardWidth, int boardHeight) const override;

private:
    int x1, y1, x2, y2;
};

#endif // LINE_H
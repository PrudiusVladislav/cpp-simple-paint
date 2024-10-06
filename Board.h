#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Shape.h"

class Board {
public:
    Board(int width, int height);
    ~Board();
    void addShape(const Shape* shape);
    void draw() const;

private:
    int width, height;
    std::vector<const Shape*> shapes;
    char** grid;
    void clearGrid() const;
    void drawBorder() const;
};

#endif // BOARD_H
#include <iostream>
#include "Board.h"
#include "Rectangle.h"

int main() {
    Board board(80, 25);
    Rectangle rect(-5, -5, 20, 10);
    board.addShape(&rect);
    board.draw();
    return 0;
}
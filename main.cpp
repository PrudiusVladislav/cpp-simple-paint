#include <iostream>
#include "Board.h"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"

int main() {
    Board board(80, 25);
    // Rectangle rect(10, 5, 20, 10);
    // Line line(0, 0, 79, 10);
    Circle circle(38, 12, 10);
    // board.addShape(&rect);
    // board.addShape(&line);
    board.addShape(&circle);
    board.draw();
    return 0;
}
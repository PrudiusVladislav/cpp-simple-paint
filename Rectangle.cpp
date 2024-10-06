#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

void Rectangle::draw(char** board, int boardWidth, int boardHeight) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int posX = x + j;
            int posY = y + i;
            if (posX >= 0 && posX < boardWidth && posY >= 0 && posY < boardHeight) {
                board[posY][posX] = '*';
            }
        }
    }
}
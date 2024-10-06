#include "Triangle.h"

Triangle::Triangle(int x, int y, int height)
    : x(x), y(y), height(height) {}

void Triangle::draw(char** board, int boardWidth, int boardHeight) const {
    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;
        int rightMost = x + i;
        int posY = y + i;

        if (posY >= 0 && posY < boardHeight) {
            if (leftMost >= 0 && leftMost < boardWidth) {
                board[posY][leftMost] = '*';
            }
            if (rightMost >= 0 && rightMost < boardWidth && leftMost != rightMost) {
                board[posY][rightMost] = '*';
            }
        }
    }

    for (int j = 0; j < 2 * height - 1; ++j) {
        int baseX = x - height + 1 + j;
        int baseY = y + height - 1;

        if (baseX >= 0 && baseX < boardWidth && baseY < boardHeight) {
            board[baseY][baseX] = '*';
        }
    }
}
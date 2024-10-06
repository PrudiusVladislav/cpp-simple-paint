#include "Circle.h"
#include <cmath>

Circle::Circle(int centerX, int centerY, int radius)
    : centerX(centerX), centerY(centerY), radius(radius) {}

void Circle::draw(char** board, int boardWidth, int boardHeight) const {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        if (centerX + x >= 0 && centerX + x < boardWidth && centerY + y >= 0 && centerY + y < boardHeight)
            board[centerY + y][centerX + x] = '*';
        if (centerX + y >= 0 && centerX + y < boardWidth && centerY + x >= 0 && centerY + x < boardHeight)
            board[centerY + x][centerX + y] = '*';
        if (centerX - y >= 0 && centerX - y < boardWidth && centerY + x >= 0 && centerY + x < boardHeight)
            board[centerY + x][centerX - y] = '*';
        if (centerX - x >= 0 && centerX - x < boardWidth && centerY + y >= 0 && centerY + y < boardHeight)
            board[centerY + y][centerX - x] = '*';
        if (centerX - x >= 0 && centerX - x < boardWidth && centerY - y >= 0 && centerY - y < boardHeight)
            board[centerY - y][centerX - x] = '*';
        if (centerX - y >= 0 && centerX - y < boardWidth && centerY - x >= 0 && centerY - x < boardHeight)
            board[centerY - x][centerX - y] = '*';
        if (centerX + y >= 0 && centerX + y < boardWidth && centerY - x >= 0 && centerY - x < boardHeight)
            board[centerY - x][centerX + y] = '*';
        if (centerX + x >= 0 && centerX + x < boardWidth && centerY - y >= 0 && centerY - y < boardHeight)
            board[centerY - y][centerX + x] = '*';

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}
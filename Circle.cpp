#include "Circle.h"
#include <sstream>
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
        if (centerX + y >= 0 && centerX + y < boardWidth && centerY - x >= 0 && centerY - x < boardHeight)
            board[centerY - x][centerX + y] = '*';
        if (centerX + x >= 0 && centerX + x < boardWidth && centerY - y >= 0 && centerY - y < boardHeight)
            board[centerY - y][centerX + x] = '*';
        if (centerX - x >= 0 && centerX - x < boardWidth && centerY + y >= 0 && centerY + y < boardHeight)
            board[centerY + y][centerX - x] = '*';
        if (centerX - y >= 0 && centerX - y < boardWidth && centerY + x >= 0 && centerY + x < boardHeight)
            board[centerY + x][centerX - y] = '*';
        if (centerX - y >= 0 && centerX - y < boardWidth && centerY - x >= 0 && centerY - x < boardHeight)
            board[centerY - x][centerX - y] = '*';
        if (centerX - x >= 0 && centerX - x < boardWidth && centerY - y >= 0 && centerY - y < boardHeight)
            board[centerY - y][centerX - x] = '*';

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

std::string Circle::serialize() const {
    std::ostringstream oss;
    oss << "Circle " << centerX << " " << centerY << " " << radius;
    return oss.str();
}

void Circle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> centerX >> centerY >> radius;
}

Circle * Circle::CreateInternal(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        return nullptr;
    }

    const int centerX = std::stoi(args[0]);
    const int centerY = std::stoi(args[1]);
    const int radius = std::stoi(args[2]);
    return new Circle(centerX, centerY, radius);
}

Circle * Circle::CreateEmptyInternal() {
    return new Circle(0, 0, 0);
}

#include "Circle.h"
#include <sstream>
#include <cmath>

Circle::Circle(bool filled, char color, int centerX, int centerY, int radius)
    : Shape(filled, color), centerX(centerX), centerY(centerY), radius(radius) {}

void Circle::draw(char** board, int boardWidth, int boardHeight) const {
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            int dx = j - centerX;
            int dy = i - centerY;
            int distanceSquared = dx * dx + dy * dy;
            int radiusSquared = radius * radius;
            if (distanceSquared <= radiusSquared) {
                if (filled || std::abs(distanceSquared - radiusSquared) < radius) {
                    board[i][j] = color;
                }
            }
        }
    }
}

bool Circle::contains(int x, int y) const {
    int dx = x - centerX;
    int dy = y - centerY;
    return (dx * dx + dy * dy <= radius * radius);
}

std::string Circle::serialize() const {
    std::ostringstream oss;
    oss << "Circle " << filled << ' ' << color << ' ' << centerX << ' ' << centerY << ' ' << radius;
    return oss.str();
}

void Circle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> filled >> color >> centerX >> centerY >> radius;
}

Circle* Circle::CreateInternal(const std::vector<std::string>& args) {
    if (args.size() != 5) {
        return nullptr;
    }

    const bool filled = args[0] == "fill";
    const char color = args[1][0];
    const int centerX = std::stoi(args[2]);
    const int centerY = std::stoi(args[3]);
    const int radius = std::stoi(args[4]);
    return new Circle(filled, color, centerX, centerY, radius);
}

Circle* Circle::CreateEmptyInternal() {
    return new Circle(false, 'b', 0, 0, 0);
}

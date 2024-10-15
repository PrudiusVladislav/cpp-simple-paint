#include "Triangle.h"
#include <sstream>

Triangle::Triangle(bool filled, char color, int x, int y, int height)
    : Shape(filled, color), x(x), y(y), height(height) {}

void Triangle::draw(char** board, int boardWidth, int boardHeight) const {
    int baseY = y + height;
    for (int i = y; i <= baseY && i < boardHeight; ++i) {
        int rowHeight = i - y;
        int startX = x - rowHeight;
        int endX = x + rowHeight;
        for (int j = startX; j <= endX && j < boardWidth; ++j) {
            if (filled || i == baseY || j == startX || j == endX) {
                board[i][j] = color;
            }
        }
    }
}

std::string Triangle::serialize() const {
    std::ostringstream oss;
    oss << "Triangle " << filled << ' ' << color << ' ' << x << ' ' << y << ' ' << height;
    return oss.str();
}

void Triangle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> filled >> color >> x >> y >> height;
}

Triangle* Triangle::CreateInternal(const std::vector<std::string>& args) {
    if (args.size() != 5) {
        return nullptr;
    }

    const bool filled = args[0] == "fill";
    const char color = args[1][0];
    const int x = std::stoi(args[2]);
    const int y = std::stoi(args[3]);
    const int height = std::stoi(args[4]);
    return new Triangle(filled, color, x, y, height);
}

Triangle * Triangle::CreateEmptyInternal() {
    return new Triangle(false, 'b', 0, 0, 0);
}

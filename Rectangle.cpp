#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(bool filled, char color, int x, int y, int width, int height)
    : Shape(filled, color), x(x), y(y), width(width), height(height) {}

void Rectangle::draw(char** board, int boardWidth, int boardHeight) const {
    for (int i = y; i < y + height && i < boardHeight; ++i) {
        for (int j = x; j < x + width && j < boardWidth; ++j) {
            if (filled || i == y || i == y + height - 1 || j == x || j == x + width - 1) {
                board[i][j] = color;
            }
        }
    }
}

bool Rectangle::contains(int x, int y) const {
    return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

std::string Rectangle::serialize() const {
    std::ostringstream oss;
    oss << "Rectangle " << filled << ' ' << color << ' ' << x << ' ' << y << ' ' << width << ' ' << height;
    return oss.str();
}

void Rectangle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> filled >> color >> x >> y >> width >> height;
}

Rectangle* Rectangle::CreateInternal(const std::vector<std::string>& args) {
    if (args.size() != 6) {
        return nullptr;
    }

    const bool filled = args[0] == "fill";
    const char color = args[1][0];
    const int x = std::stoi(args[2]);
    const int y = std::stoi(args[3]);
    const int width = std::stoi(args[4]);
    const int height = std::stoi(args[5]);
    return new Rectangle(filled, color, x, y, width, height);
}

Rectangle* Rectangle::CreateEmptyInternal() {
    return new Rectangle(false, 'b', 0, 0, 0, 0);
}

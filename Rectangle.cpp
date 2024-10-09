#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

void Rectangle::draw(char** board, int boardWidth, int boardHeight) const {
    for (int i = y; i < y + height && i < boardHeight; ++i) {
        for (int j = x; j < x + width && j < boardWidth; ++j) {
            board[i][j] = '*';
        }
    }
}

std::string Rectangle::serialize() const {
    std::ostringstream oss;
    oss << "Rectangle " << x << " " << y << " " << width << " " << height;
    return oss.str();
}

void Rectangle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> x >> y >> width >> height;
}

Rectangle * Rectangle::CreateInternal(const std::vector<std::string> &args) {
    if (args.size() != 4) {
        return nullptr;
    }

    const int x = std::stoi(args[0]);
    const int y = std::stoi(args[1]);
    const int width = std::stoi(args[2]);
    const int height = std::stoi(args[3]);
    return new Rectangle(x, y, width, height);
}

Rectangle * Rectangle::CreateEmptyInternal() {
    return new Rectangle(0, 0, 0, 0);
}

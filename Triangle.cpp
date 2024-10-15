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

bool Triangle::contains(int x, int y) const {
    int x1 = this->x;
    int y1 = this->y;
    int x2 = this->x - height + 1;
    int y2 = this->y + height - 1;
    int x3 = this->x + height - 1;
    int y3 = this->y + height - 1;

    int denominator = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
    int a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denominator;
    int b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denominator;
    int c = 1 - a - b;

    return a >= 0 && b >= 0 && c >= 0;
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

bool Triangle::edit(const std::vector<std::string> &params) {
    if (params.size() != 5) {
        return false;
    }

    filled = params[0] == "fill";
    color = params[1][0];
    x = std::stoi(params[2]);
    y = std::stoi(params[3]);
    height = std::stoi(params[4]);
    return true;
}

void Triangle::setColor(const std::string &color) {
    if (!color.empty()) {
        this->color = color[0];
    }
}

void Triangle::move(int x, int y) {
    this->x = x;
    this->y = y;
}

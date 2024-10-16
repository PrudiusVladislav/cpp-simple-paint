#include "Line.h"
#include <sstream>
#include <cmath>

Line::Line(bool filled, char color, int x1, int y1, int x2, int y2)
    : Shape(filled, color), x1(x1), y1(y1), x2(x2), y2(y2) {}

void Line::draw(char** board, int boardWidth, int boardHeight) const {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    int x = x1;
    int y = y1;

    while (true) {
        if (x >= 0 && x < boardWidth && y >= 0 && y < boardHeight) {
            board[y][x] = color;
        }
        if (x == x2 && y == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

bool Line::contains(int x, int y) const {
    double distance = std::abs((y2 - y1) * x - (x2 - x1) * y + x2 * y1 - y2 * x1) /
                      std::sqrt(std::pow(y2 - y1, 2) + std::pow(x2 - x1, 2));
    const double tolerance = 0.5;

    bool withinBoundingBox = (x >= std::min(x1, x2) && x <= std::max(x1, x2) &&
                              y >= std::min(y1, y2) && y <= std::max(y1, y2));

    return distance <= tolerance && withinBoundingBox;
}

std::string Line::serialize() const {
    std::ostringstream oss;
    oss << "Line " << filled << ' ' << color << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
    return oss.str();
}

void Line::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> filled >> color >> x1 >> y1 >> x2 >> y2;
}

Line* Line::CreateInternal(const std::vector<std::string>& args) {
    if (args.size() != 5) {
        return nullptr;
    }

    const bool filled = true;
    const char color = args[0][0];
    const int x1 = std::stoi(args[1]);
    const int y1 = std::stoi(args[2]);
    const int x2 = std::stoi(args[3]);
    const int y2 = std::stoi(args[4]);
    return new Line(filled, color, x1, y1, x2, y2);
}

Line* Line::CreateEmptyInternal() {
    return new Line(true, 'b', 0, 0, 0, 0);
}

bool Line::edit(const std::vector<std::string> &params) {
    if (params.size() != 5) {
        return false;
    }

    color = params[0][0];
    x1 = std::stoi(params[1]);
    y1 = std::stoi(params[2]);
    x2 = std::stoi(params[3]);
    y2 = std::stoi(params[4]);
    return true;
}

void Line::setColor(const std::string &color) {
    if (!color.empty()) {
        this->color = color[0];
    }
}

void Line::move(int x, int y) {
    x1 += x;
    y1 += y;
    x2 += x;
    y2 += y;
}

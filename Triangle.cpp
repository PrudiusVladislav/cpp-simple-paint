#include "Triangle.h"
#include <sstream>

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

std::string Triangle::serialize() const {
    std::ostringstream oss;
    oss << "Triangle " << x << " " << y << " " << height;
    return oss.str();
}

void Triangle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    iss >> type >> x >> y >> height;
}

Triangle * Triangle::CreateInternal(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        return nullptr;
    }

    const int x = std::stoi(args[0]);
    const int y = std::stoi(args[1]);
    const int height = std::stoi(args[2]);
    return new Triangle(x, y, height);
}

Triangle * Triangle::CreateEmptyInternal() {
    return new Triangle(0, 0, 0);
}

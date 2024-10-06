#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height);
    void draw(char** board, int boardWidth, int boardHeight) const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;

private:
    int x, y, width, height;
};

#endif // RECTANGLE_H
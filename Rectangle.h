#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "ShapeFactory.h"


class Rectangle :
    public ShapeFactory<Rectangle>,
    public Shape {
    int x, y, width, height;
    Rectangle(int x, int y, int width, int height);
public:
    void draw(char** board, int boardWidth, int boardHeight) const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    static Rectangle* CreateInternal(const std::vector<std::string>& args);
    static Rectangle* CreateEmptyInternal();
};

#endif // RECTANGLE_H
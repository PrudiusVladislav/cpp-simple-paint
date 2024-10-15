#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "ShapeFactory.h"

class Circle : public ShapeFactory<Circle>, public Shape {
public:
    void draw(char** board, int boardWidth, int boardHeight) const override;
    bool contains(int x, int y) const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    static Circle* CreateInternal(const std::vector<std::string>& args);
    static Circle* CreateEmptyInternal();
private:
    Circle(bool filled, char color, int centerX, int centerY, int radius);
    int centerX, centerY, radius;
};

#endif // CIRCLE_H
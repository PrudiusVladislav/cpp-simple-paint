#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "ShapeFactory.h"

class Triangle : public ShapeFactory<Triangle>, public Shape {
public:
    void draw(char** board, int boardWidth, int boardHeight) const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    static Triangle* CreateInternal(const std::vector<std::string>& args);
    static Triangle* CreateEmptyInternal();
private:
    Triangle(bool filled, char color, int x, int y, int height);
    int x, y, height;
};

#endif // TRIANGLE_H
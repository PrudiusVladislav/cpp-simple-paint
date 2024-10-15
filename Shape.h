#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    Shape(bool filled, char color) : filled(filled), color(color) {}
    virtual ~Shape() = default;
    virtual void draw(char** grid, int width, int height) const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
protected:
    bool filled;
    char color;
};

#endif // SHAPE_H
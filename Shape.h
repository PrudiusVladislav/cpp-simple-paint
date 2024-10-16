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
    virtual bool contains(int x, int y) const = 0;
    virtual bool edit(const std::vector<std::string>& params) = 0;
    virtual void setColor(const std::string& color) = 0;
    virtual void move(int x, int y) = 0;
protected:
    bool filled;
    char color;
};

#endif // SHAPE_H
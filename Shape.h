#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(char** board, int width, int height) const = 0;
};

#endif // SHAPE_H
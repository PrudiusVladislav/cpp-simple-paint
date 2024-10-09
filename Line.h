#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "ShapeFactory.h"

class Line : public ShapeFactory<Line>, public Shape {
public:
    void draw(char** board, int boardWidth, int boardHeight) const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    static Line* CreateInternal(const std::vector<std::string>& args);
    static Line* CreateEmptyInternal();
private:
    Line(int x1, int y1, int x2, int y2);
    int x1, y1, x2, y2;
};

#endif // LINE_H
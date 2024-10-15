#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Shape.h"

class Board {
public:
    Board(int width, int height);
    ~Board();
    void addShape(const Shape* shape);
    bool editSelectedShape(const std::vector<std::string>& params);
    void paintSelectedShape(const std::string& color);
    void moveSelectedShape(int x, int y);
    void removeLastShape();
    void removeSelectedShape();
    void draw() const;
    void clear();
    void save(const std::string& filePath) const;
    void load(const std::string& filePath);
    void select(int x, int y);
    Shape* getSelected() const;
    const std::vector<const Shape*>& getShapes() const;

private:
    int width, height;
    std::vector<const Shape*> shapes;
    std::vector<const Shape*> undoStack;
    char** grid;
    Shape* selected;
    void clearGrid() const;
    void drawBorder() const;
};

#endif // BOARD_H
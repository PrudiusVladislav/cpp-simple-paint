#include "Board.h"
#include <iostream>

Board::Board(int width, int height)
    : width(width), height(height) {
    grid = new char*[height];
    for (int i = 0; i < height; ++i) {
        grid[i] = new char[width];
    }
    clearGrid();
}

Board::~Board() {
    for (int i = 0; i < height; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Board::addShape(const Shape* shape) {
    shapes.push_back(shape);
}

void Board::draw() const {
    clearGrid();
    for (const Shape* shape : shapes) {
        shape->draw(grid, width, height);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::clearGrid() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = ' ';
        }
    }
}
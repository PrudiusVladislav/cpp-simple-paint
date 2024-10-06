#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"

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
    undoStack.clear(); // Clear the undo stack when a new shape is added
}

void Board::removeLastShape() {
    if (!shapes.empty()) {
        undoStack.push_back(shapes.back());
        shapes.pop_back();
    }
}

void Board::draw() const {
    clearGrid();
    for (const Shape* shape : shapes) {
        shape->draw(grid, width, height);
    }
    drawBorder();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::clear() {
    shapes.clear();
    undoStack.clear();
    clearGrid();
}

void Board::clearGrid() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = ' ';
        }
    }
}

void Board::drawBorder() const {
    for (int i = 0; i < width; ++i) {
        grid[0][i] = '-';
        grid[height - 1][i] = '-';
    }
    for (int i = 0; i < height; ++i) {
        grid[i][0] = '|';
        grid[i][width - 1] = '|';
    }
    grid[0][0] = '+';
    grid[0][width - 1] = '+';
    grid[height - 1][0] = '+';
    grid[height - 1][width - 1] = '+';
}

void Board::save(const std::string& filePath) const {
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filePath << std::endl;
        return;
    }

    outFile << width << " " << height << std::endl;
    for (const Shape* shape : shapes) {
        outFile << shape->serialize() << std::endl;
    }

    outFile.close();
}

void Board::load(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filePath << std::endl;
        return;
    }

    inFile >> width >> height;
    shapes.clear();
    clearGrid();

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        Shape* shape = nullptr;
        if (shapeType == "Rectangle") {
            shape = new Rectangle(0, 0, 0, 0);
        } else if (shapeType == "Line") {
            shape = new Line(0, 0, 0, 0);
        } else if (shapeType == "Circle") {
            shape = new Circle(0, 0, 0);
        } else if (shapeType == "Triangle") {
            shape = new Triangle(0, 0, 0);
        }

        if (shape) {
            shape->deserialize(line);
            shapes.push_back(shape);
        }
    }

    inFile.close();
}

const std::vector<const Shape*>& Board::getShapes() const {
    return shapes;
}
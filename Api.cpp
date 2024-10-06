#include "Api.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"

Api::Api(int width, int height)
    : board(width, height) {}

void Api::runCommand(const std::string& command, const std::vector<std::string>& args) {
    if (command == "draw") {
        draw();
    } else if (command == "list") {
        list();
    } else if (command == "shapes") {
        shapes();
    } else if (command == "add") {
        add(args);
    } else if (command == "undo") {
        undo();
    } else if (command == "redo") {
        redo();
    } else if (command == "clear") {
        clear();
    } else if (command == "save") {
        if (args.size() != 1) {
            std::cerr << "Invalid arguments for save command" << std::endl;
            return;
        }
        save(args[0]);
    } else if (command == "load") {
        if (args.size() != 1) {
            std::cerr << "Invalid arguments for load command" << std::endl;
            return;
        }
        load(args[0]);
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
    }
}

void Api::draw() const {
    board.draw();
}

void Api::list() const {
    const auto& shapes = board.getShapes();
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i + 1 << ": " << shapes[i]->serialize() << std::endl;
    }
}

void Api::shapes() const {
    std::cout << "Available shapes:" << std::endl;
    std::cout << "1. Rectangle x y width height" << std::endl;
    std::cout << "2. Line x1 y1 x2 y2" << std::endl;
    std::cout << "3. Circle centerX centerY radius" << std::endl;
    std::cout << "4. Triangle x y height" << std::endl;
}

void Api::add(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "Invalid arguments for add command" << std::endl;
        return;
    }

    const std::string& shapeType = args[0];
    if (shapeType == "Rectangle" && args.size() == 5) {
        int x = std::stoi(args[1]);
        int y = std::stoi(args[2]);
        int width = std::stoi(args[3]);
        int height = std::stoi(args[4]);
        board.addShape(new Rectangle(x, y, width, height));
    } else if (shapeType == "Line" && args.size() == 5) {
        int x1 = std::stoi(args[1]);
        int y1 = std::stoi(args[2]);
        int x2 = std::stoi(args[3]);
        int y2 = std::stoi(args[4]);
        board.addShape(new Line(x1, y1, x2, y2));
    } else if (shapeType == "Circle" && args.size() == 4) {
        int centerX = std::stoi(args[1]);
        int centerY = std::stoi(args[2]);
        int radius = std::stoi(args[3]);
        board.addShape(new Circle(centerX, centerY, radius));
    } else if (shapeType == "Triangle" && args.size() == 4) {
        int x = std::stoi(args[1]);
        int y = std::stoi(args[2]);
        int height = std::stoi(args[3]);
        board.addShape(new Triangle(x, y, height));
    } else {
        std::cerr << "Invalid shape type or parameters" << std::endl;
    }
}

void Api::undo() {
    if (!board.getShapes().empty()) {
        redoStack.push_back(board.getShapes().back());
        board.removeLastShape();
    } else {
        std::cerr << "No shapes to undo" << std::endl;
    }
}

void Api::redo() {
    if (!redoStack.empty()) {
        board.addShape(redoStack.back());
        redoStack.pop_back();
    } else {
        std::cerr << "No shapes to redo" << std::endl;
    }
}

void Api::clear() {
   board.clear();
}

void Api::save(const std::string& filePath) const {
    board.save(filePath);
}

void Api::load(const std::string& filePath) {
    board.load(filePath);
}
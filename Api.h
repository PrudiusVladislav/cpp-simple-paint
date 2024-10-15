#ifndef API_H
#define API_H

#include <string>
#include "Board.h"

class Api {
public:
    Api(int width, int height);
    void runCommand(const std::string& command, const std::vector<std::string>& args);

private:
    Board board;
    std::vector<const Shape*> redoStack;
    void draw() const;
    void list() const;
    void shapes() const;
    void add(const std::vector<std::string>& args);
    void undo();
    void redo();
    void clear();
    void save(const std::string& filePath) const;
    void load(const std::string& filePath);
    void select(const std::vector<std::string>& args);
    void showSelected() const;
    void edit(const std::vector<std::string>& args);
    void paint(const std::vector<std::string>& args);
    void move(const std::vector<std::string>& args);
    void remove();
};

#endif // API_H
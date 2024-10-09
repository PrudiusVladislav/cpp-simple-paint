#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <string>
#include <vector>
#include "Shape.h"

template <class TClass>
class ShapeFactory {
public:
    static Shape* Create(const std::vector<std::string>& args) {
        return TClass::CreateInternal(args);
    }
    static Shape* CreateEmpty() {
        return TClass::CreateEmptyInternal();
    }
};

#endif // SHAPE_FACTORY_H

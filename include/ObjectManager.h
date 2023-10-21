// ObjectManager.h
#pragma once

#include <vector>
#include "Object.h"
#include <cstddef>
#include <stdexcept>

class ObjectManager {
public:
    ObjectManager();
    ~ObjectManager();

    void addObject(Object& obj);
    void removeObject(const Object& obj);
    Object& getObjectAt(size_t index);
    size_t getObjectCount() const;
    void updateObjectAt(size_t index, const Object& newObject);  // New method

private:
    std::vector<Object> objects;
};

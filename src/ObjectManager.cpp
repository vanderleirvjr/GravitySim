#include "ObjectManager.h"

ObjectManager::ObjectManager() {
    // constructor body, if needed
}

ObjectManager::~ObjectManager() {
    // destructor body, if needed
}

void ObjectManager::addObject(Object& obj) {
    
    if (obj.getName().empty()) {  
        obj.setName("Object_" + std::to_string(objects.size() + 1));
    }

    objects.push_back(obj);
}

void ObjectManager::removeObject(const Object& obj) {
    // Assuming Object has an operator== to compare objects
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (*it == obj) {
            objects.erase(it);
            return;
        }
    }
}

Object& ObjectManager::getObjectAt(size_t index) {
    if (index < objects.size()) {
        return objects[index];
    }
    throw std::out_of_range("Index out of range");
}

size_t ObjectManager::getObjectCount() const {
    return objects.size();
}

void ObjectManager::updateObjectAt(size_t index, const Object& newObject) {
    if (index >= objects.size()) {
        throw std::out_of_range("Index out of range");
    }
    objects[index] = newObject;
}

#include "Object.h"
#include "Player.h"
// Object::Object(const Object& other) : name(other.name), tag(other.tag) {}
Object::Object(){
    name = "NotDefined";
    tag = "NotDefined";
}

Object::Object(std::string Name, std::string Tag){
    name = Name;
    tag = Tag;
}

void Object::setName(std::string Name){
    name = Name;
}

std::string Object::getName(){
    return name;
}

void Object::setTag(std::string Tag){
    tag = Tag;
}

std::string Object::getTag(){
    return tag;
}
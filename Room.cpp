#include "Room.h"

Room::Room(){
    type = "empty";
    upRoom = NULL;
    downRoom = NULL;
    leftRoom = NULL;
    rightRoom = NULL;
    isExit = true;
    index = -1;
    objects = {0};
}
Room::Room(string Type, int Index, vector<Object*> Objects){
    type = Type;
    index = Index;
    objects = Objects;
}

void Room::ItemFall(Item* obj) {
    // Implement this function according to your requirements
    objects.push_back(obj);
}

void Room::setUpRoom(Room* room) {
    upRoom = room;
}

void Room::setDownRoom(Room* room) {
    downRoom = room;
}

void Room::setLeftRoom(Room* room) {
    leftRoom = room;
}

void Room::setRightRoom(Room* room) {
    rightRoom = room;
}

void Room::setIsExit(bool exit) {
    isExit = exit;
}

void Room::setIndex(int roomIndex) {
    index = roomIndex;
}

bool Room::getIsExit() {
    return isExit;
}

int Room::getIndex() {
    return index;
}

vector<Object*> Room::getObjects() {
    return objects;
}

Room* Room::getUpRoom() {
    return upRoom;
}

Room* Room::getDownRoom() {
    return downRoom;
}

Room* Room::getLeftRoom() {
    return leftRoom;
}

Room* Room::getRightRoom() {
    return rightRoom;
}
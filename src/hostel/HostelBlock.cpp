/**
 * @file HostelBlock.cpp
 * @brief Implementation of HostelBlock class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Composition (Room objects inside HostelBlock),
 *               Arrays of Objects
 */

#include "HostelBlock.h"
#include <iostream>
using namespace std;

HostelBlock::HostelBlock(const string& blockName)
    : blockName(blockName), roomCount(0) {
    for (int i = 0; i < MAX_ROOMS_PER_BLOCK; i++) rooms[i] = nullptr;
}

HostelBlock::~HostelBlock() {
    for (int i = 0; i < roomCount; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}

void HostelBlock::addRoom(Room* room) {
    if (roomCount < MAX_ROOMS_PER_BLOCK) {
        rooms[roomCount++] = room;
    } else {
        cout << "Block " << blockName << " is full. Cannot add room." << endl;
    }
}

Room* HostelBlock::findRoom(const string& roomNumber) const {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getRoomNumber() == roomNumber)
            return rooms[i];
    }
    return nullptr;
}

Room* HostelBlock::findAvailableRoom(RoomType type) const {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getType() == type && !rooms[i]->isFull())
            return rooms[i];
    }
    return nullptr;
}

Room* HostelBlock::getRoom(int i) const {
    if (i >= 0 && i < roomCount) return rooms[i];
    return nullptr;
}

void HostelBlock::displayBlock() const {
    cout << "\n=== Block: " << blockName << " ===" << endl;
    cout << "Total Rooms: " << roomCount
         << " | Occupancy: " << getTotalOccupancy()
         << "/" << getTotalCapacity() << endl;
    for (int i = 0; i < roomCount; i++)
        rooms[i]->displayRoom();
}

int HostelBlock::getTotalOccupancy() const {
    int total = 0;
    for (int i = 0; i < roomCount; i++)
        total += rooms[i]->getOccupantCount();
    return total;
}

int HostelBlock::getTotalCapacity() const {
    int total = 0;
    for (int i = 0; i < roomCount; i++)
        total += rooms[i]->getMaxOccupants();
    return total;
}

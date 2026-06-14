/**
 * @file HostelBlock.h
 * @brief HostelBlock class composed of Room objects
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Composition (Room objects inside HostelBlock),
 *               Arrays of Objects
 */

#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H

#include "Room.h"
#include <string>
using namespace std;

const int MAX_ROOMS_PER_BLOCK = 20;

class HostelBlock {
private:
    string blockName;
    Room*  rooms[MAX_ROOMS_PER_BLOCK];  // array of Room pointers
    int    roomCount;

public:
    explicit HostelBlock(const string& blockName);
    ~HostelBlock();

    void addRoom(Room* room);
    Room* findRoom(const string& roomNumber) const;
    Room* findAvailableRoom(RoomType type) const;

    // Getters
    string getBlockName() const { return blockName; }
    int    getRoomCount() const { return roomCount;  }
    Room*  getRoom(int i) const;

    void displayBlock() const;
    int  getTotalOccupancy()  const;
    int  getTotalCapacity()   const;
};

#endif // HOSTELBLOCK_H

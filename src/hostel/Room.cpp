/**
 * @file Room.cpp
 * @brief Implementation of Room class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Arrays of Pointers, Exception Handling
 */

#include "Room.h"
#include <iostream>
using namespace std;

Room::Room(const string& roomNumber, RoomType type, int floor)
    : roomNumber(roomNumber), type(type), floor(floor), occupantCount(0) {
    maxOccupants = static_cast<int>(type);  // SINGLE=1, DOUBLE=2, TRIPLE=3
    for (int i = 0; i < 3; i++) occupants[i] = nullptr;
}

void Room::addOccupant(Student* s) {
    if (isFull()) {
        throw RoomFullException(roomNumber);
    }
    occupants[occupantCount++] = s;
    cout << s->getName() << " assigned to room " << roomNumber << endl;
}

void Room::removeOccupant(const string& rollNo) {
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i] && occupants[i]->getRollNo() == rollNo) {
            cout << occupants[i]->getName() << " vacated room " << roomNumber << endl;
            for (int j = i; j < occupantCount - 1; j++)
                occupants[j] = occupants[j + 1];
            occupants[--occupantCount] = nullptr;
            return;
        }
    }
    cout << "Student " << rollNo << " not found in room " << roomNumber << endl;
}

Student* Room::getOccupant(int i) const {
    if (i >= 0 && i < occupantCount) return occupants[i];
    return nullptr;
}

void Room::displayRoom() const {
    string typeStr = (type == SINGLE) ? "Single" : (type == DOUBLE) ? "Double" : "Triple";
    cout << "Room " << roomNumber << " [" << typeStr << "] Floor " << floor
         << " | Occupancy: " << occupantCount << "/" << maxOccupants << endl;
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i])
            cout << "  - " << occupants[i]->getRollNo() << " " << occupants[i]->getName() << endl;
    }
}

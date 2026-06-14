/**
 * @file Room.h
 * @brief Room class managing occupants
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Arrays of Pointers, Exception Handling
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "../person/Student.h"
#include "../utils/Exceptions.h"
using namespace std;

enum RoomType { SINGLE = 1, DOUBLE = 2, TRIPLE = 3 };

class Room {
private:
    string   roomNumber;
    RoomType type;
    int      floor;
    Student* occupants[3];   // max 3 for triple room
    int      occupantCount;
    int      maxOccupants;

public:
    Room(const string& roomNumber, RoomType type, int floor);

    void addOccupant(Student* s);
    void removeOccupant(const string& rollNo);

    bool isFull()     const { return occupantCount >= maxOccupants; }
    bool isEmpty()    const { return occupantCount == 0;            }

    // Getters
    string   getRoomNumber()    const { return roomNumber;    }
    RoomType getType()          const { return type;          }
    int      getFloor()         const { return floor;         }
    int      getOccupantCount() const { return occupantCount; }
    int      getMaxOccupants()  const { return maxOccupants;  }
    Student* getOccupant(int i) const;

    void displayRoom() const;
};

#endif // ROOM_H

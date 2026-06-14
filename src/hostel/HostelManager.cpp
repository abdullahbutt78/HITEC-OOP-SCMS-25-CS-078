/**
 * @file HostelManager.cpp
 * @brief Implementation of HostelManager (multiple + virtual inheritance)
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 * OOP Concepts: Multiple Inheritance, Virtual Inheritance (diamond problem),
 *               Composition (HostelBlock inside HostelManager),
 *               Abstract classes as interfaces
 */

#include "HostelManager.h"
#include <iostream>
using namespace std;

HostelManager::HostelManager(const string& managerName)
    : managerName(managerName), blockCount(0) {
    for (int i = 0; i < MAX_BLOCKS; i++) blocks[i] = nullptr;
}

HostelManager::~HostelManager() {
    for (int i = 0; i < blockCount; i++) {
        delete blocks[i];
        blocks[i] = nullptr;
    }
}

void HostelManager::addBlock(HostelBlock* block) {
    if (blockCount < MAX_BLOCKS) {
        blocks[blockCount++] = block;
    } else {
        cout << "Cannot add more blocks. Maximum reached." << endl;
    }
}

void HostelManager::allocateRoom(Student* student, RoomType type) {
    for (int i = 0; i < blockCount; i++) {
        Room* room = blocks[i]->findAvailableRoom(type);
        if (room) {
            try {
                room->addOccupant(student);
            } catch (const RoomFullException& e) {
                cout << "[ERROR] " << e.what() << endl;
            }
            return;
        }
    }
    cout << "No available room of requested type found for " << student->getName() << endl;
}

void HostelManager::vacateRoom(const string& rollNo, const string& blockName) {
    HostelBlock* block = findBlock(blockName);
    if (!block) {
        cout << "Block \"" << blockName << "\" not found." << endl;
        return;
    }
    for (int i = 0; i < block->getRoomCount(); i++) {
        Room* room = block->getRoom(i);
        for (int j = 0; j < room->getOccupantCount(); j++) {
            if (room->getOccupant(j) && room->getOccupant(j)->getRollNo() == rollNo) {
                room->removeOccupant(rollNo);
                return;
            }
        }
    }
    cout << "Student " << rollNo << " not found in block " << blockName << endl;
}

void HostelManager::generateOccupancyReport() const {
    cout << "\n====== HOSTEL OCCUPANCY REPORT ======" << endl;
    cout << "Manager: " << managerName << endl;
    int totalOccupied = 0, totalCapacity = 0;
    for (int i = 0; i < blockCount; i++) {
        blocks[i]->displayBlock();
        totalOccupied  += blocks[i]->getTotalOccupancy();
        totalCapacity  += blocks[i]->getTotalCapacity();
    }
    cout << "\nOverall Occupancy: " << totalOccupied << " / " << totalCapacity << endl;
    cout << "=====================================" << endl;
}

HostelBlock* HostelManager::getBlock(int i) const {
    if (i >= 0 && i < blockCount) return blocks[i];
    return nullptr;
}

HostelBlock* HostelManager::findBlock(const string& name) const {
    for (int i = 0; i < blockCount; i++) {
        if (blocks[i]->getBlockName() == name)
            return blocks[i];
    }
    return nullptr;
}

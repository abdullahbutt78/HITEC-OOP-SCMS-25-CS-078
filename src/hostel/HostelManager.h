/**
 * @file HostelManager.h
 * @brief HostelManager with multiple inheritance (Accommodation + Reportable)
 *        and virtual inheritance to resolve the diamond problem
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Multiple Inheritance, Virtual Inheritance (diamond problem),
 *               Composition (HostelBlock inside HostelManager),
 *               Abstract classes as interfaces
 *
 * Diamond diagram:
 *           Manageable  (virtual base)
 *          /           \
 *   Accommodation    Reportable
 *          \           /
 *         HostelManager
 */

#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H

#include "HostelBlock.h"
#include <string>
#include <iostream>
using namespace std;

// ─── Virtual base to illustrate diamond problem ─────────────────────────────
class Manageable {
public:
    virtual ~Manageable() = default;
    virtual string getManagerName() const = 0;
};

// ─── Interface 1: Accommodation ─────────────────────────────────────────────
class Accommodation : public virtual Manageable {
public:
    virtual ~Accommodation() = default;
    virtual void allocateRoom(Student* student, RoomType type) = 0;
    virtual void vacateRoom(const string& rollNo, const string& blockName) = 0;
};

// ─── Interface 2: Reportable ────────────────────────────────────────────────
class Reportable : public virtual Manageable {
public:
    virtual ~Reportable() = default;
    virtual void generateOccupancyReport() const = 0;
};

// ─── HostelManager: multiple inheritance ────────────────────────────────────
const int MAX_BLOCKS = 5;

class HostelManager : public Accommodation, public Reportable {
private:
    string       managerName;
    HostelBlock* blocks[MAX_BLOCKS];   // composition: HostelBlock array
    int          blockCount;

public:
    explicit HostelManager(const string& managerName);
    ~HostelManager();

    void addBlock(HostelBlock* block);

    // Implements Manageable
    string getManagerName() const override { return managerName; }

    // Implements Accommodation
    void allocateRoom(Student* student, RoomType type) override;
    void vacateRoom(const string& rollNo, const string& blockName) override;

    // Implements Reportable
    void generateOccupancyReport() const override;

    // Getters
    int          getBlockCount()  const { return blockCount; }
    HostelBlock* getBlock(int i)  const;
    HostelBlock* findBlock(const string& name) const;
};

#endif // HOSTELMANAGER_H

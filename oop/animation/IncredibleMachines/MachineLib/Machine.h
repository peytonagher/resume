/**
 * @file Machine.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

#include "Body.h"
#include "ContactListener.h"

class Component;

class Machine
{
private:
    int mMachineNumber;
    std::vector<std::shared_ptr<Component>> mComponents;

    /// The box2d world
    std::shared_ptr<b2World> mWorld;

    std::shared_ptr<ContactListener> mContactListener;

public:
    Machine(int machineNumber);
    void Update(double elapsed);
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);
    void AddComponent(std::shared_ptr<Component> component);
    std::vector<std::shared_ptr<Component>> GetComponents() { return mComponents; }
    void Reset();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

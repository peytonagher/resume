/**
 * @file Component.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

#include "PhysicsPolygon.h"

class Machine;

class Component
{
private:
    std::shared_ptr<Machine> mMachine;

public:
    virtual cse335::PhysicsPolygon* GetPolygon() { return nullptr; }
    virtual void Update(double elapsed) {};
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) {};
    virtual void InstallPhysics(std::shared_ptr<b2World> world) = 0;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

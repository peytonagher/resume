/**
 * @file Machine.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "Machine.h"
#include "DebugDraw.h"
#include <box2d/box2d.h>

/// Gravity in meters per second per second
const float Gravity = -9.8f;

/// Number of velocity update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

Machine::Machine(int number)
{
    mMachineNumber = number;
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));
}

void Machine::Reset()
{
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));
    mContactListener = std::make_shared<ContactListener>();
    mWorld->SetContactListener(mContactListener.get());

    for (auto component : mComponents)
    {
        component->InstallPhysics(mWorld);
    }
}

/**
 * Update the machine in time
 * @param elapsed Elapsed time in seconds
 */
void Machine::Update(double elapsed)
{
    for (auto & component : mComponents)
    {
        component->Update(elapsed);
    }
    mWorld->Step(elapsed, VelocityIterations, PositionIterations);
}

void Machine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();

    for (auto & component : mComponents)
    {
        component->Draw(graphics);
    }

    graphics->PopState();
}

void Machine::AddComponent(std::shared_ptr<Component> component)
{
    auto polygon = component->GetPolygon();
    if (polygon != nullptr)
    {
        polygon->InstallPhysics(mWorld);
    }
    mComponents.push_back(component);
}

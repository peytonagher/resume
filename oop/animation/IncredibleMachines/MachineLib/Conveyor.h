/**
 * @file Conveyor.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
#define CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H

#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include "PhysicsPolygon.h"

class Conveyor : public Component, public IRotationSink
{
private:
    double mSpeed = 0.0;
    double mRotation = 0.0;
    cse335::PhysicsPolygon mPolygon;

    wxPoint2DDouble mPosition;
    wxPoint2DDouble mShaftPosition;

    RotationSource mRotationSource;

public:
    Conveyor(const std::wstring &imagesDir);

    double GetSpeed() { return mSpeed; }
    wxPoint2DDouble GetPosition() { return mPosition; }
    wxPoint2DDouble GetShaftPosition() { return mShaftPosition; };
    cse335::PhysicsPolygon* GetPolygon() override { return &mPolygon; }

    void SetSpeed(double speed) override { mSpeed = speed; }
    void SetRotation(double rotation) override { mRotation = rotation; }
    void SetPosition(double x, double y);
    void InstallPhysics(std::shared_ptr<b2World> world) override;

    void ApplyLinearMotionToContacts();
    void PreSolve(b2Contact contact, b2Manifold oldManifold);
    void Rotate(double rotation, double speed) override {};
    void Reset(double elapsed);
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H

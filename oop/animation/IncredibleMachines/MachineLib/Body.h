/**
 * @file Body.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_BODY_H
#define CANADIANEXPERIENCE_MACHINELIB_BODY_H

#include "Component.h"
#include "RotationSink.h"
#include "PhysicsPolygon.h"

class Body : public Component, public IRotationSink
{
private:
    std::wstring mImage;
    bool mIsDynamic = false;
    cse335::PhysicsPolygon mPhysicsPolygon;
    double mSpeed = 0.0;
    double mRotation = 0.0;

public:
    Body();
    void Rectangle(double x, double y, double width, double height);
    void BottomCenteredRectangle(double width, double height);
    void Circle(double radius);
    void AddPoint(double x, double y);
    void Rotate(double rotation, double speed) override;

    cse335::PhysicsPolygon* GetPolygon() override { return &mPhysicsPolygon; }

    void SetImage(std::wstring image);
    void SetPhysics(double density, double friction, double restitution);
    void InstallPhysics(std::shared_ptr<b2World> world) override;
    void SetSpeed(double speed) override { mSpeed = speed; }
    void SetRotation(double rotation) override { mRotation = rotation; }
    void SetInitialPosition(double x, double y);
    void SetInitialRotation(double rotation);
    void SetDynamic();
    void SetKinematic();

    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_BODY_H

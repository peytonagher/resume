/**
 * @file Hamster.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
#define CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H

#include "Component.h"
#include "RotationSource.h"
#include "Polygon.h"
#include "PhysicsPolygon.h"

class Hamster : public Component
{
private:
    std::wstring mImagesDir;

    bool mIsInitiallyRunning = true;
    bool mIsRunning = true;
    double mSpeed = 0.0;
    double mRotation = 0.0;
    int mHamsterIndex = 0;

    cse335::Polygon mHamsterImages[4];
    cse335::PhysicsPolygon mCage;
    cse335::Polygon mWheel;

    wxPoint2DDouble mHamsterPosition;
    wxPoint2DDouble mWheelPosition;
    wxPoint2DDouble mCagePosition;
    wxPoint2DDouble mShaftPosition;

    RotationSource mRotationSource;

public:
    Hamster(const std::wstring& imagesDir);
    void BeginContact(b2Contact* contact);

    RotationSource *GetSource() { return &mRotationSource; }
    cse335::PhysicsPolygon* GetPolygon() override { return &mCage; }
    wxPoint2DDouble GetShaftPosition();

    void SetImage(std::wstring image);
    void SetPosition(double x, double y);
    void SetInitiallyRunning(bool isRunning)
    {
        mIsInitiallyRunning = isRunning;
        mIsRunning = isRunning;
    };
    void SetSpeed(double speed) { mSpeed = speed; };
    void InstallPhysics(std::shared_ptr<b2World> world) override;

    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H

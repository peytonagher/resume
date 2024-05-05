/**
 * @file Pulley.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include "Polygon.h"
#include "PhysicsPolygon.h"

class Pulley : public Component, public IRotationSink
{
private:
    std::wstring mImagesDir;
    std::wstring mImage;

    double mRadius = 0.0;
    double mRotation = 0.0;
    wxPoint2DDouble mPosition;

    cse335::Polygon mPolygon;

    std::shared_ptr<Pulley> mPulley;
    RotationSource mRotationSource;

public:
    Pulley(double radius, const std::wstring& imagesDir);
    void Rotate(double speed);
    void Drive(std::shared_ptr<Pulley> pulley);

    RotationSource *GetSource() { return &mRotationSource; }
    void SetPosition(wxPoint2DDouble position);
    void SetImage(std::wstring image);

    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void InstallPhysics(std::shared_ptr<b2World> world) {}
    void SetSpeed(double speed) {}
    void SetRotation(double rotation) {}
    void Rotate(double rotation, double speed) {}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

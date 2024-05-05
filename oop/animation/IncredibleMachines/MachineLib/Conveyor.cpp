/**
 * @file Conveyor.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "Conveyor.h"

/// The offset from the bottom center of the conveyor
/// to the center of the drive shaft.  48
const auto ConveyorShaftOffset = wxPoint2DDouble(48, 4);

/// The size of the conveyor in cm
const auto ConveyorSize = wxSize(125, 14);

/// The conveyor image to use
const std::wstring ConveyorImageName = L"/conveyor.png";


Conveyor::Conveyor(const std::wstring &imagesDir)  : mRotationSource(this, imagesDir)
{
    mPolygon.SetImage(imagesDir+ L"/conveyor.png");
    mPolygon.BottomCenteredRectangle(ConveyorSize);
}
void Conveyor::Update(double elapsed)
{

}
void Conveyor::Reset(double elapsed)
{

}
void Conveyor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PopState();
    mPolygon.Draw(graphics);
    graphics->PushState();
}
void Conveyor::InstallPhysics(std::shared_ptr<b2World> world)
{
    mPolygon.InstallPhysics(world);
}
void Conveyor::SetPosition(double x, double y)
{
    mPosition = wxPoint2DDouble(x, y);
    mShaftPosition = wxPoint2DDouble(mPosition.m_x + ConveyorShaftOffset.m_x, mPosition.m_y + ConveyorShaftOffset.m_y);
    mPolygon.SetInitialPosition(mPosition.m_x, mPosition.m_y);
}

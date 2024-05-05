/**
 * @file Body.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "Body.h"
#include <cmath>

Body::Body()
{

}
void Body::Rectangle(double x, double y, double width, double height)
{
    mPhysicsPolygon.Rectangle(x, y, width, height);
}
void Body::BottomCenteredRectangle(double width, double height)
{
    mPhysicsPolygon.BottomCenteredRectangle(width, height);
}
void Body::Circle(double radius)
{
    mPhysicsPolygon.Circle(radius);
}
void Body::AddPoint(double x, double y)
{
    mPhysicsPolygon.AddPoint(x, y);
}
void Body::Rotate(double rotation, double speed)
{
    mPhysicsPolygon.SetAngularVelocity(speed);
}
void Body::SetImage(std::wstring image)
{
    mPhysicsPolygon.SetImage(image);
}
void Body::SetPhysics(double density, double friction, double restitution)
{
    mPhysicsPolygon.SetPhysics(density, friction, restitution);
}
void Body::InstallPhysics(std::shared_ptr<b2World> world)
{
    mPhysicsPolygon.InstallPhysics(world);
}
void Body::SetInitialPosition(double x, double y)
{
    mPhysicsPolygon.SetInitialPosition(x, y);
}
void Body::SetInitialRotation(double rotation)
{
    mPhysicsPolygon.SetInitialRotation(rotation);
}
void Body::SetDynamic()
{
    mPhysicsPolygon.SetDynamic();
}
void Body::SetKinematic()
{
    mPhysicsPolygon.SetKinematic();
}
void Body::Update(double elapsed)
{

}
void Body::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPhysicsPolygon.Draw(graphics);
}

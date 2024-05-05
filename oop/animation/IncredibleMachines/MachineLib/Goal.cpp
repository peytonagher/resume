/**
 * @file Goal.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "Goal.h"
#include "b2_contact.h"

/// Image to draw for the goal
const std::wstring GoalImage = L"/goal.png";

/// Size to draw the entire goal post image
/// This does not go into the physics system at all
const auto GoalSize = wxSize(65, 247);

/// Size to create a rectangle in the physics system only
/// (does not draw) to reflect off of the backboard and post
const auto PostSize = wxSize(10, 250);

/// Size of a target object inside the goal net that
/// we'll consider a score when touched by a ball
const auto TargetSize = wxSize(20, 5);

/// Rectangle that represents the location relative to the
/// goal position for the scoreboard and its size.
const auto ScoreboardRectangle = wxRect2DDouble(5, 280, 30, 20);

/// Position of the goalpost polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble PostPosition = wxPoint2DDouble(22, 0);

/// Position of the basket goal polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble GoalPosition = wxPoint2DDouble(-12, 165);

Goal::Goal(const std::wstring& imagesDir) : mImagesDir(imagesDir)
{
    mPolygon.BottomCenteredRectangle(GoalSize);
    mPolygon.SetImage(imagesDir + GoalImage);
    mPost.BottomCenteredRectangle(PostSize);
    mGoal.BottomCenteredRectangle(TargetSize);
}
void Goal::SetImage(std::wstring image)
{
    mPolygon.SetImage(image);
}
void Goal::BeginContact(b2Contact contact)
{

}
void Goal::PreSolve(b2Contact contact, b2Manifold oldManifold)
{

}
void Goal::SetPosition(double x, double y)
{
    mPosition = wxPoint(x, y);
    mPost.SetInitialPosition(x + PostPosition.m_x, y + PostPosition.m_y);
    mGoal.SetInitialPosition(x + GoalPosition.m_x, y + GoalPosition.m_y);

    mScoreBoard.SetPosition(x, y - ScoreboardRectangle.m_height);
}
void Goal::InstallPhysics(std::shared_ptr<b2World> world)
{
//    mGoal.InstallPhysics(world);
    mPost.InstallPhysics(world);
}
void Goal::Update(double elapsed)
{
    mScoreBoard.Update(elapsed);
}
void Goal::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, mPosition.x, mPosition.y, 0);
//    mPost.Draw(graphics);
//    mGoal.Draw(graphics);
    mScoreBoard.Draw(graphics);
}

/**
 * @file Goal.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_GOAL_H
#define CANADIANEXPERIENCE_MACHINELIB_GOAL_H

#include "Component.h"
#include "ScoreBoard.h"
#include "Polygon.h"
#include "PhysicsPolygon.h"

class Goal : public Component
{
private:
    /// The polygon object for the goal image
    cse335::Polygon mPolygon;

    /// Physics polygon for the backboard/post
    cse335::PhysicsPolygon mPost;

    /// Polygon that we are going to hit to
    /// determine the basket has been scored
    cse335::PhysicsPolygon mGoal;

    std::wstring mImagesDir;
    ScoreBoard mScoreBoard;
    wxPoint mPosition;

public:
    Goal(const std::wstring& imagesDir);
    void SetImage(std::wstring image);
    void BeginContact(b2Contact contact);
    void PreSolve(b2Contact contact, b2Manifold oldManifold);

    cse335::PhysicsPolygon* GetPolygon() override { return &mPost; }

    void SetPosition(double x, double y);
    void InstallPhysics(std::shared_ptr<b2World> world) override;

    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_GOAL_H

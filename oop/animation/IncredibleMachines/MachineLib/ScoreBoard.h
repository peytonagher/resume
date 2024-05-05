/**
 * @file ScoreBoard.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SCOREBOARD_H
#define CANADIANEXPERIENCE_MACHINELIB_SCOREBOARD_H

#include "Polygon.h"

class ScoreBoard
{
private:
    int mScore = 0;
    wxPoint mPosition;
    cse335::Polygon mPolygon;

public:
    ScoreBoard();
    void SetPosition(double x, double y);
    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_SCOREBOARD_H

/**
 * @file ScoreBoard.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "ScoreBoard.h"
#include <sstream>
#include <iomanip>

/// The color of the scoreboard background
const auto ScoreboardBackgroundColor = wxColor(24, 69, 59);

/// Width of the black line around the scoreboard
const int ScoreboarderLineWidth = 3;

/// Scoreboard font size (height) in cm
/// The font color is white
const int ScoreboardFontSize = 20;

/// Rectangle that represents the location relative to the
/// goal position for the scoreboard and its size.
const auto ScoreboardRectangle = wxRect2DDouble(5, 280, 30, 20);

/// Location of the scoreboard text relative to the
/// scoreboard location in cm.
const auto ScoreboardTextLocation = wxPoint2DDouble(9, 299);

ScoreBoard::ScoreBoard()
{
    // Create the rectangle for the scoreboard
    mPolygon.Rectangle(ScoreboardRectangle.m_x, ScoreboardRectangle.m_y, ScoreboardRectangle.m_width, ScoreboardRectangle.m_height);
}

void ScoreBoard::SetPosition(double x, double y)
{
    mPosition = wxPoint(x, y);
}

void ScoreBoard::Update(double elapsed)
{

}

void ScoreBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.SetColor(ScoreboardBackgroundColor);
    mPolygon.DrawPolygon(graphics, mPosition.x, mPosition.y, 0);

    wxPen pen(*wxBLACK, ScoreboarderLineWidth);
    graphics->SetPen(pen);
    graphics->DrawRectangle(mPosition.x + ScoreboardRectangle.m_x, mPosition.y + ScoreboardRectangle.m_y, ScoreboardRectangle.m_width, ScoreboardRectangle.m_height);

    wxFont font(ScoreboardFontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, *wxWHITE);

    // Use std::setw and std::setfill to format the score
    std::ostringstream scoreStream;
    scoreStream << std::setw(2) << std::setfill('0') << mScore;
    std::string scoreStr = scoreStream.str();


    graphics->PushState();
    graphics->Translate(mPosition.x + ScoreboardTextLocation.m_x, mPosition.y + ScoreboardTextLocation.m_y);
    graphics->Scale(1, -1);
    graphics->DrawText(scoreStr, 0, 0);
    graphics->PopState();
}


/**
 * @file Hamster.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "b2_contact.h"
#include "RotationSink.h"
#include "Hamster.h"

/// The center point for drawing the wheel
/// relative to the bottom center of the cage
const auto WheelCenter = wxPoint2DDouble(-12, 24);

/// The size of the hamster cage in centimeters
const auto HamsterCageSize = wxSize(75, 50);

/// Size of the hamster wheel (diameter) in centimeters
const double HamsterWheelSize = 45;

/// Size of the hamster wheel (square) in centimeters
const double HamsterSize = 45;

/// How fast the hamster runs. This is how many cycles of
/// the 3 images we make per revolution of the wheel
/// as images 1, 2, 3, 2, ... The value of 4.0 means
/// 4 complete cycles per resolution, one image every 1/16
/// of a revolution
const double HamsterSpeed = 4.0;

/// The offset from the bottom center of the hamster cage
/// to the center of the output shaft.
const auto HamsterShaftOffset = wxPoint2DDouble(25, 40);

/// The image for the hamster cage
const std::wstring HamsterCageImage = L"/hamster-cage.png";

/// The image for the hamster wheel
const std::wstring HamsterWheelImage = L"/hamster-wheel.png";

/// The hamster images. Image 0 is sleeping, 1-3 are
/// the running hamster animation images.
const std::wstring HamsterImages[4] =
    {L"/hamster-sleep.png", L"/hamster-run-1.png",
        L"/hamster-run-2.png", L"/hamster-run-3.png"};

Hamster::Hamster(const std::wstring& imagesDir) : mRotationSource(this, imagesDir)
{
    mHamsterIndex = 0;

    mCage.SetImage(imagesDir + HamsterCageImage);
    mWheel.SetImage(imagesDir + HamsterWheelImage);
    mHamsterImages[0].SetImage(imagesDir + HamsterImages[1]);
    mHamsterImages[1].SetImage(imagesDir + HamsterImages[2]);
    mHamsterImages[2].SetImage(imagesDir + HamsterImages[3]);
    mHamsterImages[3].SetImage(imagesDir + HamsterImages[0]);

    mCage.BottomCenteredRectangle(HamsterCageSize);
    mWheel.CenteredSquare(HamsterWheelSize);

    for (auto & mHamsterImage : mHamsterImages)
    {
        mHamsterImage.Circle(HamsterSize / 2);
    }

    mCage.SetPhysics(1, 0.5, 0.6);
}

void Hamster::BeginContact(b2Contact* contact)
{
    mIsRunning = true;
}

wxPoint2DDouble Hamster::GetShaftPosition()
{
    return mShaftPosition;
}

void Hamster::SetImage(std::wstring image)
{

}

void Hamster::SetPosition(double x, double y)
{
    mHamsterPosition = wxPoint(x, y);
    mCage.SetInitialPosition(x, y);
    mWheelPosition = wxPoint2DDouble(x + WheelCenter.m_x, y + WheelCenter.m_y);
    mCagePosition = wxPoint2DDouble(x + WheelCenter.m_x, y + WheelCenter.m_y);
    mShaftPosition = wxPoint2DDouble(x + HamsterShaftOffset.m_x, y + HamsterShaftOffset.m_y);
}

void Hamster::InstallPhysics(std::shared_ptr<b2World> world)
{
    mCage.InstallPhysics(world);
}

void Hamster::Update(double elapsed)
{
    if ((mIsInitiallyRunning && mIsRunning) || (!mIsInitiallyRunning && mIsRunning))
    {
        mRotation += mSpeed * elapsed;
        mHamsterIndex = (static_cast<int>(mRotation * 15) % 3 + 3) % 3;
        mRotationSource.SetRotation(mRotation);
    }
    else
    {
        mHamsterIndex = 3;
    }

    for (auto sink : mRotationSource.GetSink())
    {
        sink->Rotate(mRotation, -mSpeed);
    }
}

void Hamster::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mCage.Draw(graphics);
    mWheel.DrawPolygon(graphics, mWheelPosition.m_x, mWheelPosition.m_y, -mRotation);

    graphics->PushState();
    graphics->Translate(mCagePosition.m_x, mCagePosition.m_y);

    if (mSpeed < 0)
    {
        graphics->Scale(-1, 1);
    }

    mHamsterImages[mHamsterIndex].DrawPolygon(graphics, 0, 0, 0);

    graphics->PopState();
}

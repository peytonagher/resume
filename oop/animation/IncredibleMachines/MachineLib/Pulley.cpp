/**
 * @file Pulley.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "b2_contact.h"
#include "Pulley.h"


// tentative
const auto HamsterShaftOffset = wxPoint2DDouble(25, 40);

Pulley::Pulley(double radius, const std::wstring& imagesDir) : mRotationSource(this, imagesDir)
{
    mRadius = radius;
    mImagesDir = imagesDir;

    mPolygon.CenteredSquare(mRadius * 2);
}
void Pulley::Rotate(double speed)
{
    mRotation += speed;
}
void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mPulley = pulley;
    mPulley->Rotate(mRotation);
}
void Pulley::SetPosition(wxPoint2DDouble position)
{
    mPosition = wxPoint2DDouble(position.m_x, position.m_y);
}
void Pulley::SetImage(std::wstring image)
{
    mImage = image;
    mPolygon.SetImage(mImage);
}
void Pulley::Update(double elapsed)
{
    mRotation += elapsed;
    mRotationSource.SetRotation(mRotation);
}
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, mPosition.m_x, mPosition.m_y, -mRotation);
}

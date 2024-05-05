/**
 * @file RotationSink.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "RotationSink.h"

RotationSink::RotationSink() : mSources()
{

}
void RotationSink::Rotate(double rotation, double speed)
{
    mComponent->Rotate(rotation, speed);
}
void RotationSink::SetRotation(double rotation) {
    for (auto & source : mSources) {
        source->SetRotation(rotation);
    }
}

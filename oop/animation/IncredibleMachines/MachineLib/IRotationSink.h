/**
 * @file IRotationSink.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H

#include "Component.h"
#include "RotationSource.h"

class IRotationSink
{
public:
    virtual ~IRotationSink() {}
    virtual void SetSpeed(double speed) = 0;
    virtual void SetRotation(double rotation) = 0;
    virtual void Rotate(double rotation, double speed) = 0;
};


#endif //CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H

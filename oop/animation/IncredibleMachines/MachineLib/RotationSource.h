/**
 * @file RotationSource.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H

#include <vector>
#include <memory>
#include "Component.h"

class IRotationSink;

class RotationSource
{
private:
    std::vector<std::shared_ptr<IRotationSink>> mRotationSinks;
    double mRotation = 0.0;

public:
    RotationSource(Component* component, std::wstring imagesDir) {}
    RotationSource(const RotationSource &) = delete;
    void operator=(const RotationSource &) = delete;

    std::vector<std::shared_ptr<IRotationSink>> GetSink() { return mRotationSinks; }
    void AddSink(const std::shared_ptr<IRotationSink>& sink) { mRotationSinks.push_back(sink); };

    double GetRotation() { return mRotation; }
    void SetRotation(double rotation) { mRotation = rotation; };
};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H

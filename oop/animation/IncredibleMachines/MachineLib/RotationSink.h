/**
 * @file RotationSink.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H

#include "IRotationSink.h"
#include "RotationSource.h"
#include <vector>

class RotationSink : public IRotationSink
{
private:
    std::vector<RotationSource*> mSources;
    IRotationSink* mComponent = nullptr;

public:
    RotationSink();
    RotationSink(const RotationSource &) = delete;
    void operator=(const RotationSink &) = delete;

    void Rotate(double rotation, double speed) override;

//    IRotationSink* GetSink() override { return this; }
    RotationSource* GetSource(int sourceNum) { return mSources[sourceNum]; }
    std::vector<RotationSource*> GetSources() { return mSources; }

//    void AddSource(RotationSource* source) override;
    void SetRotation(double rotation) override;
    void SetComponent(IRotationSink* component) { mComponent = component; }
};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H

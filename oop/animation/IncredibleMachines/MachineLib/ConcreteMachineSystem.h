/**
 * @file ConcreteMachineSystem.h
 * @author Peyton Nagher
 *
 * Concrete class for abstract IMachineSystem interface class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CONCRETEMACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_CONCRETEMACHINESYSTEM_H

#include "IMachineSystem.h"
#include "MachineCFactory.h"
#include "Machine.h"

class ConcreteMachineSystem : public IMachineSystem
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;
    wxPoint mLocation;
    double mFrameRate = 30;
    int mFrame = 0;
    int mNumber = 0;
    int mFlag = 0;

    std::shared_ptr<Machine> mMachine;

    /// How many pixels there are for each CM
    double mPixelsPerCentimeter = 1.5;

public:
    ConcreteMachineSystem(std::wstring resourcesDir);
    wxPoint GetLocation() { return mLocation; };
    void SetLocation(wxPoint location) { mLocation = location; };
    int GetFrameRate() { return mFrameRate; };
    void SetFrameRate(double frameRate) { mFrameRate = frameRate; };
    int GetMachineFrame() { return mFrame; };
    void SetMachineFrame(int frame);
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);
    int GetMachineNumber() { return mNumber; };
    void SetMachineNumber(int number = 0);
    double GetMachineTime() { return mFrame / mFrameRate; };
    void SetFlag(int flag) { mFlag = flag; };
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CONCRETEMACHINESYSTEM_H

/**
 * @file ConcreteMachineSystem.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "ConcreteMachineSystem.h"
#include "MachineCFactory.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"
#include <string>

using namespace std;

/**
* Constructor
*/
ConcreteMachineSystem::ConcreteMachineSystem(wstring resourcesDir)
{
    mResourcesDir = resourcesDir;
    SetMachineNumber();
}

void ConcreteMachineSystem::SetMachineFrame(int frame)
{
    if(frame < mFrame)
    {
        mFrame = 0;
        mMachine->Reset();
    }

    for( ; mFrame < frame;  mFrame++)
    {
        mMachine->Update(1.0 / mFrameRate);
    }

}

void ConcreteMachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);
    graphics->Scale(mPixelsPerCentimeter, -mPixelsPerCentimeter);

    mMachine->DrawMachine(graphics);

    graphics->PopState();
}

void ConcreteMachineSystem::SetMachineNumber(int machineNumber)
{
    mNumber = machineNumber;

    if (mNumber == 1)
    {
        Machine1Factory factory(mResourcesDir);
        mMachine = std::shared_ptr<Machine>(factory.Create());
    }
    else if (mNumber == 2)
    {
        Machine2Factory factory(mResourcesDir);
        mMachine = std::shared_ptr<Machine>(factory.Create());
    }
    else
    {
        MachineCFactory factory(mResourcesDir);
        mMachine = std::shared_ptr<Machine>(factory.Create());
    }
}

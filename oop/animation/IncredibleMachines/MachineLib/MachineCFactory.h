/**
 * @file MachineCFactory.h
 * @author Charles Owen
 *
 * Factory that creates just the parts of the machine
 * necessary for the checkpoint.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H

#include <memory>
#include <string>

class Machine;
class Body;
class Conveyor;

/**
 * Factory that creates just the parts of the machine
 * necessary for the checkpoint.
 */
class MachineCFactory
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    /// The possible domino colors
    enum class DominoColor { Black, Red, Green, Blue };

    /// Height of a Domino
    const double DominoHeight = 25;

    /// Width of a Domino
    const double DominoWidth = 5;

    void TopBeamAndRamp(std::shared_ptr<Machine> machine);
    void BeamAndSpinningArm(std::shared_ptr<Machine> machine);
    void DominoStack(std::shared_ptr<Machine> machine, wxPoint2DDouble position);
    void DominoesOnBeam(std::shared_ptr<Machine> machine, wxPoint2DDouble position);
    std::shared_ptr<Body> Domino(std::shared_ptr<Machine> machine, wxPoint2DDouble position, double rotation, DominoColor color);


public:
    MachineCFactory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H

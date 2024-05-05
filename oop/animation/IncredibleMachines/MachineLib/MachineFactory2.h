/**
 * @file MachineFactory2.h
 * @author Peyton Nagher
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H

#include <memory>
#include <string>

class Machine;
class Body;
class Conveyor;

/**
 * Factory for creating Machine #1
 */
class Machine2Factory {
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
    void BasketballGoal(std::shared_ptr<Machine> machine);
    void DominoesOnBeam(std::shared_ptr<Machine> machine, wxPoint2DDouble position);

    std::shared_ptr<Body> Domino(std::shared_ptr<Machine> machine, wxPoint2DDouble position, double rotation, DominoColor color);

public:
    Machine2Factory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H

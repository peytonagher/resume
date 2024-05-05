/**
 * @file MachineFactory2.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "MachineFactory2.h"
#include "Machine.h"
#include "Body.h"
#include "Goal.h"
#include "Pulley.h"
#include "Hamster.h"
#include "Conveyor.h"
#include "HamsterAndConveyorFactory.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
Machine2Factory::Machine2Factory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}



/**
 * Factory method to create machine #1
 * @return
 */
std::shared_ptr<Machine> Machine2Factory::Create()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor, so it knows
    // its number.
    auto machine = std::make_shared<Machine>(1);

    // Notice: All dimensions are in centimeters and assumes
    // the Y axis is positive in the up direction.

    const double FloorWidth = 600;
    const double FloorHeight = 15;

    //
    // The floor
    //
    // The values are chosen so the top of the floor
    // is at Y=0
    //
    auto floor = std::make_shared<Body>();
    floor->Rectangle(-FloorWidth/2, -FloorHeight, FloorWidth, FloorHeight);
    floor->SetImage(mImagesDir + L"/floor.png");
    machine->AddComponent(floor);

    auto hamster = std::make_shared<Hamster>(mImagesDir);
    hamster->SetPosition(-250, 185);
    hamster->SetInitiallyRunning(true);
    hamster->SetSpeed(1.50);
    machine->AddComponent(hamster);
    auto hamstershaft = hamster->GetShaftPosition();

    auto hamster1 = std::make_shared<Hamster>(mImagesDir);
    hamster1->SetPosition(-170, 185);
    hamster1->SetInitiallyRunning(true);
    hamster1->SetSpeed(1.50);
    machine->AddComponent(hamster1);

    auto hamster2 = std::make_shared<Hamster>(mImagesDir);
    hamster2->SetPosition(-90, 185);
    hamster2->SetInitiallyRunning(true);
    hamster2->SetSpeed(1.50);
    machine->AddComponent(hamster2);

    auto hamster3 = std::make_shared<Hamster>(mImagesDir);
    hamster3->SetPosition(-10, 185);
    hamster3->SetInitiallyRunning(true);
    hamster3->SetSpeed(1.50);
    machine->AddComponent(hamster3);

    auto hamster4 = std::make_shared<Hamster>(mImagesDir);
    hamster4->SetPosition(70, 185);
    hamster4->SetInitiallyRunning(true);
    hamster4->SetSpeed(1.50);
    machine->AddComponent(hamster4);

    auto hamster5 = std::make_shared<Hamster>(mImagesDir);
    hamster5->SetPosition(150, 185);
    hamster5->SetInitiallyRunning(true);
    hamster5->SetSpeed(1.50);
    machine->AddComponent(hamster5);

    auto hamster34 = std::make_shared<Hamster>(mImagesDir);
    hamster34->SetPosition(230, 185);
    hamster34->SetInitiallyRunning(true);
    hamster34->SetSpeed(1.50);
    machine->AddComponent(hamster34);



    auto hamster6 = std::make_shared<Hamster>(mImagesDir);
    hamster6->SetPosition(-250, 125);
    hamster6->SetInitiallyRunning(true);
    hamster6->SetSpeed(1.50);
    machine->AddComponent(hamster6);

    auto hamster7 = std::make_shared<Hamster>(mImagesDir);
    hamster7->SetPosition(-170, 125);
    hamster7->SetInitiallyRunning(true);
    hamster7->SetSpeed(1.50);
    machine->AddComponent(hamster7);

    auto hamster8 = std::make_shared<Hamster>(mImagesDir);
    hamster8->SetPosition(-90, 125);
    hamster8->SetInitiallyRunning(true);
    hamster8->SetSpeed(1.50);
    machine->AddComponent(hamster8);

    auto hamster9 = std::make_shared<Hamster>(mImagesDir);
    hamster9->SetPosition(-10, 125);
    hamster9->SetInitiallyRunning(true);
    hamster9->SetSpeed(1.50);
    machine->AddComponent(hamster9);

    auto hamster10 = std::make_shared<Hamster>(mImagesDir);
    hamster10->SetPosition(70, 125);
    hamster10->SetInitiallyRunning(true);
    hamster10->SetSpeed(1.50);
    machine->AddComponent(hamster10);

    auto hamster11 = std::make_shared<Hamster>(mImagesDir);
    hamster11->SetPosition(150, 125);
    hamster11->SetInitiallyRunning(true);
    hamster11->SetSpeed(1.50);
    machine->AddComponent(hamster11);

    auto hamster33 = std::make_shared<Hamster>(mImagesDir);
    hamster33->SetPosition(230, 125);
    hamster33->SetInitiallyRunning(true);
    hamster33->SetSpeed(1.50);
    machine->AddComponent(hamster33);



    auto hamster12 = std::make_shared<Hamster>(mImagesDir);
    hamster12->SetPosition(-250, 65);
    hamster12->SetInitiallyRunning(true);
    hamster12->SetSpeed(1.50);
    machine->AddComponent(hamster12);

    auto hamster13 = std::make_shared<Hamster>(mImagesDir);
    hamster13->SetPosition(-170, 65);
    hamster13->SetInitiallyRunning(true);
    hamster13->SetSpeed(1.50);
    machine->AddComponent(hamster13);

    auto hamster14 = std::make_shared<Hamster>(mImagesDir);
    hamster14->SetPosition(-90, 65);
    hamster14->SetInitiallyRunning(true);
    hamster14->SetSpeed(1.50);
    machine->AddComponent(hamster14);

    auto hamster15 = std::make_shared<Hamster>(mImagesDir);
    hamster15->SetPosition(-10, 65);
    hamster15->SetInitiallyRunning(true);
    hamster15->SetSpeed(1.50);
    machine->AddComponent(hamster15);

    auto hamster16 = std::make_shared<Hamster>(mImagesDir);
    hamster16->SetPosition(70, 65);
    hamster16->SetInitiallyRunning(true);
    hamster16->SetSpeed(1.50);
    machine->AddComponent(hamster16);

    auto hamster17 = std::make_shared<Hamster>(mImagesDir);
    hamster17->SetPosition(150, 65);
    hamster17->SetInitiallyRunning(true);
    hamster17->SetSpeed(1.50);
    machine->AddComponent(hamster17);

    auto hamster32 = std::make_shared<Hamster>(mImagesDir);
    hamster32->SetPosition(230, 65);
    hamster32->SetInitiallyRunning(true);
    hamster32->SetSpeed(1.50);
    machine->AddComponent(hamster32);



    auto hamster18 = std::make_shared<Hamster>(mImagesDir);
    hamster18->SetPosition(-250, 5);
    hamster18->SetInitiallyRunning(true);
    hamster18->SetSpeed(1.50);
    machine->AddComponent(hamster18);

    auto hamster19 = std::make_shared<Hamster>(mImagesDir);
    hamster19->SetPosition(-170, 5);
    hamster19->SetInitiallyRunning(true);
    hamster19->SetSpeed(1.50);
    machine->AddComponent(hamster19);

    auto hamster20 = std::make_shared<Hamster>(mImagesDir);
    hamster20->SetPosition(-90, 5);
    hamster20->SetInitiallyRunning(true);
    hamster20->SetSpeed(1.50);
    machine->AddComponent(hamster20);

    auto hamster21 = std::make_shared<Hamster>(mImagesDir);
    hamster21->SetPosition(-10, 5);
    hamster21->SetInitiallyRunning(true);
    hamster21->SetSpeed(1.50);
    machine->AddComponent(hamster21);

    auto hamster22 = std::make_shared<Hamster>(mImagesDir);
    hamster22->SetPosition(70, 5);
    hamster22->SetInitiallyRunning(true);
    hamster22->SetSpeed(1.50);
    machine->AddComponent(hamster22);

    auto hamster23 = std::make_shared<Hamster>(mImagesDir);
    hamster23->SetPosition(150, 5);
    hamster23->SetInitiallyRunning(true);
    hamster23->SetSpeed(1.50);
    machine->AddComponent(hamster23);

    auto hamster31 = std::make_shared<Hamster>(mImagesDir);
    hamster31->SetPosition(230, 5);
    hamster31->SetInitiallyRunning(true);
    hamster31->SetSpeed(1.50);
    machine->AddComponent(hamster31);
    
    
    
    auto hamster24 = std::make_shared<Hamster>(mImagesDir);
    hamster24->SetPosition(-250, 245);
    hamster24->SetInitiallyRunning(true);
    hamster24->SetSpeed(1.50);
    machine->AddComponent(hamster24);

    auto hamster25 = std::make_shared<Hamster>(mImagesDir);
    hamster25->SetPosition(-170, 245);
    hamster25->SetInitiallyRunning(true);
    hamster25->SetSpeed(1.50);
    machine->AddComponent(hamster25);

    auto hamster26 = std::make_shared<Hamster>(mImagesDir);
    hamster26->SetPosition(-90, 245);
    hamster26->SetInitiallyRunning(true);
    hamster26->SetSpeed(1.50);
    machine->AddComponent(hamster26);

    auto hamster27 = std::make_shared<Hamster>(mImagesDir);
    hamster27->SetPosition(-10, 245);
    hamster27->SetInitiallyRunning(true);
    hamster27->SetSpeed(1.50);
    machine->AddComponent(hamster27);

    auto hamster28 = std::make_shared<Hamster>(mImagesDir);
    hamster28->SetPosition(70, 245);
    hamster28->SetInitiallyRunning(true);
    hamster28->SetSpeed(1.50);
    machine->AddComponent(hamster28);

    auto hamster29 = std::make_shared<Hamster>(mImagesDir);
    hamster29->SetPosition(150, 245);
    hamster29->SetInitiallyRunning(true);
    hamster29->SetSpeed(1.50);
    machine->AddComponent(hamster29);

    auto hamster30 = std::make_shared<Hamster>(mImagesDir);
    hamster30->SetPosition(230, 245);
    hamster30->SetInitiallyRunning(true);
    hamster30->SetSpeed(1.50);
    machine->AddComponent(hamster30);



    auto hamster35 = std::make_shared<Hamster>(mImagesDir);
    hamster35->SetPosition(-250, 305);
    hamster35->SetInitiallyRunning(true);
    hamster35->SetSpeed(1.50);
    machine->AddComponent(hamster35);

    auto hamster36 = std::make_shared<Hamster>(mImagesDir);
    hamster36->SetPosition(-170, 305);
    hamster36->SetInitiallyRunning(true);
    hamster36->SetSpeed(1.50);
    machine->AddComponent(hamster36);

    auto hamster37 = std::make_shared<Hamster>(mImagesDir);
    hamster37->SetPosition(-90, 305);
    hamster37->SetInitiallyRunning(true);
    hamster37->SetSpeed(1.50);
    machine->AddComponent(hamster37);

    auto hamster38 = std::make_shared<Hamster>(mImagesDir);
    hamster38->SetPosition(-10, 305);
    hamster38->SetInitiallyRunning(true);
    hamster38->SetSpeed(1.50);
    machine->AddComponent(hamster38);

    auto hamster39 = std::make_shared<Hamster>(mImagesDir);
    hamster39->SetPosition(70, 305);
    hamster39->SetInitiallyRunning(true);
    hamster39->SetSpeed(1.50);
    machine->AddComponent(hamster39);

    auto hamster40 = std::make_shared<Hamster>(mImagesDir);
    hamster40->SetPosition(150, 305);
    hamster40->SetInitiallyRunning(true);
    hamster40->SetSpeed(1.50);
    machine->AddComponent(hamster40);

    auto hamster41 = std::make_shared<Hamster>(mImagesDir);
    hamster41->SetPosition(230, 305);
    hamster41->SetInitiallyRunning(true);
    hamster41->SetSpeed(1.50);
    machine->AddComponent(hamster41);

    return machine;
}



/**
 * Generate the top beam and its basketball
 *
 * The top beam and ramp and basketball that
 * rolls right and goes through the hoop.
 * @param machine Beam to generate
 */
void Machine2Factory::TopBeamAndRamp(std::shared_ptr<Machine> machine)
{
    const double BeamX = -25;
    auto beam1 = std::make_shared<Body>();
    beam1->BottomCenteredRectangle(400, 20);
    beam1->SetImage(mImagesDir + L"/beam.png");
    beam1->SetInitialPosition(BeamX, 300);
    machine->AddComponent(beam1);

    auto wedge1 = std::make_shared<Body>();
    wedge1->AddPoint(-25, 0);
    wedge1->AddPoint(25, 0);
    wedge1->AddPoint(25, 4.5);
    wedge1->AddPoint(-25, 25);
    wedge1->SetImage(mImagesDir + L"/wedge.png");
    wedge1->SetInitialPosition(BeamX-175, 320);
    machine->AddComponent(wedge1);

    // Basketball 1
    auto basketball1 = std::make_shared<Body>();
    basketball1->Circle(12);
    basketball1->SetImage(mImagesDir + L"/basketball1.png");
    basketball1->SetInitialPosition(BeamX-186, 353);
    basketball1->SetDynamic();
    basketball1->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(basketball1);
}

/**
 * Create a stack of 9 dominos.
 * @param machine Machine to add to
 * @param position The position to draw the domino stack at
 */
void Machine2Factory::DominoStack(std::shared_ptr<Machine> machine, wxPoint2DDouble position)
{
    Domino(machine, position + wxPoint2DDouble(30, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(10, DominoHeight/2), 0, DominoColor::Blue);
    Domino(machine, position + wxPoint2DDouble(20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Green);

    Domino(machine, position + wxPoint2DDouble(-10, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-30, DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(-20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);

    const int DominoLevel2 = DominoHeight + DominoWidth;

    Domino(machine, position + wxPoint2DDouble(10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(0, DominoLevel2 + DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);
}

/**
 * This is the second beam from the top and the spinning arm that hits the ball
 * @param machine Machine to add to
 */
void Machine2Factory::BeamAndSpinningArm(std::shared_ptr<Machine> machine)
{
    const double Beam2X = -25;
    auto beam2 = std::make_shared<Body>();
    beam2->BottomCenteredRectangle(400, 20);
    beam2->SetImage(mImagesDir + L"/beam.png");
    beam2->SetInitialPosition(Beam2X, 240);
    machine->AddComponent(beam2);

    // Basketball 2
    auto basketball2 = std::make_shared<Body>();
    basketball2->Circle(12);
    basketball2->SetImage(mImagesDir + L"/basketball2.png");
    basketball2->SetInitialPosition(Beam2X - 170, 240 + 12 + 20);
    basketball2->SetDynamic();
    basketball2->SetPhysics(1, 0.5, 0.75);
    machine->AddComponent(basketball2);

    //
    // The hamster motor for the second-beam
    //
    auto hamster = std::make_shared<Hamster>(mImagesDir);
    hamster->SetPosition(-220, 185);
    hamster->SetInitiallyRunning(true);      // Initially running
    hamster->SetSpeed(1.50);
    machine->AddComponent(hamster);
    auto hamster1shaft = hamster->GetShaftPosition();

    auto arm = std::make_shared<Body>();
    arm->SetInitialPosition(hamster1shaft.m_x, hamster1shaft.m_y);
    arm->AddPoint(-7, 10);
    arm->AddPoint(7, 10);
    arm->AddPoint(7, -60);
    arm->AddPoint(-7, -60);
    arm->SetImage(mImagesDir + L"/arm.png");
    arm->SetKinematic();
    machine->AddComponent(arm);

    hamster->GetSource()->AddSink(arm);
}

/**
 * Add the basketball goal to the machine
 * @param machine Machine to add to
 */
void Machine2Factory::BasketballGoal(std::shared_ptr<Machine> machine)
{
    auto goal = std::make_shared<Goal>(mImagesDir);
    goal->SetPosition(270, 0);
    machine->AddComponent(goal);
}

/**
 * Create the beam that has 10 dominoes on it.
 * @param machine Machine to add bem to
 * @param position Location to place the beam.
 */
void Machine2Factory::DominoesOnBeam(std::shared_ptr<Machine> machine, wxPoint2DDouble position)
{
    // The beam the dominoes sit on
    auto beam = std::make_shared<Body>();
    beam->BottomCenteredRectangle(150, 15);
    beam->SetImage(mImagesDir + L"/beam.png");
    beam->SetInitialPosition(position.m_x, position.m_y);
    machine->AddComponent(beam);

    for(int d=0; d<10; d++)
    {
        // Where to put this domino
        auto dominos = position + wxPoint2DDouble(-70 + d * 15, 27);

        Domino(machine, dominos, 0, DominoColor::Green);
    }
}


/**
 * Create a Domino and add it to the machine.
 *
 * This has been created to make it easier to create
 * a lot of dominos
 *
 * @param machine Machine to add the domino to
 * @param position Position to place the center of the domino
 * @param rotation Rotation in turns
 * @param color Color code
 * @return Returns the created domino body
 */
std::shared_ptr<Body>  Machine2Factory::Domino(std::shared_ptr<Machine> machine, wxPoint2DDouble position, double rotation, DominoColor color)
{
    auto x = position.m_x;
    auto y = position.m_y;

    auto domino = std::make_shared<Body>();
    domino->Rectangle(-DominoWidth/2, -DominoHeight/2, DominoWidth, DominoHeight);
    switch(color)
    {
        case DominoColor::Black:
            domino->SetImage(mImagesDir + L"/domino-black.png");
            break;

        case DominoColor::Red:
            domino->SetImage(mImagesDir + L"/domino-red.png");
            break;

        case DominoColor::Green:
            domino->SetImage(mImagesDir + L"/domino-green.png");
            break;

        case DominoColor::Blue:
            domino->SetImage(mImagesDir + L"/domino-blue.png");
            break;
    }

    domino->SetInitialPosition(x, y);
    domino->SetInitialRotation(rotation);
    domino->SetDynamic();
    machine->AddComponent(domino);

    return domino;
}


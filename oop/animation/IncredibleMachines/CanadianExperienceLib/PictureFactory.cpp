/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    auto machine1 = make_shared<MachineAdapter>(L"Machine 1", resourcesDir);
    auto machine2 = make_shared<MachineAdapter>(L"Machine 2", resourcesDir);

    picture->SetMachine1(machine1);
	picture->SetMachine2(machine2);

    machine1->SetMachineNumber(1);
	machine2->SetMachineNumber(2);

    auto machineActor1 = make_shared<Actor>(L"Machine1");
	machineActor1->SetPosition(wxPoint(550, 575));
	machineActor1->SetRoot(machine1);
	machineActor1->AddDrawable(machine1);
	picture->AddActor(machineActor1);

	auto machineActor2 = make_shared<Actor>(L"Machine2");
	machineActor2->SetPosition(wxPoint(1000, 650));
	machineActor2->SetRoot(machine2);
	machineActor2->AddDrawable(machine2);
	picture->AddActor(machineActor2);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    return picture;
}


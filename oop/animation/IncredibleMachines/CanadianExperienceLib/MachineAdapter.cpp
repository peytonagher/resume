/**
 * @file MachineAdapter.cpp
 * @author Peyton Nagher
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "../MachineLib/MachineDialog.h"
#include "../MachineLib/MachineSystemFactory.h"

using namespace std;

MachineAdapter::MachineAdapter(std::wstring name, std::wstring resourcesDir) : Drawable(name)
{
	mName = name;
    MachineSystemFactory factory(resourcesDir);
	mMachine = factory.CreateMachineSystem();
}

void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	auto frame = GetAngleChannel()->GetTimeline()->GetCurrentFrame();
	auto rate = GetAngleChannel()->GetTimeline()->GetFrameRate();

	double scale = 0.5f;
	graphics->PushState();
	graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
	graphics->Scale(scale, scale);
	mMachine->SetLocation(wxPoint(0,0));
	mMachine->DrawMachine(graphics);
	graphics->PopState();

	if (frame > mFirstFrame && frame < mFinalFrame)
	{
		mMachine->SetMachineFrame(frame);
		mMachine->SetFrameRate(rate);
	}
}

int MachineAdapter::ShowDialogBox(wxWindow* parent, Picture* picture)
{
	MachineDialog MachineDialog(parent, mMachine);
	return MachineDialog.ShowModal();
}

int MachineAdapter::ShowFrameDialogBox(wxWindow *parent)
{
	MachineDialog MachineDialog(parent, mMachine);
	return MachineDialog.ShowModal();
}

wxXmlNode *MachineAdapter::SaveMachine1(wxXmlNode *root)
{
	wxString number = wxString::Format(wxString("%i"), mMachine->GetMachineNumber());
	wxString startFrame = wxString::Format(wxString("%i"), mFirstFrame);
	wxString endFrame = wxString::Format(wxString("%i"), mFinalFrame);

	auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"Machine1");

	root->AddChild(itemNode);
	itemNode->AddAttribute(L"Machine", number);
	itemNode->AddAttribute(L"FirstFrame", startFrame);
	itemNode->AddAttribute(L"FinalFrame", endFrame);

	return itemNode;
}

wxXmlNode *MachineAdapter::SaveMachine2(wxXmlNode *root)
{
	wxString number = wxString::Format(wxString("%i"), mMachine->GetMachineNumber());
	wxString startFrame = wxString::Format(wxString("%i"), mFirstFrame);
	wxString endFrame = wxString::Format(wxString("%i"), mFinalFrame);

	auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"Machine2");

	root->AddChild(itemNode);
	itemNode->AddAttribute(L"Machine", number);
	itemNode->AddAttribute(L"FirstFrame", startFrame);
	itemNode->AddAttribute(L"FinalFrame", endFrame);

	return itemNode;
}

void MachineAdapter::LoadMachine1(wxXmlNode *root)
{
	int machineNum = 1;
	int startFrame = 0;
	int endFrame = 900;

	root->GetAttribute(L"Machine1").ToInt(&machineNum);
	root->GetAttribute(L"FirstFrame").ToInt(&startFrame);
	root->GetAttribute(L"FinalFrame").ToInt(&endFrame);

	mMachine->SetMachineNumber(machineNum);
	mFirstFrame = startFrame;
	mFinalFrame = endFrame;
}

void MachineAdapter::LoadMachine2(wxXmlNode *root)
{
	int machineNum = 2;
	int startFrame = 0;
	int endFrame = 900;

	root->GetAttribute(L"Machine2").ToInt(&machineNum);
	root->GetAttribute(L"FirstFrame").ToInt(&startFrame);
	root->GetAttribute(L"FinalFrame").ToInt(&endFrame);

	mMachine->SetMachineNumber(machineNum);
	mFirstFrame = startFrame;
	mFinalFrame = endFrame;
}

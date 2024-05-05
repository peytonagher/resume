/**
 * @file MachineAdapter.h
 * @author Peyton Nagher
 *
 * Adapter that allows a machine system to be treated as a drawable object
 *
 * Inherits from both Drawable and IMachineSystem
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINEADAPTER_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINEADAPTER_H

#include "Drawable.h"
#include "Picture.h"
#include "../MachineLib/IMachineSystem.h"

class MachineAdapter : public Drawable
{
private:
    /// Name of machine being adapted
    wxString mName;
    /// Start time of the machine system
    double mStartTime = 0;
    /// Starting frame number of machine system
    int mFirstFrame = 0;
    /// Total amount of frames for machine system
    int mFinalFrame = 900;
    /// Shared pointer to machine system that the adapter wraps
    std::shared_ptr<IMachineSystem> mMachine;

public:
    /**
     * Constructs a new MachineAdapter
     * @param name of the drawable object
     * @param machine system that this adapter wraps
     */
    MachineAdapter(std::wstring name, std::wstring resourcesDir);

    /**
     * Draws the machine system, overrides same function in Drawable base class
     * so the machine system can be drawn on a wxGraphicsContext
     * @param graphics context to draw on
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override { return false; }
	void SetStartFrame(int startFrame) { mFirstFrame = startFrame; }
	void SetEndFrame(int endFrame) { mFinalFrame = endFrame; }
	void SetMachineNumber(int num) { mMachine->SetMachineNumber(num); }
	void SetLocation(wxPoint pos) { mMachine->SetLocation(pos); }
	int ShowDialogBox(wxWindow *parent, Picture *picture);
	int ShowFrameDialogBox(wxWindow* parent);
	int GetStartFrame() const { return mFirstFrame; }
	int GetEndFrame() const { return mFinalFrame; }
	wxXmlNode* SaveMachine1(wxXmlNode* root);
	wxXmlNode* SaveMachine2(wxXmlNode* root);
	void LoadMachine1(wxXmlNode* root);
	void LoadMachine2(wxXmlNode* root);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINEADAPTER_H

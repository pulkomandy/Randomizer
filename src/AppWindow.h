//========================================================================
//	AppWindow.h
//
//	Copyright 2005-2009 Sergey Kazenyuk, All Rights Reserved.
//  Copyright 2018 Janus
//	Distributed under the terms of the MIT License.
//========================================================================
//	$Id: AppWindow.h 11 2009-02-01 16:13:11Z sergey.kazenyuk $
//	$Rev: 11 $
//	$Author: sergey.kazenyuk $
//	$Date: 2009-02-01 18:13:11 +0200 (Sun, 01 Feb 2009) $
//========================================================================

#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <Bitmap.h>
#include <Button.h>
#include <CheckBox.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Spinner.h>
#include <TextControl.h>
#include <Window.h>

//====================================================================

class AppWindow : public BWindow
{
public:
	AppWindow(BRect frame);
	virtual void MessageReceived(BMessage* message);
	virtual bool QuitRequested();

private:
	BMenuBar* BuildMenuBar(); // Menu bar setup
	void GeneratePassword();
	BBitmap* ResourceVectorToBitmap(const char* resName, float iconSize);

	BFile PrefsFile(int32 mode);
	void SavePreferences(BMessage& msg);
	void LoadPreferences(BMessage& msg);

	void ArchivePreferences();
	void UnarchivePreferences();

	BTextControl* PassOut; // Generated password output
	BButton* GenerateBtn;
	BButton* CopyToClipboardBtn;
	BSpinner* PassLength;
	BCheckBox* UpperCaseCB;
	BCheckBox* LowerCaseCB;
	BCheckBox* NumCB;
	BCheckBox* SpecSymbCB;
	BCheckBox* CustSymbCB; // Custom symbols checkbox
	BTextControl* CustSymb; // Custom symbols input field
};

#endif



// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CMSystemJGDDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgFrame.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgEditor.h"
#include "CATDlgCombo.h"
#include "CATDlgEditor.h"
#include "CATDlgEditor.h"
#include "CATDlgEditor.h"

// Begin of User Code

// End of User Code

CMSystemJGDDlg::CMSystemJGDDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
|CATDlgWndAPPLY
|CATDlgWndAutoResize
|CATDlgWndNoResize
| CATDlgGridLayout
)
{

_Frame1 = NULL;
_Label1 = NULL;
_Label2 = NULL;
_Label3 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Label6 = NULL;
_Editor1 = NULL;
_Editor2 = NULL;
_Combo1 = NULL;
_Editor3 = NULL;
_Editor4 = NULL;
_Editor5 = NULL;

// Begin of User Code

// End of User Code

}

CMSystemJGDDlg::~CMSystemJGDDlg()
{

// Begin of User Code

// End of User Code
_Frame1 = NULL;
_Label1 = NULL;
_Label2 = NULL;
_Label3 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Label6 = NULL;
_Editor1 = NULL;
_Editor2 = NULL;
_Combo1 = NULL;
_Editor3 = NULL;
_Editor4 = NULL;
_Editor5 = NULL;

}



void CMSystemJGDDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Frame1=new CATDlgFrame(this,(const char*)"Frame1",0|CATDlgGridLayout);
_Label1=new CATDlgLabel(_Frame1,(const char*)"Label1",0);
_Label2=new CATDlgLabel(_Frame1,(const char*)"Label2",0);
_Label3=new CATDlgLabel(_Frame1,(const char*)"Label3",0);
_Label4=new CATDlgLabel(_Frame1,(const char*)"Label4",0);
_Label5=new CATDlgLabel(_Frame1,(const char*)"Label5",0);
_Label6=new CATDlgLabel(_Frame1,(const char*)"Label6",0);
_Editor1=new CATDlgEditor(_Frame1,(const char*)"Editor1",0);
_Editor2=new CATDlgEditor(_Frame1,(const char*)"Editor2",0);
_Combo1=new CATDlgCombo(_Frame1,(const char*)"Combo1",0|CATDlgCmbDropDown);
_Editor3=new CATDlgEditor(_Frame1,(const char*)"Editor3",0);
_Editor4=new CATDlgEditor(_Frame1,(const char*)"Editor4",0);
_Editor5=new CATDlgEditor(_Frame1,(const char*)"Editor5",0);
this->SetGridRowResizable(0,1);
this->SetGridColumnResizable(1,1);
this->SetGridColumnResizable(2,1);
this->SetGridColumnResizable(3,1);
this->SetRectDimensions(0,0,300,300);
_Frame1->SetGridConstraints(0,0,4,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame1->SetGridRowResizable(0,1);
_Frame1->SetGridRowResizable(2,1);
_Frame1->SetGridRowResizable(4,1);
_Frame1->SetGridRowResizable(6,1);
_Frame1->SetGridRowResizable(8,1);
_Frame1->SetGridRowResizable(10,1);
_Frame1->SetGridColumnResizable(1,1);
_Frame1->SetGridColumnResizable(2,1);
_Frame1->SetGridColumnResizable(3,1);
_Frame1->SetGridColumnResizable(4,1);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label2->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label3->SetGridConstraints(4,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label4->SetGridConstraints(6,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label5->SetGridConstraints(8,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label6->SetGridConstraints(10,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor1->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor2->SetSensitivity(CATDlgDisable);
_Editor2->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor2->SetText("JGD");
_Combo1->SetGridConstraints(4,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor3->SetGridConstraints(6,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor4->SetSensitivity(CATDlgDisable);
_Editor4->SetGridConstraints(8,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor4->SetText("A.1");
_Editor5->SetGridConstraints(10,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);

// Begin of User Code
this->SetRectDimensions(800, 300, 300, 300);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
CATDlgEditor* CMSystemJGDDlg::GetEditor(int iCtrlID)
{
	/*
	ID_NameEditor,
	ID_WorkTypeEditor,
	ID_AirCraftNoEdiror,
	ID_VersionEditor,
	ID_CommentsEdirot,
	ID_TypeCombo
	*/
	CATDlgEditor* pEditor = NULL;
	switch (iCtrlID)
	{
	case ID_NameEditor:
		pEditor = _Editor1;
		break;
	case ID_WorkTypeEditor:
		pEditor = _Editor2;
		break;
	case ID_AirCraftNoEdiror:
		pEditor = _Editor3;
		break;
	case ID_VersionEditor:
		pEditor = _Editor4;
		break;
	case ID_CommentsEditor:
		pEditor = _Editor5;
		break;
	default:
		break;
	}

	return pEditor;
}

CATDlgCombo* CMSystemJGDDlg::GetCombo(int iCtrlID)
{
	CATDlgCombo * pCombo = NULL;
	switch (iCtrlID)
	{
	case ID_TypeCombo:
		pCombo = _Combo1;
		break;
	default:
		break;
	}
	return pCombo;
}
// End of User Code


// End of implementation of class methods



// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CMSystemGTOBOMDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgCombo.h"
#include "CATDlgLabel.h"
#include "CATDlgCombo.h"
#include "CATDlgLabel.h"
#include "CATDlgCombo.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"

// Begin of User Code

// End of User Code

CMSystemGTOBOMDlg::CMSystemGTOBOMDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
|CATDlgWndAPPLY
|CATDlgWndAutoResize
|CATDlgWndNoResize
| CATDlgGridLayout
)
{

_Label1 = NULL;
_Editor4 = NULL;
_Label7 = NULL;
_Editor3 = NULL;
_Label6 = NULL;
_Combo3 = NULL;
_Label5 = NULL;
_Combo2 = NULL;
_Label4 = NULL;
_Combo1 = NULL;
_Label3 = NULL;
_Editor2 = NULL;
_Label2 = NULL;
_Editor1 = NULL;

// Begin of User Code

// End of User Code

}

CMSystemGTOBOMDlg::~CMSystemGTOBOMDlg()
{

// Begin of User Code

// End of User Code
_Label1 = NULL;
_Editor4 = NULL;
_Label7 = NULL;
_Editor3 = NULL;
_Label6 = NULL;
_Combo3 = NULL;
_Label5 = NULL;
_Combo2 = NULL;
_Label4 = NULL;
_Combo1 = NULL;
_Label3 = NULL;
_Editor2 = NULL;
_Label2 = NULL;
_Editor1 = NULL;

}



void CMSystemGTOBOMDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Label1=new CATDlgLabel(this,(const char*)"Label1",0);
_Editor4=new CATDlgEditor(this,(const char*)"Editor4",0);
_Label7=new CATDlgLabel(this,(const char*)"Label7",0);
_Editor3=new CATDlgEditor(this,(const char*)"Editor3",0);
_Label6=new CATDlgLabel(this,(const char*)"Label6",0);
_Combo3=new CATDlgCombo(this,(const char*)"Combo3",0|CATDlgCmbDropDown);
_Label5=new CATDlgLabel(this,(const char*)"Label5",0);
_Combo2=new CATDlgCombo(this,(const char*)"Combo2",0|CATDlgCmbDropDown);
_Label4=new CATDlgLabel(this,(const char*)"Label4",0);
_Combo1=new CATDlgCombo(this,(const char*)"Combo1",0|CATDlgCmbDropDown);
_Label3=new CATDlgLabel(this,(const char*)"Label3",0);
_Editor2=new CATDlgEditor(this,(const char*)"Editor2",0);
_Label2=new CATDlgLabel(this,(const char*)"Label2",0);
_Editor1=new CATDlgEditor(this,(const char*)"Editor1",0);
this->SetGridRowResizable(0,1);
this->SetGridRowResizable(2,1);
this->SetGridRowResizable(4,1);
this->SetGridRowResizable(6,1);
this->SetGridRowResizable(8,1);
this->SetGridRowResizable(10,1);
this->SetGridRowResizable(12,1);
this->SetGridColumnResizable(1,1);
this->SetGridColumnResizable(2,1);
this->SetGridColumnResizable(3,1);
this->SetGridColumnResizable(4,1);
this->SetGridColumnResizable(5,1);
this->SetGridColumnResizable(6,1);
this->SetGridColumnResizable(7,1);
this->SetRectDimensions(0,0,300,300);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor4->SetGridConstraints(12,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label7->SetGridConstraints(12,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor3->SetSensitivity(CATDlgDisable);
_Editor3->SetGridConstraints(10,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor3->SetText("A.1");
_Label6->SetGridConstraints(10,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Combo3->SetGridConstraints(8,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label5->SetGridConstraints(8,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Combo2->SetGridConstraints(6,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label4->SetGridConstraints(6,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Combo1->SetGridConstraints(4,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label3->SetGridConstraints(4,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor2->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label2->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor1->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);

// Begin of User Code
this->SetRectDimensions(800, 300, 300, 300);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
CATDlgEditor* CMSystemGTOBOMDlg::GetEditor(int iCtrlID)
{
	/*
	ID_NumberEditor,			//CUS_GTOPart_PartCode
	ID_PartNameEditor,			//CUS_GTOPart_PartName
	ID_VersionEditor,			//
	ID_DescriptionEditor,		//CUS_GTOPart_Description
	ID_PartCodeCombo,			//CUS_GTOPart_Number
	ID_MFGDEPTCombo,			//CUS_GTOPart_Department
	ID_APLDEPTCombo				//CUS_GTOPart_Application
	*/
	CATDlgEditor* pEditor = NULL;
	switch (iCtrlID)
	{
	case ID_NumberEditor:
		pEditor = _Editor1;
		break;
	case ID_PartNameEditor:
		pEditor = _Editor2;
		break;
	case ID_VersionEditor:
		pEditor = _Editor3;
		break;
	case ID_DescriptionEditor:
		pEditor = _Editor4;
		break;
	default:
		break;
	}

	return pEditor;
}

CATDlgCombo* CMSystemGTOBOMDlg::GetCombo(int iCtrlID)
{
	CATDlgCombo * pCombo = NULL;
	switch (iCtrlID)
	{
	case ID_PartCodeCombo:
		pCombo = _Combo1;
		break;
	case ID_MFGDEPTCombo:
		pCombo = _Combo2;
		break;
	case ID_APLDEPTCombo:
		pCombo = _Combo3;
		break;
	default:
		break;
	}
	return pCombo;
}
// End of User Code


// End of implementation of class methods

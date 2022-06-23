

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CMSystemFTZWDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgCombo.h"
#include "CATDlgEditor.h"
#include "CATDlgCombo.h"
#include "CATDlgEditor.h"

// Begin of User Code

// End of User Code

CMSystemFTZWDlg::CMSystemFTZWDlg(CATDialog* iParent, const CATString& iName)
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
_Label2 = NULL;
_Label3 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Editor1 = NULL;
_Combo2 = NULL;
_Editor3 = NULL;
_Combo1 = NULL;
_Editor4 = NULL;

// Begin of User Code

// End of User Code

}

CMSystemFTZWDlg::~CMSystemFTZWDlg()
{

// Begin of User Code

// End of User Code
_Label1 = NULL;
_Label2 = NULL;
_Label3 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Editor1 = NULL;
_Combo2 = NULL;
_Editor3 = NULL;
_Combo1 = NULL;
_Editor4 = NULL;

}



void CMSystemFTZWDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Label1=new CATDlgLabel(this,(const char*)"Label1",0);
_Label2=new CATDlgLabel(this,(const char*)"Label2",0);
_Label3=new CATDlgLabel(this,(const char*)"Label3",0);
_Label4=new CATDlgLabel(this,(const char*)"Label4",0);
_Label5=new CATDlgLabel(this,(const char*)"Label5",0);
_Editor1=new CATDlgEditor(this,(const char*)"Editor1",0);
_Combo2=new CATDlgCombo(this,(const char*)"Combo2",0|CATDlgCmbDropDown);
_Editor3=new CATDlgEditor(this,(const char*)"Editor3",0|CATDlgEdtNumerical);
_Combo1=new CATDlgCombo(this,(const char*)"Combo1",0|CATDlgCmbDropDown);
_Editor4=new CATDlgEditor(this,(const char*)"Editor4",0);
this->SetGridRowResizable(0,1);
this->SetGridRowResizable(2,1);
this->SetGridRowResizable(4,1);
this->SetGridRowResizable(6,1);
this->SetGridRowResizable(8,1);
this->SetGridColumnResizable(1,1);
this->SetGridColumnResizable(2,1);
this->SetGridColumnResizable(3,1);
this->SetGridColumnResizable(4,1);
this->SetGridColumnResizable(5,1);
this->SetGridColumnResizable(6,1);
this->SetGridColumnResizable(7,1);
this->SetGridColumnResizable(8,1);
this->SetRectDimensions(0,0,300,300);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label2->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label3->SetGridConstraints(4,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label4->SetGridConstraints(6,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label5->SetGridConstraints(8,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor1->SetSensitivity(CATDlgDisable);
_Editor1->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor1->SetText("8012");
_Combo2->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor3->SetGridConstraints(4,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Combo1->SetGridConstraints(6,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor4->SetGridConstraints(8,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);

// Begin of User Code
this->SetRectDimensions(800, 300, 300, 300);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
CATDlgEditor* CMSystemFTZWDlg::GetEditor(int iCtrlID)
{
	CATDlgEditor* pEditor = NULL;
	switch (iCtrlID)
	{
	case ID_PartCodeEditor:
		pEditor = _Editor1;
		break;
	case ID_NameEditor:
		pEditor = _Editor3;
		break;
	case ID_ValidEditor:
		pEditor = _Editor4;
		break;
	default:
		break;
	}

	return pEditor;
}

CATDlgCombo* CMSystemFTZWDlg::GetCombo(int iCtrlID)
{
	CATDlgCombo * pCombo = NULL;
	switch (iCtrlID)
	{
	case ID_JobStylesCombo:
		pCombo = _Combo1;
		break;
	case ID_MachineCodeCombo:
		pCombo = _Combo2;
		break;
	default:
		break;
	}
	return pCombo;
}

// End of User Code


// End of implementation of class methods

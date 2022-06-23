

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CreateWorkingProcedureDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgFrame.h"
#include "CATDlgRadioButton.h"
#include "CATDlgRadioButton.h"
#include "CATDlgRadioButton.h"
#include "CATDlgCheckButton.h"

// Begin of User Code

// End of User Code

CreateWorkingProcedureDlg::CreateWorkingProcedureDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
|CATDlgWndAutoResize
|CATDlgWndNoResize
| CATDlgGridLayout
)
{

_Label1 = NULL;
_Editor1 = NULL;
_Label3 = NULL;
_Editor2 = NULL;
_Frame1 = NULL;
_RadioButton2 = NULL;
_RadioButton1 = NULL;
_RadioButton3 = NULL;
_CheckButton1 = NULL;

// Begin of User Code

// End of User Code

}

CreateWorkingProcedureDlg::~CreateWorkingProcedureDlg()
{

// Begin of User Code

// End of User Code
_Label1 = NULL;
_Editor1 = NULL;
_Label3 = NULL;
_Editor2 = NULL;
_Frame1 = NULL;
_RadioButton2 = NULL;
_RadioButton1 = NULL;
_RadioButton3 = NULL;
_CheckButton1 = NULL;

}



void CreateWorkingProcedureDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Label1=new CATDlgLabel(this,(const char*)"Label1",0);
_Editor1=new CATDlgEditor(this,(const char*)"Editor1",0|CATDlgEdtReadOnly);
_Label3=new CATDlgLabel(this,(const char*)"Label3",0);
_Editor2=new CATDlgEditor(this,(const char*)"Editor2",0|CATDlgEdtNumerical);
_Frame1=new CATDlgFrame(this,(const char*)"Frame1",0|CATDlgFraNoTitle|CATDlgFraNoFrame|CATDlgGridLayout);
_RadioButton2=new CATDlgRadioButton(_Frame1,(const char*)"RadioButton2",0);
_RadioButton1=new CATDlgRadioButton(_Frame1,(const char*)"RadioButton1",0);
_RadioButton3=new CATDlgRadioButton(_Frame1,(const char*)"RadioButton3",0);
_CheckButton1=new CATDlgCheckButton(this,(const char*)"CheckButton1",0);
this->SetGridRowResizable(1,1);
this->SetGridRowResizable(3,1);
this->SetGridRowResizable(5,1);
this->SetGridColumnResizable(0,1);
this->SetGridColumnResizable(1,1);
this->SetRectDimensions(0,0,200,300);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor1->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Label3->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor2->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Editor2->SetText("010");
_Frame1->SetGridConstraints(4,0,2,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame1->SetGridColumnResizable(0,1);
_Frame1->SetGridColumnResizable(1,1);
_RadioButton2->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_RadioButton1->SetGridConstraints(0,2,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_RadioButton3->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_RadioButton3->SetState(CATDlgCheck);
_CheckButton1->SetGridConstraints(6,0,2,1,0|CATGRID_LEFT|CATGRID_TOP);
_CheckButton1->SetState(CATDlgCheck);

// Begin of User Code
this->SetRectDimensions(200, 200, 200, 300);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
void CreateWorkingProcedureDlg::SetAOTitle(CATUnicodeString iTitle)
{
	_Editor1->SetText(iTitle);
}
CATUnicodeString CreateWorkingProcedureDlg::GetGXTypeName()
{
	if (_RadioButton2->GetState() == CATDlgCheck)
	{
		return "DELLmiLoadingOperationReference"; 
	}
	else if (_RadioButton1->GetState() == CATDlgCheck)
	{
		return "DELLmiUnloadingOperationReference";
	}
	else
	{
		return "DELLmiGeneralOperationReference";
	}
}
CATUnicodeString CreateWorkingProcedureDlg::GetGXTtitle()
{
	return _Editor2->GetText();
}
CATBoolean CreateWorkingProcedureDlg::IsReorder()
{
	if (_CheckButton1->GetState() == CATDlgCheck)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
// End of User Code


// End of implementation of class methods

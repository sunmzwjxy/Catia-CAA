

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CMSystemGTOOperationDuplicateDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgFrame.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgEditor.h"
#include "CATDlgLabel.h"
#include "CATDlgPushButton.h"
#include "CATDlgFrame.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgLabel.h"
#include "CATDlgPushButton.h"
#include "CATDlgPushButton.h"
#include "CATDlgPushButton.h"
#include "CATDlgSelectorList.h"
#include "CATDlgSelectorList.h"

// Begin of User Code
#include "CATListPtrCATIPLMNavReference.h"
#include "CATListPtrCATIPLMNavEntity.h"
#include "CATIPLMNavRepInstance.h"
#include "CUSCAAUtilService.h"

#include "CATOmbLifeCycleRootsBag.h"
#include "CATAdpOpenParameters.h"
#include "CATPLMSessionServices.h"
// End of User Code

CMSystemGTOOperationDuplicateDlg::CMSystemGTOOperationDuplicateDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
|CATDlgWndAPPLY
|CATDlgWndAutoResize
| CATDlgGridLayout
)
{

_Frame1 = NULL;
_Editor_GTOName = NULL;
_Label2 = NULL;
_Label6 = NULL;
_Editor_GTOTarget = NULL;
_Editor_GTOCode = NULL;
_Label1 = NULL;
_PushButton_Search = NULL;
_Frame2 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Label3 = NULL;
_PushButton_DeleteAll = NULL;
_PushButton_Delete = NULL;
_PushButton_Add = NULL;
_SelectorList_GTOOperatoinsDup = NULL;
_SelectorList_GTOOperations = NULL;

// Begin of User Code

// End of User Code

}

CMSystemGTOOperationDuplicateDlg::~CMSystemGTOOperationDuplicateDlg()
{

// Begin of User Code

// End of User Code
_Frame1 = NULL;
_Editor_GTOName = NULL;
_Label2 = NULL;
_Label6 = NULL;
_Editor_GTOTarget = NULL;
_Editor_GTOCode = NULL;
_Label1 = NULL;
_PushButton_Search = NULL;
_Frame2 = NULL;
_Label4 = NULL;
_Label5 = NULL;
_Label3 = NULL;
_PushButton_DeleteAll = NULL;
_PushButton_Delete = NULL;
_PushButton_Add = NULL;
_SelectorList_GTOOperatoinsDup = NULL;
_SelectorList_GTOOperations = NULL;

}



void CMSystemGTOOperationDuplicateDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Frame1=new CATDlgFrame(this,(const char*)"Frame1",0|CATDlgGridLayout);
_Editor_GTOName=new CATDlgEditor(_Frame1,(const char*)"Editor_GTOName",0);
_Label2=new CATDlgLabel(_Frame1,(const char*)"Label2",0);
_Label6=new CATDlgLabel(_Frame1,(const char*)"Label6",0);
_Editor_GTOTarget=new CATDlgEditor(_Frame1,(const char*)"Editor_GTOTarget",0);
_Editor_GTOCode=new CATDlgEditor(_Frame1,(const char*)"Editor_GTOCode",0|CATDlgEdtAlphanumerical);
_Label1=new CATDlgLabel(_Frame1,(const char*)"Label1",0);
_PushButton_Search=new CATDlgPushButton(_Frame1,(const char*)"PushButton_Search",0);
_Frame2=new CATDlgFrame(this,(const char*)"Frame2",0|CATDlgGridLayout);
_Label4=new CATDlgLabel(_Frame2,(const char*)"Label4",0);
_Label5=new CATDlgLabel(_Frame2,(const char*)"Label5",0);
_Label3=new CATDlgLabel(_Frame2,(const char*)"Label3",0);
_PushButton_DeleteAll=new CATDlgPushButton(_Frame2,(const char*)"PushButton_DeleteAll",0);
_PushButton_Delete=new CATDlgPushButton(_Frame2,(const char*)"PushButton_Delete",0);
_PushButton_Add=new CATDlgPushButton(_Frame2,(const char*)"PushButton_Add",0);
_SelectorList_GTOOperatoinsDup=new CATDlgSelectorList(_Frame2,(const char*)"SelectorList_GTOOperatoinsDup",0);
_SelectorList_GTOOperations=new CATDlgSelectorList(_Frame2,(const char*)"SelectorList_GTOOperations",0);
this->SetGridRowResizable(1,1);
this->SetGridColumnResizable(1,1);
_Frame1->SetGridConstraints(0,0,2,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame1->SetGridColumnResizable(0,1);
_Frame1->SetGridColumnResizable(1,1);
_Frame1->SetGridColumnResizable(3,1);
_Frame1->SetGridColumnResizable(4,1);
_Frame1->SetGridColumnResizable(5,1);
_Frame1->SetGridColumnResizable(6,1);
_Frame1->SetGridColumnResizable(7,1);
_Frame1->SetGridColumnResizable(8,1);
_Frame1->SetGridColumnResizable(9,1);
_Frame1->SetGridColumnResizable(10,1);
_Frame1->SetGridColumnResizable(11,1);
_Frame1->SetGridColumnResizable(12,1);
_Frame1->SetGridColumnResizable(13,1);
_Frame1->SetGridColumnResizable(14,1);
_Frame1->SetGridColumnResizable(15,1);
_Frame1->SetGridColumnResizable(16,1);
_Frame1->SetGridColumnResizable(17,1);
_Editor_GTOName->SetSensitivity(CATDlgDisable);
_Editor_GTOName->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT);
_Label2->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label6->SetGridConstraints(1,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor_GTOTarget->SetSensitivity(CATDlgDisable);
_Editor_GTOTarget->SetGridConstraints(1,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT);
_Editor_GTOCode->SetVisibility(CATDlgHide);
_Editor_GTOCode->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT);
_Label1->SetVisibility(CATDlgHide);
_Label1->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_PushButton_Search->SetGridConstraints(0,2,1,1,0);
_Frame2->SetGridConstraints(1,0,2,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame2->SetGridRowResizable(0,1);
_Frame2->SetGridRowResizable(1,1);
_Frame2->SetGridRowResizable(2,1);
_Frame2->SetGridRowResizable(3,1);
_Frame2->SetGridRowResizable(4,1);
_Frame2->SetGridRowResizable(5,1);
_Frame2->SetGridRowResizable(6,1);
_Frame2->SetGridRowResizable(7,1);
_Frame2->SetGridRowResizable(8,1);
_Frame2->SetGridRowResizable(9,1);
_Frame2->SetGridRowResizable(10,1);
_Frame2->SetGridColumnResizable(1,1);
_Frame2->SetGridColumnResizable(2,1);
_Frame2->SetGridColumnResizable(3,1);
_Frame2->SetGridColumnResizable(4,1);
_Frame2->SetGridColumnResizable(5,1);
_Frame2->SetGridColumnResizable(6,1);
_Frame2->SetGridColumnResizable(8,1);
_Frame2->SetGridColumnResizable(9,1);
_Frame2->SetGridColumnResizable(10,1);
_Frame2->SetGridColumnResizable(11,1);
_Frame2->SetGridColumnResizable(12,1);
_Label4->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label5->SetGridConstraints(0,8,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Label3->SetGridConstraints(5,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_PushButton_DeleteAll->SetGridConstraints(6,7,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_PushButton_Delete->SetGridConstraints(4,7,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_PushButton_Add->SetGridConstraints(2,7,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_SelectorList_GTOOperatoinsDup->SetGridConstraints(1,8,5,10,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_SelectorList_GTOOperations->SetGridConstraints(1,1,6,10,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);

// Begin of User Code

// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code

/*
	ID_GTOPartCodeEditor,					//CUS_GTOPart_PartCode
	ID_GTOPartNameEdiror,					//CUS_GTOPart_PartName
	ID_GTOOperatoinsDupSelectorList,		//_SelectorList_GTOOperatoinsDup
	ID_GTOOperationsSelectorList,			//_SelectorList_GTOOperations
	ID_GTOSearchButton,						//_PushButton_Search;
	ID_GTOAddButton,						//_PushButton_Add;
	ID_GTODeleteButton,						//_PushButton_Delete;
	ID_GTODeleteAll							// _PushButton_DeleteAll;
*/
CATDlgEditor* CMSystemGTOOperationDuplicateDlg::GetEditor(int iCtrlID)
{
	CATDlgEditor* pEditor = NULL;
	switch (iCtrlID)
	{
	case ID_GTOPartCodeEditor:
		pEditor = _Editor_GTOCode;
		break;
	case ID_GTOPartNameEdiror:
		pEditor = _Editor_GTOName;
		break;
	case ID_GTOTargetEditor:
		pEditor = _Editor_GTOTarget;
		break;
	default:
		break;
	}
	return pEditor;
}

CATDlgPushButton* CMSystemGTOOperationDuplicateDlg::GetPushBtn(int iCtrlID)
{
	CATDlgPushButton* pButton = NULL;
	switch (iCtrlID)
	{
	case ID_GTOSearchButton:
		pButton = _PushButton_Search;
		break;
	case ID_GTOAddButton:
		pButton = _PushButton_Add;
		break;
	case ID_GTODeleteButton:
		pButton = _PushButton_Delete;
		break;
	case ID_GTODeleteAll:
		pButton = _PushButton_DeleteAll;
		break;
	default:
		break;
	}
	return pButton;
}

CATDlgSelectorList* CMSystemGTOOperationDuplicateDlg::GetSelector(int iCtrlID)
{
	CATDlgSelectorList* pSelectorList = NULL;
	switch (iCtrlID)
	{
	case ID_GTOOperationsSelectorList:
		pSelectorList = _SelectorList_GTOOperations;
		break;
	case ID_GTOOperatoinsDupSelectorList:
		pSelectorList = _SelectorList_GTOOperatoinsDup;
		break;
	default:
		break;
	}
	return pSelectorList;
}

// End of User Code


// End of implementation of class methods

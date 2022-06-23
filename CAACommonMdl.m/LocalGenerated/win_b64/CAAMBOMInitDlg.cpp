

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CAAMBOMInitDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgFrame.h"
#include "CATDlgLabel.h"
#include "CATDlgEditor.h"
#include "CATDlgFrame.h"
#include "CATDlgMultiList.h"

// Begin of User Code
#include "CATMsgCatalog.h"
// End of User Code

CAAMBOMInitDlg::CAAMBOMInitDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
| CATDlgGridLayout
)
{

_Frame1 = NULL;
_Label1 = NULL;
_Editor1 = NULL;
_Frame2 = NULL;
_MultiList1 = NULL;

// Begin of User Code

// End of User Code

}

CAAMBOMInitDlg::~CAAMBOMInitDlg()
{

// Begin of User Code

// End of User Code
_Frame1 = NULL;
_Label1 = NULL;
_Editor1 = NULL;
_Frame2 = NULL;
_MultiList1 = NULL;

}



void CAAMBOMInitDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Frame1=new CATDlgFrame(this,(const char*)"Frame1",0|CATDlgFraNoTitle|CATDlgFraNoFrame|CATDlgGridLayout);
_Label1=new CATDlgLabel(_Frame1,(const char*)"Label1",0);
_Editor1=new CATDlgEditor(_Frame1,(const char*)"Editor1",0|CATDlgEdtReadOnly);
_Frame2=new CATDlgFrame(this,(const char*)"Frame2",0|CATDlgGridLayout);
_MultiList1=new CATDlgMultiList(_Frame2,(const char*)"MultiList1",0);
this->SetGridRowResizable(1,1);
this->SetGridColumnResizable(0,1);
this->SetRectDimensions(0,0,400,700);
_Frame1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame1->SetGridColumnResizable(1,1);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Editor1->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_Frame2->SetGridConstraints(1,0,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame2->SetGridRowResizable(0,1);
_Frame2->SetGridColumnResizable(0,1);
_MultiList1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);

// Begin of User Code
this->SetRectDimensions(400, 200, 400, 700);
CATUnicodeString ListTitleArray[6];
ListTitleArray[0] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg","MultiList.Title1");
ListTitleArray[1] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg", "MultiList.Title2");
ListTitleArray[2] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg", "MultiList.Title3");
ListTitleArray[3] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg", "MultiList.Title4");
ListTitleArray[4] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg", "MultiList.Title5");
ListTitleArray[5] = CATMsgCatalog::BuildMessage("CAAMBOMInitDlg", "MultiList.Title6");
_MultiList1->SetColumnTitles(6, ListTitleArray);
_MultiList1->SetColumnTextWidth(0,15);
_MultiList1->SetColumnTextWidth(1, 5);
_MultiList1->SetColumnTextWidth(2, 10);
_MultiList1->SetColumnTextWidth(3, 15);
_MultiList1->SetColumnTextWidth(4, 5);
_MultiList1->SetColumnTextWidth(5, 5);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
void CAAMBOMInitDlg::SetUserName(CATUnicodeString iUserName)
{
	_Editor1->SetText(iUserName);
}
void CAAMBOMInitDlg::InitMultiList(std::vector<FOTask> foVect)
{
	_MultiList1->ClearLine();
	int size = foVect.size();
	for (int i = 0; i < size; ++i)
	{
		_MultiList1->SetColumnItem(0, foVect[i].MPRFormNum, i, CATDlgDataAdd);
		_MultiList1->SetColumnItem(1, foVect[i].MPRRevision, i, CATDlgDataAdd);
		_MultiList1->SetColumnItem(2, foVect[i].MPRTime, i, CATDlgDataAdd);
		_MultiList1->SetColumnItem(3, foVect[i].FOName, i, CATDlgDataAdd);
		_MultiList1->SetColumnItem(4, foVect[i].FODisRevision, i, CATDlgDataAdd);
		_MultiList1->SetColumnItem(5, foVect[i].FOState, i, CATDlgDataAdd);
	}
}
int CAAMBOMInitDlg::GetSelectRow()
{
	int count = _MultiList1->GetSelectCount();
	if (count == 0)
	{
		return -1;
	}
	int* TabRow = new int[count];
	_MultiList1->GetSelect(TabRow, count);
	int row = TabRow[0];
	delete[] TabRow;
	return row;
}
// End of User Code


// End of implementation of class methods
